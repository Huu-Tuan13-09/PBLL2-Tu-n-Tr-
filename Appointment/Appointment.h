#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "../Person/Person.h"
#include <ctime>

using namespace std;

map<string, int> Month = {
    {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
    {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
};

class Time {
private:
    vector<string> vTime; // Lưu trữ thứ, tháng, ngày, giờ phút giây, năm
public:
    Time();
    vector<string> getTime() const;
    string getDay() const;
    string getTimeOfDay() const;
};

// Service class
class Service {
private:
    static int serId;
    string serviceId;
    string nameService;
    double price;
    int duration;

public:
    Service();
    Service(const string& nameSer, double price, int dur);
    void display() const;
    string getServiceId() const;
    string getNameService() const;
    double getPrice() const;
    int getDuration() const;
};

// Appointment class
class Appointment {
private:
    static int apId;
    string appointmentId;
    string CustomerId;
    string ServiceId;
    string status;
    Time appointmentTime;
    string time;

public:
    Appointment();
    Appointment(const string& cusId, const string& serId, const string& time);
    string getAptId() const;
    string getCusId() const;
    string getSerId() const;
    string getStatus() const;
    string getTime() const;
    Time getTimeApp() const;
    void setStatus(const string& st);
    void setTime(const string& Time);
};

#endif