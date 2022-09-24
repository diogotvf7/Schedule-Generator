#ifndef SCHEDULES_LIST
#define SCHEDULES_LIST

#include <iostream>
#include <map>
#include "Class.h"
#include "Schedule.h"

using namespace std;

class Schedules_list {

    public:
        // --------------Constructor functions--------------
        Schedules_list(vector<string> input, string output = "");
        // ------------------Get functions------------------
        vector<Schedule> get_schedules_list() const;
        // ------------------Set functions------------------
        // -----------------Print function------------------
        void print() const;
        // ------------Schedules list functions-------------
        void sort_schedules_list();
        void generate_schedules();
        // ---------------Operators function----------------
        friend ostream& operator << (ostream& os, const Schedules_list& sl);
    private:
        vector<Schedule> schedules_list_;
        map<string, vector<Class>> tp_classes_;
        vector<Class> t_classes_;
        vector<string> input_;
        string output_;
};

#endif