#include <bits/stdc++.h>
using namespace std;
class User;

class User{
protected:
    static int userId;
    string name;
    string phone;
    string role;
public:
    User(){};
    User(string name, string phone, string pasword, string role)
    : name(name), phone(phone), role(role) {++userId;}
    string getName() {return name; }
    string getPhone() {return phone; }
    string getRole() {return role; }
};
int User::userId=1000;
