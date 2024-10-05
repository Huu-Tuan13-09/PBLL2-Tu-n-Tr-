#include <iostream>
#include <string>
using namespace std;
class Person{
protected:
    static int personId;
    string name;
    string phone;
public:
    Person(){
       ++personId;
       cout<<"Nhap Ten: ";
       getline(cin,name);
       cout<<"Nhap so dien thoai: ";cin>>phone;
    }
    Person(string name, string phone, string role)
    : name(name), phone(phone){++personId;}
    string getName(){return name;}
    string getPhone(){return phone;}
    int getUserId(){return personId;}
};
    
int Person::personId=1000;