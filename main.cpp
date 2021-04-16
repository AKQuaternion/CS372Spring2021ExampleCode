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
#include "StoreByPointer.hpp"
#include "StoreByReference.hpp"
#include <functional>
#include <map>
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

using std::make_shared;
using std::shared_ptr;

#include "Command.hpp"
#include "HomeAutomationComponent.hpp"
//
//[[noreturn]] void demonstrateCommand() {
//   //   SayHiCommand x;
//   //   x.execute();
//   //
//   //   auto f = make_shared<FanObject>();
//   //   f->on();
//   //   f->off();
//   auto l = make_shared<LightObject>();
//   //   l->on();
//   //   l->off();
//   //   auto s = make_shared<StereoObject>();
//   //   s->on();
//   //   s->off();
//   //
//   //   HACOnCommand fanOnCommand(f);
//   //   fanOnCommand.execute();
//
//   vector<shared_ptr<Command>> v(10, make_shared<NullCommand>());
//   v[0] = make_shared<SayHiCommand>();
//   v[1] = make_shared<HACOnCommand>(l);
//   v[2] = make_shared<HACOffCommand>(l);
//   v[3] = make_shared<VoidFunctionCommand>(demonstrateDecorator);
//   v[4] = make_shared<VoidFunctionCommand>([]() { cout << "It's Friday!\n"; });
//   v[9] = make_shared<ExitCommand>();
//   v[5] = make_shared<MacroCommand>(
//         vector<shared_ptr<Command>>({v[0], v[1], v[2], v[3], v[4]}));
//   auto doorHAC = make_shared<DoorAdapter>(make_shared<HouseDoor>());
//   v[6] = make_shared<HACOnCommand>(doorHAC);
//   while (true) {
//      cout << "What button? ";
//      unsigned int button;
//      std::cin >> button;
//      v[button]->execute();
//   }
//
//   //   ExitCommand ex;
//   //   ex.execute();
//}
using std::cin;

void foo() {
   cout << "You called foo!";
}

[[noreturn]] void menuSystem() {
   vector<shared_ptr<Command>> menu(10, make_shared<NullCommand>());

   shared_ptr<HomeAutomationComponent> light = make_shared<LightObject>();
   shared_ptr<HomeAutomationComponent> fan = make_shared<FanObject>();
   shared_ptr<HomeAutomationComponent> stereo = make_shared<StereoObject>();

   //   stereo->off();
   //   stereo->off();
   //   fan->on();
   //   light->on();
   menu[0] = make_shared<HACOnCommand>(light);
   menu[1] = make_shared<HACOffCommand>(light);
   menu[2] = make_shared<HACOnCommand>(fan);
   menu[3] = make_shared<HACOffCommand>(fan);
   menu[4] = make_shared<HACOnCommand>(stereo);
   menu[5] = make_shared<HACOffCommand>(stereo);
   menu[6] = make_shared<VoidFunctionCommand>([]() {
      for (int i = 0; i < 10; ++i)
         cout << i << " ";
      cout << endl;
   });
   menu[7] = make_shared<VoidFunctionCommand>(foo);
   shared_ptr<Command> exit = make_shared<ExitCommand>();
   shared_ptr<Door> hd = make_shared<HouseDoor>();
   hd->open();

   menu[8] = make_shared<HACOnCommand>(make_shared<DoorAdapter>(hd));

   menu[9] = make_shared<MacroCommand>(vector<shared_ptr<Command>>{menu[1], menu[3], menu[5], exit});
   while (true) {
      cout << "What command? ";
      int com;
      cin >> com;
      menu[com]->execute();
   }
}

using std::make_shared;

struct TreeNodeBase {
   virtual ~TreeNodeBase() = default;
   [[nodiscard]] virtual int size() const = 0;
   [[nodiscard]] virtual shared_ptr<TreeNodeBase> getLeft() const = 0;
   [[nodiscard]] virtual shared_ptr<TreeNodeBase> getRight() const = 0;
   [[nodiscard]] virtual int getData() const = 0;
};

struct NullTreeNode : public TreeNodeBase {
   [[nodiscard]] int size() const override {
      return 0;
   }
   [[nodiscard]] shared_ptr<TreeNodeBase> getLeft() const override {
      return nullptr;
   }
   [[nodiscard]] shared_ptr<TreeNodeBase> getRight() const override {
      return nullptr;
   }
   [[nodiscard]] virtual int getData() const override {
      return 0;
   }
};

struct DataTreeNode : public TreeNodeBase {
   DataTreeNode(int data, shared_ptr<TreeNodeBase> left, shared_ptr<TreeNodeBase> right)
       : _data(data), _left(move(left)), _right(move(right)) {}

   [[nodiscard]] int size() const override {
      return _left->size() + _right->size() + 1;
   }
   [[nodiscard]] shared_ptr<TreeNodeBase> getLeft() const override {
      return _left;
   }
   [[nodiscard]] shared_ptr<TreeNodeBase> getRight() const override {
      return _right;
   }
   [[nodiscard]] int getData() const override {
      return _data;
   }

   int _data;
   shared_ptr<TreeNodeBase> _left = make_shared<NullTreeNode>();
   shared_ptr<TreeNodeBase> _right = make_shared<NullTreeNode>();
};

int main() {
//   shared_ptr<TreeNodeBase> nullTree = make_shared<NullTreeNode>();
//   shared_ptr<TreeNodeBase> tree = make_shared<DataTreeNode>(1,
//                                                             make_shared<DataTreeNode>(2,
//                                                                                       nullTree,
//                                                                                       make_shared<DataTreeNode>(3,
//                                                                                                                 nullTree,
//                                                                                                                 nullTree)),
//                                                             make_shared<DataTreeNode>(4,
//                                                                                       make_shared<DataTreeNode>(5,
//                                                                                                                 nullTree,
//                                                                                                                 nullTree),
//                                                                                       nullTree));
//
//   cout << tree->size() << endl;
      menuSystem();
   //   demonstrateDecorator();
}
