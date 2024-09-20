#include <iostream>
#include <ctime>
#include <vector>
#include "user.h"
#include "customer.h"
#include "service.h"
#include "appointment.h"
#include "barber.h"
#include "time.h"

using namespace std;

class Manager : public User{
private:
    vector<Customer> customers;
    vector<Barber> barbers;
    vector<Service> services;
    vector<Appointment> appointments;
    string managerID;

public:
    //Xem danh sach khach hang
    void displayCustomer(){
        for(auto x:customers){
            cout<<x.userId<<"         "<<x.getName()<<"";
        }
    }
    //
    

};

