#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Time.h"

using namespace std;


// --------------Constructor functions--------------
Time::Time(const string& hhmm) {

    istringstream iss(hhmm);
    char sep;
    iss >> hour_ >> sep >> minute_;
}
// -------------------------------------------------

// ------------------Get functions------------------
unsigned int Time::get_hour() const {return hour_;}
unsigned int Time::get_minutes() const {return minute_;}
// -------------------------------------------------

// ------------------Set functions------------------ 
void Time::set_time(unsigned int hour, unsigned int minute) {hour_ = hour; minute_ = minute;}
void Time::set_time(const string& hhmm) {

    istringstream iss(hhmm); 
    char sc;
    iss >> hour_ >> sc >> minute_; 
}
void Time::set_hour(unsigned int hour) {hour_ = hour;}
void Time::set_minute(unsigned int minute) {minute_ = minute;}
// -------------------------------------------------

// -----------------Print function------------------
void Time::print() const {cout << hour_ << ':' << minute_;}
// -------------------------------------------------

// -----------------Time functions------------------
bool Time::isBefore(const Time& cmp_time) const {

    return ((hour_ < cmp_time.get_hour()) ||
        ((hour_ == cmp_time.get_hour()) && (minute_ < cmp_time.get_minutes())));
}
// -------------------------------------------------

// ---------------Operators function----------------
ostream& operator << (ostream& os, const Time& tm) {

    os << setw(2) << right << setfill('0') << tm.hour_ << ':' << setw(2) << setfill('0') << tm.minute_;
    return os;
}
// -------------------------------------------------