//
//  Subject.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/13/18.
//

#include "Subject.hpp"
#include <algorithm>

void Subject::attach(std::shared_ptr<Observer> o){
    _observers.insert(std::move(o));
}

void Subject::detach(const std::shared_ptr<Observer>& o){
    _observers.erase(o);
}

void Subject::notify() const{
    for (const auto &o:_observers)
        o->update(_n);
}

void Subject::setN(int n)
{
    _n = n;
    notify();
}

