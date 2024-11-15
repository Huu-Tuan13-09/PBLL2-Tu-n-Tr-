#include "Appointment.h"
// Implementation of Time class
Time::Time() {
    time_t now = time(0); // Lấy thời gian hiện tại của hệ thống
    string dt = ctime(&now); // Trả về chuỗi thời gian
    stringstream ss(dt);
    string word;
    while (ss >> word) {
        vTime.push_back(word);
    }
}

vector<string> Time::getTime() const {
    return vTime;
}

string Time::getDay() const {
    string monthStr = (Month.at(vTime[1]) < 10) ? "0" + to_string(Month.at(vTime[1])) : to_string(Month.at(vTime[1]));
    string dayStr = (stoi(vTime[2]) < 10) ? "0" + to_string(stoi(vTime[2])) : vTime[2];
    return dayStr + "-" + monthStr + "-" + vTime[4];
}

string Time::getTimeOfDay() const {
    return vTime[3];
}

// Implementation of Service class
int Service::serId = 1000;

Service::Service() {
    serviceId = "S" + to_string(++serId);
}

Service::Service(const string& nameSer, double price, int dur)
    : nameService(nameSer), price(price), duration(dur), serviceId("S" + to_string(++serId)) {}

void Service::display() const {
    cout << serviceId << ", " << nameService << ", " << price << ", " << duration;
}

string Service::getServiceId() const {
    return serviceId;
}

string Service::getNameService() const {
    return nameService;
}

double Service::getPrice() const {
    return price;
}

int Service::getDuration() const {
    return duration;
}

// Implementation of Appointment class
int Appointment::apId = 1000;

Appointment::Appointment() {}

Appointment::Appointment(const string& cusId, const string& serId, const string& time)
    : appointmentId("A" + to_string(++apId)), CustomerId(cusId), ServiceId(serId), status("PENDING"), time(time) {}

string Appointment::getAptId() const {
    return appointmentId;
}

string Appointment::getCusId() const {
    return CustomerId;
}

string Appointment::getSerId() const {
    return ServiceId;
}

string Appointment::getStatus() const {
    return status;
}

string Appointment::getTime() const {
    return time;
}

Time Appointment::getTimeApp() const {
    return appointmentTime;
}

void Appointment::setStatus(const string& st) {
    status = st;
}

void Appointment::setTime(const string& Time) {
    time = Time;
}