#include <iostream>
#include <string>
using namespace std;
class Person{
protected:
    static int personId;
    string name;
    string phone;
    string role;
public:
    Person(){++personId;}
    Person(string name, string phone, string role)
    : name(name), phone(phone), role(role) {++personId;}
    string getName(){return name;}
    string getPhone(){return phone;}
    string getRole(){return role;}
    int getUserId(){return personId;}
};
    
int Person::personId=1000;