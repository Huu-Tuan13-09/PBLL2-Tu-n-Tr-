#include<bits/stdc++.h>
using namespace std;

class Time{
protected:
    int day, month, year;
    string time; // h : m 
public:
    Time(){}
    Time(int d, int m, int y, string t) : day(d), month(m), year(y), time(t) {}

    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    string getTime(){
        return time;
    }

    void display(){
        cout << year << "/" << month << "/" << day << " " << time;
    }
    bool operator == (Time& a){
        return (time == a.time && day == a.day && month == a.month && year == a.year);
    }
};