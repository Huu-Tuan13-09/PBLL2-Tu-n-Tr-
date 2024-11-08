#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Person {
protected:
    static int personId;
    string name;
    string phone;
public:
    Person();
    Person(const string& phone);
    string getName() const;
    string getPhone() const;
    void setName(const string& name);
};

struct Schedule {
    vector<map<string, string>> day;
    map<string, int> scheduled;
    void showScheduled();
    Schedule();
};

Schedule sche;

class Barber : public Person {
private:
    string barberId;
    int experience;
    vector<string> role;
    map<string, vector<string>> vWorking;
public:
    Barber();
    Barber(const string& name, const string& phone, int ex);
    void setWorking(string s);
    void createRole(const vector<string>& Role);
    void changeWorking();
    void deleteWorking();
    void setRole();
    void cancelRole();
    string getBarberId() const;
    vector<string> getRole() const;
    int getExperience() const;
    map<string, vector<string>> getWorking() const;
};

class Customer : public Person {
private:
    string customerId;
    int loyaltyLevel;
    string sex;
    int age;
public:
    Customer();
    Customer(const string& phone);
    void setLoyaltyLevel(int level = 1);
    int getLoyaltyLevel() const;
    string getCustomerId();
    int getAge() const;
    string getSex() const;
};
#endif  