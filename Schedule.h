#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include <vector>
#include "Class.h"

using namespace std;

class Schedule {

    public:
        // --------------Constructor functions--------------
        Schedule();
        // ------------------Get functions------------------
        vector<Class> get_schedule() const;
        vector<string> get_lecturers() const;
        float get_rating() const;
        // ---------------Schedule functions----------------
        bool fits_schedule(const Class& cl);
        bool add_class(const Class& cl);
        bool add_class(const vector<Class>& cl);
        void sort_schedule();
        // -----------------Print function------------------
        void print() const;
        // ---------------Operators function----------------
        friend ostream& operator << (ostream& os, const Schedule& sc);
        bool operator < (const Schedule& cmp_schedule);
    private:
        vector<Class> schedule_;
        static map<string, int> ratings_list;
};

#endif