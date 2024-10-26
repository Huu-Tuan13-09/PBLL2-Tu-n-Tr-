#include "customer.h"
#include "appointment.h"
#include "barber.h"
#include "time.h"

class Manager{
private:
    vector<Customer> customers;
    vector<Barber> barbers;
    vector<Service> services;
    vector<Appointment> appointments;
    string password = "haha123";

public:
    // Kiem tra password
    bool checkPassword(string pass){
        return pass == password;
    }

    //Tao moi dich vu
    void createServices(){
        Service newSer;
        services.push_back(newSer);
    }
    //Xem danh sach khach hang
    void displayCustomers(){
        for(auto x:customers){
            cout<<x.getCustomerId()<<"         "<<x.getName()<<"\n";
        }
    }

    //Theo doi lich lam viec
    void showSchedule(){
        for(int i=2;i<=8;i++){
            if(i==8)cout<<"Chu nhat ";
            else cout<<"Thu "<<i<<" ";
            for(auto it:sche.day[i]){
                cout<<sche.day[i].first<<"["<<sche.day[i].second.first<<"](";
                if(!sche.day[i].second.second)cout<<"Trong)  ";
                else cout<<"Da dat)  ";
            }
            cout<<endl;
        }
    }
    //Dieu chinh lich lam viec cua tat ca cac tho
    void adjustSchedule(){
        showSchedule();

    }
    //Xem bao cao, thong ke dich vu khach hang

    //Xem dich vu
    void displayServices(){
        for(Service ser : services){
            cout << ser.getServiceId() << "         " << ser.getNameService() << "         " 
            << ser.getDuration() << "         " << ser.getPrice() << endl;
        }
    }

    //Cap nhat muc do than thiet cua khach hang
    void updateLoyaltyLevel(string cusId, int loyaltyLevel){
        int i = findCusId(cusId);
        customers[i].setLoyaltyLevel(loyaltyLevel);
    }

    //xem lich su 

    //Dat lich va chon dich vu
    void booking(){
        bool check=false;
        cout<<"Nhap so dien thoai khach hang: ";
        string number;cin>>number;
        Customer tmp;
        for(auto it : customers){
            if(number==it.getPhone()){
                it.setLoyaltyLevel(it.getLoyaltyLevel()+1);
                check=true;
                tmp=it;
                break;
            }
        }
        if(!check){
            cout<<"Chua co khach hang nay! ";
            Customer newCus(number);
            customers.push_back(newCus);
            tmp=newCus;
        }
        displayServices();
        cout<<"Nhap ten dich vu: ";
        string nameSer;
        getline(cin,nameSer);
        showSchedule();
        cout<<"Nhap thu: ";
        string Day;
        getline(cin,Day);
        int number;
        if(s=="chu nhat")number=8;
        else number=stoi(Day);
        cout<<"Thoi gian: ";
        string TIME;
        getline(cin,TIME);
        sche.day[number].second.second=true;
        Appointment newApp(tmp.getCustomerId,);
        
    }

    //Thay doi lich hen

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
    // Them Service
    void addService(){
        char check;
        do{
            cout << "Name: "; string name; getline(cin,name);
            cout << "Price: "; double price; cin >> price;
            cout << "Duration: "; int duration; cin >> duration;
            Service newSer(name,price,duration);
            services.push_back(newSer);
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
    Customer returnCus(int i){
        if(i != -1) return customers[i];
    }
    Barber returnBar(int i){
        if(i != -1) return barbers[i];
    }
    Service returnSer(int i){
        if(i != -1) return services[i];
    }
    Appointment returnApt(int i){
        if(i != -1) return appointments[i];
    }
};

