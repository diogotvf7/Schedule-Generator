#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Time.h"
#include "Class.h"
#include "Schedule.h"
#include "Schedules_list.h"

using namespace std;

vector<int> listPrimes(int n) {

    vector<int> ans;

    for (int i = 2; i <= n; i++) {ans.push_back(i);}
    for (const int & i : ans) {
        for (const int & j : ans) {
            if (j % i == 0) {ans.erase(ans.begin() + j);}
        }
    }

    return ans;
}

int main () {

    Schedules_list sl_1({"files/Classes/Shift1/AED.txt", "files/Classes/Shift1/BD.txt", "files/Classes/Shift1/F.txt", "files/Classes/Shift1/LDTS.txt", "files/Classes/Shift1/SO.txt"}, "files/Generated/Shift1.txt");
    Schedules_list sl_2({"files/Classes/Shift2/AED.txt", "files/Classes/Shift2/BD.txt", "files/Classes/Shift2/F.txt", "files/Classes/Shift2/LDTS.txt", "files/Classes/Shift2/SO.txt"}, "files/Generated/Shift2.txt");

    sl_1.generate_schedules(); sl_1.print(); 
    sl_2.generate_schedules(); sl_2.print();

    return 0;
}

