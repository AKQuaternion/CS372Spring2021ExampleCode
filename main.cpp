// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
// #include <algorithm>
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
#include "StoreByPointer.hpp"
#include "StoreByReference.hpp"

void demonstrateStoreByReference() {
   cout << "\nDemonstrating store by reference:\n";
   RepairFacility downtown("456 1st Avenue");
   RepairFacility hillside("123 Oak St.");

   RobotR kim("Kim", downtown);
   RobotR joe("Joseph", hillside);

   kim.repair();
   joe.repair();
}

void demonstrateStoreByPointer() {
   cout << "\nDemonstrating store by pointer:\n";
   RepairFacility downtown("456 1st Avenue");
   RepairFacility hillside("123 Oak St.");

   RobotP kim("Kim", &downtown);
   RobotP joe("Joseph", &hillside);

   kim.repair();
   joe.repair();

   kim.changeRepairFacility(&hillside);
   kim.repair();
}

int main() {
   demonstrateStoreByReference();
   demonstrateStoreByPointer();
}
