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
    string password;

public:
    
    //Xem danh sach khach hang
    void displayCustomer(){
        for(auto x:customers){
            cout<<x.userId<<"         "<<x.getName()<<"";
        }
    }
    //Theo doi lich lam viec
    void showSchedule(){
        for(Barber barber : barbers){
            vector<pair<string,vector<string>>> schedule = barber.getWorking();
            // Trình bày tuỳ chỉnh
        }
    }
    //Dieu chinh lich lam viec cua tat ca cac tho
    void adjustSchedule(){
        showSchedule();

    }
    //Xem bao cao, thong ke dich vu khach hang

    //Cap nhat muc do than thiet cua khach hang

    //xem lich su 

    //Dat lich va chon dich vu
    void booking(){

    }
    //Huy hoac thay doi lich hen
    

};

