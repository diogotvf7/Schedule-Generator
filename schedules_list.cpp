#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Schedules_list.h"

using namespace std;

// --------------Constructor functions--------------
Schedules_list::Schedules_list(vector<string> input, string output) : input_(input), output_(output) {
    
    // Lê de todas as aulas a partir dos ficheiros
    for (const string& path : input) {

        string map_key = path.substr(path.find_last_of('/') + 1, path.find_last_of('.') - path.find_last_of('/') - 1);

        ifstream input_file(path);
        string line;
        while (getline(input_file, line)) {
            
            if (line.substr(0, 2) == "T_") t_classes_.push_back(Class(line));
            else tp_classes_[map_key].push_back(Class(line));
        }
    }

    generate_schedules();
}
// -------------------------------------------------

// ------------------Get functions------------------
vector<Schedule> Schedules_list::get_schedules_list() const {return schedules_list_;}
// -------------------------------------------------

// -----------------Print function------------------
void Schedules_list::print() const {

    ofstream output_file(output_);

    for (size_t i = 0; i < schedules_list_.size(); i++) {

        if (output_ != "") output_file << "\n_________________" << i + 1 << " - rating: " << schedules_list_[i].get_rating() << "_________________\n" << schedules_list_[i];
        else  cout << "\n_________________" << i << " - rating: " << schedules_list_[i].get_rating() << "_________________\n" << schedules_list_[i];
    }
}
// -------------------------------------------------

// ------------Schedules list functions-------------
void Schedules_list::sort_schedules_list() {sort(schedules_list_.begin(), schedules_list_.end());}
void Schedules_list::generate_schedules() {

    ofstream ofs("files/Generated/check.txt");

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            for (int k = 0; k <= 7; k++) {
                for (int l = 0; l <= 7; l++) {
                    for (int m = 0; m <= 7; m++) {
                        
                        Schedule s;
                        
                        if (!s.add_class(t_classes_)) continue;
                        if (!s.add_class(tp_classes_.at("BD")[i])) continue;
                        if (!s.add_class(tp_classes_.at("SO")[j])) continue;  
                        if (!s.add_class(tp_classes_.at("F")[k])) continue; 
                        if (!s.add_class(tp_classes_.at("LDTS")[l])) continue;
                        if (!s.add_class(tp_classes_.at("AED")[m])) continue;
                        
                        s.sort_schedule();


                        schedules_list_.push_back(s);
                        
                        ofs << schedules_list_.size() << "   BD0" << i + 1 << " SO0" << j + 1 << " F0" << k + 1 << " LDTS0" << l + 1 << " AED0" << m + 1 << '\n';
                    }
                }
            }
        }
    }
    
    sort_schedules_list();         // UNCOMMENT HERE
}
// -------------------------------------------------

// ---------------Operators function----------------
ostream& operator << (ostream& os, const Schedules_list& sl) {

    for (size_t i = 0; i < sl.schedules_list_.size(); i++) {
    
        os << "\n_________________" << i + 1 << " - rating: " << sl.schedules_list_[i].get_rating() << "_________________\n" << sl.schedules_list_[i];
    }
    return os;
}
// -------------------------------------------------