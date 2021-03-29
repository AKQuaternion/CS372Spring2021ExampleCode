//
// Created by Chris Hartman on 3/29/21.
//

#ifndef CS372SPRING2021EXAMPLECODE_STOREBYREFERENCE_HPP
#define CS372SPRING2021EXAMPLECODE_STOREBYREFERENCE_HPP
// For ease of reading, we use poor style and define our class functions
// inline.

/*
 * Let's write a robot class for our town, which has two
 * robot repair facilities. Each robot will have a home repair
 * facility, which will be set at the time the robot is created.
 * The robot will need to store a handle to its repair facility.
 *
 * In this example, we will use a reference to store the handle,
 * because lifetime is not an issue (the repair facilities exist
 * beyond the lifetime of the robots), and we never change the
 * repair facility for a robot.
 *
 * Note that in this example, the objects we are storing handles to
 * are not polymorphic. However, the Robot class would still work
 * properly if you pass it an object of a class derived from RepairFacility.
 */

class RepairFacility {
public:
   explicit RepairFacility(const std::string &location) : _location(location) {}
   [[nodiscard]] std::string getLocation() const { return _location; }

private:
   std::string _location{};
};

class RobotR {  // Robot storing repair facility by reference
public:
   RobotR(const std::string &name, const RepairFacility &repairFacility)
         : _name(name), _repairFacility(repairFacility) {}

   void repair() const {
      cout << "This is " << _name << " going to get repaired at "
           << _repairFacility.getLocation() << ".\n";
   }

private:
   std::string _name{};
   const RepairFacility &_repairFacility;
};

#endif//CS372SPRING2021EXAMPLECODE_STOREBYREFERENCE_HPP
