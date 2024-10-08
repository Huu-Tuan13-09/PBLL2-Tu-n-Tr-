#include <iostream>
#include "person.h"
using namespace std;

class Customer : public Person{
private:
    string customerId;
    string adress;
    string loyaltyLevel;
    string sex;
    int age;
public: 
    Customer(){}
    Customer(string name, string phone, string role, string adress, string loyalLevel, string sex, int age) : customerId("C"+to_string(personId)), adress(adress), sex(sex), age(age), Person(name, phone, role) {}

    void setLoyaltyLevel(string level){loyaltyLevel=level;}
    void setAdress(string ad){adress=ad;}
    void setAge(int age){this->age=age;}

    string getLoyaltyLevel(){return loyaltyLevel;}
    string getCustomerId(){return customerId;}
    string getAdress(){return adress;}
    int getAge(){return age;}
    string getSex(){return sex;}
    

};