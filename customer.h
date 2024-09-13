#include <bits/stdc++.h>
using namespace std;
#include "user.h"

class Customer : public User{
private:
    string customerId;
    string adress;
    string loyaltyLevel;
    string sex;
    int age;
public: 
    Customer(){}

    Customer(string adress, string loyalLevel, string sex, int age) : customerId("C"+to_string(userId)), adress(adress), sex(sex), age(age){}

    string setLoyaltyLevel(string level){
        loyaltyLevel=level;
    }

    string setAdress(string ad){
        adress=ad;
    }

    string getLoyaltyLevel(){
        return loyaltyLevel;
    }

    string getCustomerId(){
        return customerId;
    }

    string getAdress(){
        return adress;
    }

    void setAge(int age){
        this->age=age;
    }

    string getSex(){
        return sex;
    }

    int getAge(){
        return age;
    }

};