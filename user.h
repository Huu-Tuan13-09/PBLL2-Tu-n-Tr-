#include <bits/stdc++.h>
using namespace std;
class User;

class User{
protected:
    static int userId;
    string name;
    string phone;
    string role;
    string password="nguyenv an a";
public:
    User(){};

    User(string name, string phone, string role)
    : name(name), phone(phone), role(role) {++userId;}
    string getName(){return name;}
    string getPassword(){return password;}
};
    
int User::userId=1000;