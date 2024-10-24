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
    //Tao moi dich vu
    void createServices(){
        Service newSer;
        services.push_back(newSer);
    }
    //Xem danh sach khach hang
    void displayCustomer(){
        for(auto x:customers){
            cout<<x.getCustomerId()<<"         "<<x.getName()<<"\n";
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
    void updateLoyaltyLevel(string cusId, int loyaltyLevel){
        int i = findCusId(cusId);
        customers[i].setLoyaltyLevel(loyaltyLevel);
    }

    //xem lich su 

    //Dat lich va chon dich vu
    void booking(){
        
    }
    //Huy hoac thay doi lich hen

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
    // Them Customer
    void addCustomer(){
        char check;
        do{
            Customer newCustomer;
            cout << "Age: "; int age; cin >> age; newCustomer.setAge(age);
            cout << "Sex: "; string sex; cin >> sex; newCustomer.setSex(sex);
            cout << "Adress: "; string adress; cin >> adress; newCustomer.setAdress(adress);
            customers.push_back(newCustomer);
            cout<<"Tiep tuc them ? (Y/N) : ";cin>>check;
        }while(check=='Y'||check=='y');
    }
    
    // Huỷ thành viên từng class theo id
    void cancelCustomer(string Id){
        int i = findCusId(Id);
        if(i != -1) customers.erase(customers.begin() + i);
    }
    void cancelBarber(string Id){
        int i = findBarId(Id);
        barbers.erase(barbers.begin() + i);
    }
    void cancelService(string Id){
        int i = findSerId(Id);
        services.erase(services.begin() + i);
    }
    void cancelAppointment(string Id){
        int i = findAptId(Id);
        appointments.erase(appointments.begin() + i);
    }

    // Tìm kiếm id
    int findCusId(string Id){
        for(int i = customers.size() - 1; i >= 0; i--){
            if(customers[i].getCustomerId() == Id){
                return i;
            }
        }
        return -1;
    }
    int findBarId(string Id){
        for(int i = barbers.size() - 1; i >= 0; i--){
            if(barbers[i].getBarberId() == Id){
                return i;
            }
        }
        return -1;
    }
    int findSerId(string Id){
        for(int i = services.size() - 1; i >= 0; i--){
            if(services[i].getServiceId() == Id){
                return i;
            }
        }
        return -1;
    }
    int findAptId(string Id){
        for(int i = appointments.size() - 1; i >= 0; i--){
            if(appointments[i].getAptId() == Id){
                return i;
            }
        }
        return -1;
    }
};

