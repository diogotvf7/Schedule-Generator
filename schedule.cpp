#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Schedule.h"

using namespace std;

// --------------Constructor functions--------------
Schedule::Schedule() {schedule_ = {};}
// -------------------------------------------------

// -------------------Static data-------------------
map<string, int> Schedule::ratings_list = {{"PMPR", 8}, {"APR", 6}, {"RR", 8}, {"FMMR", 9}, 
{"GTD", 4}, {"MCPF", 5}, {"RMA", 1}, {"BMCL", 8}, {"JMCC", 1}, {"NHF", 5}, {"AOR", 10}, 
{"LMBL", 7}};
// -------------------------------------------------

// ------------------Get functions------------------
vector<Class> Schedule::get_schedule() const {return schedule_;}
float Schedule::get_rating() const {

    int i = 0; float rating = 0;
    for (const Class& cl : schedule_) {

        if (cl.get_lecture()[0] != 'T' && ratings_list[cl.get_lecturer()]) {

            rating += ratings_list[cl.get_lecturer()]; 
            i++;
        }
    }

    return rating / i;
}
vector<string> Schedule::get_lecturers() const {

    vector<string> lecturers;

    for (const Class& c : schedule_) lecturers.push_back(c.get_lecturer());

    return lecturers;
};
// -------------------------------------------------

// -----------------Print function------------------
void Schedule::print() const {for (const Class& c : schedule_) cout << c << '\n';}
// -------------------------------------------------

// ----------------Random functions-----------------
bool Schedule::fits_schedule(const Class& cl) {
    
    for (const Class& c : schedule_) if (cl.overlaps(c)) return false;
    return true;
}
bool Schedule::add_class(const Class& cl) {

    if (fits_schedule(cl)) {
        schedule_.push_back(cl);
        return true;
    }
    return false;
}
bool Schedule::add_class(const vector<Class>& cl) {

    for (const Class& c : cl) {

        if (!fits_schedule(c)) return false;
        schedule_.push_back(c);
    }
    return true;
}
void Schedule::sort_schedule() {sort(schedule_.begin(), schedule_.end());}
// -------------------------------------------------

// ---------------Operators function----------------
ostream& operator << (ostream& os, const Schedule& sc) {

    for (const Class& c : sc.schedule_) os << c << "\n";
    return os;
}
bool Schedule::operator < (const Schedule& cmp_schedule) {

    return get_rating() < cmp_schedule.get_rating();
}
// -------------------------------------------------