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
    string nameBarber;
    string ServiceId;
    string status;
    Time appointmentTime;
    string time;
public:
    Appointment() {
        ++apId;
        appointmentId = "A" + to_string(apId);

    }
    Appointment(string cusId, string nameBarber, string serId,string time) 
    : appointmentId("A" + to_string(apId)), CustomerId(cusId), nameBarber(barId), ServiceId(serId), status("Pending"),time(time) {
        ++apId;

    }

    string getAptId(){return appointmentId;}
    string getCusId(){return CustomerId;}
    string getNameBarber(){return nameBarber;}
    string getSerId(){return ServiceId;}
    string getStatus(){return status;}

    void setStatus(string st){status = st;}


};
int Appointment::apId = 1000;