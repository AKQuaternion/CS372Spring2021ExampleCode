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
#include <memory>
using std::make_unique;
using std::unique_ptr;

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


#include "Observer.hpp"
#include "Subject.hpp"

void demonstrateObserver() {
   Subject s;
   using std::make_shared;

   auto co = make_shared<CoutObserver>();
   auto co2 = make_shared<CoutObserver>();
   auto bo = make_shared<BarGraphObserver>();
   s.attach(co);
   s.attach(co);
   cout << "\u001b[32mClient attached two copies of CoutObserver1.\u001b[0m\n";
   s.attach(co2);
   cout << "\u001b[32mClient attached one copy of CoutObserver2.\u001b[0m\n";
   s.attach(bo);
   cout << "\u001b[32mClient attached one copy of BarGraphObserver.\u001b[0m\n";

   s.attach(make_shared<AlarmObserver>(50));
   cout << "\u001b[32mClient attached one copy of AlarmObserver(50).\u001b[0m\n";

   cout << "\u001b[32mClient setting n to 13:\u001b[0m\n";
   s.setN(13);

   s.detach(co2);
   cout << "\u001b[32mClient detached CoutObserver2.\u001b[0m\n";

   cout << "\u001b[32mClient setting n to 67:\u001b[0m\n";
   s.setN(67);

   s.detach(co);
   cout << "\u001b[32mClient detached CoutObserver1.\u001b[0m\n";

   cout << "\u001b[32mClient setting n to 1:\u001b[0m\n";
   s.setN(1);
}

#include "Armor.hpp"

void demonstrateDecorator() {
   unique_ptr<ArmorComponent> plate = make_unique<PlateArmor>();
   cout << plate->description() << " has AC " << plate->getAC() << endl;
   unique_ptr<ArmorComponent> rustyPlate =
         make_unique<RustyDecorator>(move(plate));
   cout << rustyPlate->description() << " has AC " << rustyPlate->getAC()
        << endl;
   unique_ptr<ArmorComponent> rustyrustyPlate =
         make_unique<RustyDecorator>(move(rustyPlate));
   cout << rustyrustyPlate->description() << " has AC "
        << rustyrustyPlate->getAC() << endl;
   unique_ptr<ArmorComponent> magicLeather =
         make_unique<MagicDecorator>(make_unique<LeatherArmor>());
   cout << magicLeather->description() << " has AC " << magicLeather->getAC()
        << endl;
}

int main() {
   demonstrateDecorator();
}
