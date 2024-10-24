#include <iostream>
#include "person.h"
using namespace std;

class Customer : public Person{
private:
    string customerId;
    int loyaltyLevel;
    string sex;
    int age;
public: 
    Customer();
    Customer(string number) : phone(number){
        customerId = "C" + to_string(personId);
        setLoyaltyLevel();
        cout<<"Ten khach hang: ";
        getline(cin,name);
        cout<<"Gioi tinh: ";
        cin>>sex;
        cout<<"Tuoi: ";
        cin>>age;
    }
    void setLoyaltyLevel(int level = 1){loyaltyLevel=level;}
    int getLoyaltyLevel(){return loyaltyLevel;}
    string getCustomerId(){return customerId;}
    int getAge(){return age;}
    string getSex(){return sex;}
    
};