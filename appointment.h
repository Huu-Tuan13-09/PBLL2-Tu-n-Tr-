#include <bits/stdc++.h>
using namespace std;
#include "barber.h"
#include "customer.h"
#include "time.h"
#include "service.h"


class Appointment{
private:
    static int apId;
    string appointmentId;
    string CustomerId;
    string BarberId;
    string ServiceId;
    string status;
    Time time;
public:
    Appointment(string cusId, string barId, string serId, string st, Time t) : CustomerId(cusId), BarberId(barId), ServiceId(serId), status(st), time(t) {++apId;}

    
};
