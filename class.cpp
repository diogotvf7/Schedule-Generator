#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include "Class.h"

using namespace std;

// --------------Constructor functions--------------
Class::Class(const string& lecture_lecturer_beginning_end) {

    istringstream iss(lecture_lecturer_beginning_end);
    string beginning, end;
    iss >> lecture_ >> lecturer_ >> weekday_ >> beginning >> end;
    beginning_.set_time(beginning);
    end_.set_time(end);
}
// -------------------------------------------------

// ------------------Get functions------------------    
string Class::get_lecture() const {return lecture_;}
string Class::get_lecturer() const {return lecturer_;}
string Class::get_weekday() const {return weekday_;}
Time Class::get_beginning() const {return beginning_;}
Time Class::get_end() const {return end_;}
// -------------------------------------------------

// -----------------Print function------------------
void Class::print() const {cout << setfill(' ') << setw(9) << left << lecture_ << '\t' << setw(12) << lecturer_ << '\t' << setw(5) << weekday_ << '\t' << setw(7) << beginning_ << '\t' << setw(7) << end_;}

// -------------------------------------------------
                    
// -----------------Class functions-----------------
bool Class::overlaps(const Class& cl) const {

    return ((weekday_ == cl.get_weekday()) && (beginning_.isBefore(cl.get_end()) && cl.get_beginning().isBefore(end_)));
}
// -------------------------------------------------

// ---------------Operators function----------------
ostream& operator << (ostream& os, const Class& cl) {

    os << setfill(' ') << setw(9) << left << cl.lecture_ << '\t' << setw(12) << cl.lecturer_ << '\t' << setw(5) << cl.weekday_ << '\t' << setw(7) << cl.beginning_ << '\t' << setw(7) << cl.end_;
    return os;
}
bool Class::operator < (const Class& cmp_class) {

    map<string, int> weekdays = {{"MON", 1}, {"TUE", 2}, {"WED", 3}, {"THU", 4}, {"FRI", 5}};

    return (weekdays[weekday_] < weekdays[cmp_class.get_weekday()]) || ((weekdays[weekday_] == weekdays[cmp_class.get_weekday()]) && (beginning_.isBefore(cmp_class.get_beginning())));
}
// -------------------------------------------------