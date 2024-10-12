#include "customer.h"
#include "appointment.h"
#include "barber.h"
#include "time.h"

using namespace std;

class Manager : public Person{
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
            cout<<x.personId<<"         "<<x.getName()<<"";
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
    
    void cancelCustomer(Customer& cus){
        for(int i = customers.size() - 1; i >= 0; i--){
            if(customers[i].getCustomerId() == cus.getCustomerId()){
                customers.erase(customers.begin() + i);
                break;
            }
        }
    }
    void cancelBarber(Barber& bar){
        for(int i = barbers.size() - 1; i >= 0; i--){
            if(barbers[i].getBarberId() == bar.getBarberId()){
                barbers.erase(barbers.begin() + i);
                break;
            }
        }
    }
    void cancelService(Service& ser){
        for(int i = services.size() - 1; i >= 0; i--){
            if(services[i].getService() == ser.getService()){
                services.erase(services.begin() + i);
                break;
            }
        }
    }
    void cancelAppointment(Appointment& appt){
        for(int i = appointments.size() - 1; i >= 0; i--){
            if(appointments[i].getAptId() == appt.getAptId()){
                appointments.erase(appointments.begin() + i);
                break;
            }
        }
    }

};

