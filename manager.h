#include "customer.h"
#include "appointment.h"
#include "barber.h"
#include "time.h"

using namespace std;

class Manager{
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
            cout<<x.getCustomerId() <<"         "<<x.getName()<<"";
        }
    }
    int findBaber(){

    }

    //Them Barber
    void addBaber(){
        char check;
        do{
            Barber newBarber;
            newBarber.setRole();
            barbers.push_back(newBarber);
            cout<<"Tiep tuc them ? (Y/N) : ";cin>>check;
        }while(check=='Y'||check=='y');
    }
    //Xoa baber
    void deleteBaber(string id){

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

