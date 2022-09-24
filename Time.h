#ifndef TIME_H
#define TIME_H

#include <string>
#include <ostream>

using namespace std;

class Time {

    public:
        // --------------Constructor functions--------------
        Time(unsigned int hour = 0, unsigned int minute = 0) : hour_(hour), minute_(minute) {}
        Time(const string& hhmm);
        // ------------------Get functions------------------
        unsigned int get_hour() const;
        unsigned int get_minutes() const;
        // ------------------Set functions------------------
        void set_time(unsigned int hour, unsigned int minute);
        void set_time(const string& hhmm);
        void set_hour(unsigned int hour);
        void set_minute(unsigned int minute);
        // -----------------Print function------------------
        void print() const;
        // -----------------Time functions------------------
        bool isBefore(const Time& ctime) const;
        // ---------------Operators function----------------
        friend ostream& operator << (ostream& os, const Time& tm);
        
    private:
        unsigned int hour_;
        unsigned int minute_;
};

#endif