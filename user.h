#include <iostream>
#include <string>
using namespace std;
class User;

class User{
protected:
    static int userId;
    string name;
    string phone;
    string role;
public:
    User(){++userId;}
    User(string name, string phone, string role)
    : name(name), phone(phone), role(role) {++userId;}
    string getName(){return name;}
    string getPhone(){return phone;}
    string getRole(){return role;}
    int getUserId(){return userId;}
};
    
int User::userId=1000;