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
    Time appointmentTime;
    string time;
public:
    Appointment() {
        ++apId;
        appointmentId = "A" + to_string(apId);

    }
    Appointment(string cusId, string barId, string serId, string st,string time) 
    : appointmentId("A" + to_string(apId)), CustomerId(cusId), BarberId(barId), ServiceId(serId), status(st),time(time) {++apId;}

    string getAptId(){return appointmentId;}
    string getCusId(){return CustomerId;}
    string getBarId(){return BarberId;}
    string getSerId(){return ServiceId;}
    string getStatus(){return status;}

    void setStatus(string st){status = st;}


};
int Appointment::apId = 1000;