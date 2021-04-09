//
// Created by Chris Hartman on 2019-04-19.
//

#ifndef CS372SPRING2021EXAMPLECODE_HOMEAUTOMATIONCOMPONENT_HPP
#define CS372SPRING2021EXAMPLECODE_HOMEAUTOMATIONCOMPONENT_HPP

#include <iostream>
#include "Door.hpp"

class HomeAutomationComponent {
public:
   virtual ~HomeAutomationComponent() = default;
   virtual void on() = 0;
   virtual void off() = 0;
};

/* In this example code we include the declarations of derived command
 * classes in the same file as the base class. In a "real" project they are
 * usually in a different include file, so that clients who deal only with
 * base class handles do not need to recomplile or change in any way when
 * a new command is added.
 * */

class FanObject : public HomeAutomationComponent {
public:
   void on() final;
   void off() final;
};

class LightObject : public HomeAutomationComponent {
public:
   void on() final;
   void off() final;
};

class StereoObject : public HomeAutomationComponent {
public:
   void on() final;
   void off() final;
};

class DoorAdapter : public HomeAutomationComponent {
public:
   DoorAdapter(std::shared_ptr<Door> door) : _door(door) {}
   void on() override { _door->open(); }
   void off() override { _door->close(); }

private:
   std::shared_ptr<Door> _door;
};
#endif  // CS372SPRING2020EXAMPLECODE_HOMEAUTOMATIONCOMPONENT_HPP
