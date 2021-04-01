//
//  Observer.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/13/18.
//

#ifndef Observer_hpp
#define Observer_hpp

class Observer {
public:
    virtual ~Observer();
    virtual void update(int n) const = 0;
};

class CoutObserver : public Observer {
public:
    void update (int n) const override;
};

class BarGraphObserver : public Observer {
public:
    void update (int n) const override;
};

class AlarmObserver : public Observer {
public:
   explicit AlarmObserver(int alarmValue);
   void update (int n) const override;
private:
   int _alarmValue;
};
#endif /* Observer_hpp */
