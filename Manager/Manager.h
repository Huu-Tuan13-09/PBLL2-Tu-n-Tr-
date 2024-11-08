#ifndef MANAGER_H
#define MANAGER_H

#include "../Appointment/Appointment.h"

#include <fstream>
class Manager{
private:
    vector<Customer> customers;
    vector<Barber> barbers;
    vector<Service> services;
    vector<Appointment> appointments;
    string password="1";
public:
    void createServices();
    void createBarber();
    void displayBarbers();
    void displayCustomers();
    void displayServices();  
    void showSchedule();
    void adjustSchedule();
    void Customer_Service_Analytics();
    void updateLoyaltyLevel(string cusId, int loyaltyLevel);
    void viewHistory();
    void booking();
    void changeApp();
    void addBarber();
    void addService();
    void cancelCustomer(string Id);
    void cancelBarber(string Id);
    void cancelService(string Id);
    void cancelAppointment(string Id);
    Customer* findCusId(const string& Id);
    Barber* findBarId(const string& Id);
    Service* findSerId(const string& Id);
    Appointment* findAptId(const string& Id); 
    bool checkPass(string tmp);
};

#endif