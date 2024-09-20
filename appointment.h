#include <iostream>
#include <string> 
#include <ctime>
#include "barber.h"
#include "customer.h"
#include "time.h"
#include "service.h"

using namespace std;

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
    Appointment() {++apId;}
    Appointment(string cusId, string barId, string serId, string st, Time t) 
    : appointmentId("A" + to_string(apId)), CustomerId(cusId), BarberId(barId), ServiceId(serId), status(st), time(t) {++apId;}

    string getAptId(){return appointmentId;}
    string getCusId(){return CustomerId;}
    string getBarId(){return BarberId;}
    string getSerId(){return ServiceId;}
    string getStatus(){return status;}
    Time getTime(){return time;}

    void setStatus(string st){status = st;}

};
