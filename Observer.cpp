//
//  Observer.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/13/18.
//

#include "Observer.hpp"
#include <iostream>
using std::cout;
using std::endl;

Observer::~Observer()=default;

void CoutObserver::update (int n) const
{
    cout << "n is " << n << endl;
}

void BarGraphObserver::update (int n) const
{
    for(int i=0;i<n;++i)
        cout << "*";
    cout << endl;
}

AlarmObserver::AlarmObserver(int alarmValue):_alarmValue(alarmValue){
}

void AlarmObserver::update (int n) const
{
   if(n>_alarmValue)
      cout << "ALARM!!!\n";
}