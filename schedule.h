#include <bits/stdc++.h>
#include "appointment.h"
using namespace std;


class Schedule{
public:
    vector<map<string,pair<string,bool>>> day[8];
    map<string, map<string, vector<Appointment>> schedule;
};