//
// Created by Chris Hartman on 2/10/21.
//
//
// Created by Chris Hartman on 3/23/20.
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
#include <array>
#include <numeric>
#include <tuple>
#include <utility>
#include <functional>

auto magicNumber(string_view word) {
   unsigned long answer = 0;
   for (auto ii = 0u; ii < 20000; ++ii)
      answer += ii % static_cast<unsigned int>(word[ii % word.length()]);
   return answer;
}

void checkAWord(string_view word, mutex &m) {
   if (magicNumber(word) % 1000 == 0) {
//      unique_lock lock(m);
      cout << word << " " << magicNumber(word) << endl;
   }
}

template <typename Iter> void checkSomeWords(Iter first, Iter last, mutex &m) {
   for (Iter i = first; i != last; ++i)
      checkAWord(*i,m);
}

void async_main() {

   mutex m;
   auto startTime = std::chrono::steady_clock::now();

   ifstream ifile("/usr/share/dict/words");
   vector<string> dictionary;
   string word;
   while (ifile >> word)
      dictionary.push_back(word);

   vector<std::future<void>> results;
   const int numThreads = 10;
   for (int i = 0; i < numThreads; ++i) {
      auto numWords = dictionary.size();
      auto start = int(i / double(numThreads) * numWords) + begin(dictionary);
      auto finish = int((i + 1) / double(numThreads) * numWords) +
                    begin(dictionary);

      results.push_back(std::async(std::launch::async,
                                   checkSomeWords<vector<string>::const_iterator>,
                                   start, finish, std::ref(m)));
   }
//
   for (auto &f : results)
      f.get();

//    std::for_each(//std::execution::par,
//    dictionary.begin(),dictionary.end(),checkAWord);
   auto endTime = std::chrono::steady_clock::now();
   auto diff = endTime - startTime;
   cout << std::chrono::duration<double>(diff).count() << "s" << endl;
}

class Foo {
public:
   explicit Foo(int x) : _x(x)
   {}

   [[nodiscard]] std::string operator()() {
      return "This is Foo::operator()";
   }
   [[nodiscard]] auto operator()(int i) {
      return i*_x;
   }
private:
   int _x;
};

int bar(int) {
   return 13;
}

void modernCppExamples() {
   Foo f{5};

   cout << f(3) << endl;

   std::function<int(int)> g = f;
   g = bar;
   g = [](int x) {return x*x;};

   auto isOdd = [](int x) {return x%2==1;};

   if (isOdd(5)) cout << "5 is odd";

   using namespace std::string_literals;


   //  auto [inserted,iterToIt] = rp();
   //  cout << inserted << iterToIt;
   //  int x= foo(13);
   async_main();
}