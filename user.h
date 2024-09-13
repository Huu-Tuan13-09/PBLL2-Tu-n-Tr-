#include <bits/stdc++.h>
using namespace std;
class User;

class User{
protected:
    static int userId;
    string name;
    string phone;
    string password;
    string role;
public:
    User(){};
    User(string name, string phone, string pasword, string role)
    : name(name), phone(phone), password(pasword), role(role) {++userId;}
    string getName(){return name;}
};
    
int User::userId=1000;