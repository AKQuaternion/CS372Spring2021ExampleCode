//
// Created by Chris Hartman on 4/10/20.
//

#include "Armor.hpp"

std::string PlateArmor::description() const {
   return "Plate Mail";
}

int PlateArmor::getAC() const {
   return 10;
}

std::string LeatherArmor::description() const {
   return "Leather Armor";
}

int LeatherArmor::getAC() const {
   return 3;
}

ArmorDecorator::ArmorDecorator(std::unique_ptr<ArmorComponent> wrappee)
      : _wrappee(std::move(wrappee)) {}

std::string ArmorDecorator::description() const {
   return _wrappee->description();
} //See Scott Meyers Effective C++ Item 34 for more on
// implementing a pure virtual function

int ArmorDecorator::getAC() const {
   return _wrappee->getAC();
}

std::string RustyDecorator::description() const {
   return "Rusty " + ArmorDecorator::description();
}

int RustyDecorator::getAC() const {
   return ArmorDecorator::getAC() - 3;
}

std::string MagicDecorator::description() const {
   return "Magic " + ArmorDecorator::description();
}

int MagicDecorator::getAC() const {
   return ArmorDecorator::getAC() + 1;
}
