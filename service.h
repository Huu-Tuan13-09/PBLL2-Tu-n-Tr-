#include <iostream>
#include <string>
using namespace std;

class Service{
private:
    static int serId;
    string serviceId;
    string nameService;
    double price;
    int duration; // tính theo phút
public:
    Service() {
        cin>>serId;
        getline(cin,nameService);
        cin>>price;
        cin>>duration;        
        serId++;
        serviceId = "S" + to_string(serId);
    }
    Service(string nameSer,double price, int dur) : nameService(nameSer), price(price), duration(dur), serviceId( "S" + to_string(++serId)){}
    void display(){
        cout << serviceId << ", " << nameService << ", " << price << ", " << duration;
    }
    string getServiceId(){return serviceId;}
    string getNameService(){return nameService;}
    double getPrice(){return price;}
    int getDuration(){return duration;}

};
int Service::serId = 1000;