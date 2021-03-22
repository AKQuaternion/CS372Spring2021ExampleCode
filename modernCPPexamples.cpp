// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
//
// Created by Chris Hartman on 2/10/21.
//

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::string_view;
#include <future>
using std::async;
using std::future;
#include <mutex>
using std::mutex;
using std::unique_lock;
#include <algorithm>
using std::all_of;
using std::for_each;
#include <array>
#include <functional>
#include <numeric>
#include <tuple>
#include <utility>

auto magicNumber(string_view word) {
   unsigned long answer = 0;
   for (auto ii = 0u; ii < 20000; ++ii)
      answer += ii % static_cast<unsigned int>(word[ii % word.length()]);
   return answer;
}

void async_main() {
   auto startTime = std::chrono::steady_clock::now();

   ifstream ifile("/usr/share/dict/words");
   vector<string> dictionary;
   string word;
   while (ifile >> word)
      dictionary.push_back(word);

   vector<std::future<int>> results;
   const int numThreads = 80;
   mutex m;
   for (int i = 0; i < numThreads; ++i) {
      auto numWords = dictionary.size();
      auto start = int(i / double(numThreads) * numWords) + begin(dictionary);
      auto finish = int((i + 1) / double(numThreads) * numWords) +
                    begin(dictionary);

      auto processSome = [start,finish,&m]() {
         int numMagicWords = 0;
         std::for_each(start, finish, [&numMagicWords,&m](const auto &word) {
            if (magicNumber(word) % 1000 == 0) {
               ++numMagicWords;
               unique_lock lock(m);
               if(magicNumber(word) % 3 == 0)
                  return;
               cout << word << " " << magicNumber(word) << endl;
            }
         });
         return numMagicWords;
      };
      results.push_back(std::async(std::launch::async, processSome));
   }

   int sum=0;
   for (auto &f : results)
      sum += f.get();
   cout << sum << " magic words.\n";
   auto endTime = std::chrono::steady_clock::now();
   auto diff = endTime - startTime;
   cout << std::chrono::duration<double>(diff).count() << "s" << endl;
}

void modernCppExamples() {
   //   Foo f{5};
   //
   //   cout << f(3) << endl;
   //
   //   std::function<int(int)> g = f;
   //   g = bar;
   //   g = [](int x) {return x*x;};
   //
   //   auto isOdd = [](int x) {return x%2==1;};
   //
   //   if (isOdd(5)) cout << "5 is odd";
   //
   //   using namespace std::string_literals;


   //  auto [inserted,iterToIt] = rp();
   //  cout << inserted << iterToIt;
   //  int x= foo(13);
   async_main();
}