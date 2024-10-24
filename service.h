#include <iostream>
#include <string>
using namespace std;

class Service{
private:
    static int serId;
    string serviceId;
    string nameService;
    string price;
    int duration; // tính theo phút
public:
    Service(){}
    Service(string ser, string pr, int est) : nameService(ser), price(pr), duration(est) {
        serId++;
        serviceId = "S" + to_string(serId);
    }
    void display(){
        cout << serviceId << ", " << nameService << ", " << price << ", " << duration;
    }
    string getServiceId(){return serviceId;}
    string getNameService(){return nameService;}
    string getPrice(){return price;}
    int getDuration(){return duration;}

    void setNameService(string name){nameService = name;}
    void setPrice(string price){this->price = price;}
    void setDuration(int duration){this->duration = duration;}
};
int Service::serId = 1000;