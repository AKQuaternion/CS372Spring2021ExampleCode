#include <algorithm>
#include <chrono>
#include <concepts>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
#include <string>
#include <tuple>
using std::tuple;
#include <functional>
#include <map>

double add1MRandomDoubles() {
   const vector<double> doublesToAdd = []() {
      std::random_device r;                                          //truly random on many/most platforms (but low entropy, call only once)
      std::default_random_engine e1(r());                            //seed the random engine
      std::uniform_real_distribution<double> uniform_dist(0.0, 10.0);//create a distribution

      vector<double> v;
      const int SIZE = 1'000'000;
      v.reserve(SIZE);
      for (int i = 0; i < SIZE; ++i)
         v.push_back(uniform_dist(e1));
      return v;
   }();
   //   return std::reduce(std::execution::par, doublesToAdd.begin(), doublesToAdd.end())
   return std::accumulate(doublesToAdd.begin(), doublesToAdd.end(), 0.0);
};

struct Foo {
   int x;
   double d = 13.0;
   char c;
   int operator()(double r) { return r * d; }
};

bool operator<(const Foo &lhs, const Foo &rhs) {
   return std::forward_as_tuple(lhs.x, lhs.d, lhs.c) < std::forward_as_tuple(rhs.x, rhs.d, rhs.c);
}

tuple<int, double, char> f{7, 2.4, 'x'};
tuple<int, double, char> g{7, 2.3, 'r'};
auto h = std::make_tuple(14, 13.13, 'm');

int foo(double d) {
   return d * d;
}

void async_main();

void foo(std::string_view s) {
   cout << s;
}

int main() {
//   vector v{2,4,6,8,9,10};
//   std::pair p{2,'c'};
//   std::string s("world");
//   foo(s);
//
//   if(auto c=getchar(); c!='\0') {
//
//   }
   //
   //if (std::all_of(v.begin(),v.end(),[](auto i){return i%2==0;}))
   //   cout << "Everything in v is even.\n";
   //  int i=13;
   //  auto multiplyByI = [=](int x) {return x*i;};
   //  i=2;
   //  cout << multiplyByI(5) << endl;

   //std::function<int (double)> myFunc = foo;
   //myFunc = [](double d) {return int(d*d*d);};
   //   Foo f;
   //myFunc = f;
   //
   //cout << myFunc(13.3) << endl;


   //  vector<int> v(100);
   //  std::iota(v.begin(), v.end(), 1);
   //  auto fac = std::accumulate(
   //      v.begin() + 1, v.end(), std::to_string(v.front()),
   //      [](auto i, auto j) { return i + ", " + std::to_string(j); });
   //  cout << fac << fac << endl;

   //   auto x{4};
   //   auto s = std::string{"hello"};
   //   std::string f{};
   //
   //   auto start = std::chrono::steady_clock::now();
   //   cout << "Sum was " << add1MRandomDoubles() << endl;
   //   auto end = std::chrono::steady_clock::now();
   //   std::chrono::duration<double> elapsed_seconds  = end - start;
   //   std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
   async_main();
}
