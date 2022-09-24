#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include "Time.h"

using namespace std;

class Class {

    public:

        // --------------Constructor functions--------------
        Class(string lecture, unsigned int class_number, string lecturer, string weekday, Time beginning, Time end) :
                lecture_(lecture), lecturer_(lecturer), beginning_(beginning), end_(end) {};
        Class(const string& lecture_lecturer_weekday_beginning_end);
        // ------------------Get functions------------------
        string get_lecture() const;
        string get_lecturer() const;
        string get_weekday() const;
        Time get_beginning() const;
        Time get_end() const;
        // -----------------Print function------------------
        void print() const;
        // ----------------Random functions-----------------
        bool overlaps(const Class& cl) const;
        // ---------------Operator functions----------------
        friend ostream& operator << (ostream& os, const Class& cl);
        bool operator < (const Class& cmp_class);

    private:
        string lecture_;
        string lecturer_;
        string weekday_;
        Time beginning_;
        Time end_;

};

#endif