//
// Created by Chris Hartman on 4/20/20.
//
#ifndef CS372SPRING2021EXAMPLECODE_DOOR_HPP
#define CS372SPRING2021EXAMPLECODE_DOOR_HPP
#include <iostream>

class Door {
public:
   virtual ~Door() = default;
   virtual void open() = 0;
   virtual void close() = 0;

private:
};

class HouseDoor : public Door {
   void open() override { std::cout << "Turning knob to open door\n"; }
   void close() override { std::cout << "Turning knob to close door\n"; }
};

class GarageDoor : public Door {
   void open() override { std::cout << "Pushing button to open door\n"; }
   void close() override { std::cout << "Pushing button to close door\n"; }
};

#endif  // CS372SPRING2020EXAMPLECODE_DOOR_HPP
