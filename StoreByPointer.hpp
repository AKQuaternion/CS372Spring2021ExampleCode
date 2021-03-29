//
// Created by Chris Hartman on 3/29/21.
//

#ifndef CS372SPRING2021EXAMPLECODE_STOREBYPOINTER_HPP
#define CS372SPRING2021EXAMPLECODE_STOREBYPOINTER_HPP
// For ease of reading, we use poor style and define our class functions
// inline.

#include <utility>

#include "StoreByReference.hpp"
/*
 * In StoreByReference.hpp, we made Robots with a RepairFacility.
 *
 * What if we want a robot to be able to change its RepairFacility?
 * We can no longer store the handle by reference, since references
 * can't be reseated.
 *
 * Instead, we can use a raw pointer. But this means some "ugly" syntax,
 * we must pass a pointer to the repair facility, and use -> because
 * it's a pointer.
 *
 * We do not need to redefine the RepairFacility class.
 *
 * Note that in this example, the objects we are storing handles to
 * are not polymorphic. However, the Robot class would still work
 * properly if you pass it a pointer to an object of a class derived
 * from RepairFacility.
 */

class RobotP {// Robot storing repair facility by Pointer
public:
   RobotP(std::string name, RepairFacility const *repairFacility)
       : _name(std::move(name)), _repairFacility(repairFacility)
   {}

   void repair() const {//only change from before is -> instead of .
      cout << "This is " << _name << " going to get repaired at "
           << _repairFacility->getLocation() << ".\n";
   }

   void changeRepairFacility(RepairFacility const *repairFacility) {
      _repairFacility = repairFacility;
   }

private:
   std::string _name{};
   RepairFacility const *_repairFacility;
};

#endif//CS372SPRING2021EXAMPLECODE_STOREBYPOINTER_HPP
