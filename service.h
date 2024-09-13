#include <bits/stdc++.h>
using namespace std;

class Service{
private:
    string ID;
    string nameService;
    string price;
    int duration; // tính theo phút
public:
    Service(){}
    Service(string id, string ser, string pr, int est) : ID(id), nameService(ser), price(pr), duration(est) {}
    void display(){
        cout << ID << ", " << nameService << ", " << price << ", " << duration;
    }
    string getID(){
        return ID;
    }
    string getService(){
        return nameService;
    }
    string getPrice(){
        return price;
    }
    int getDuration(){
        return duration;
    }
};