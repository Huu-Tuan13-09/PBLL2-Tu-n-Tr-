#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

class Time{
private:
    vector<string> vTime; // thứ, tháng, ngày, giờ phút giây, năm
public:
    void setTime(){
        time_t now = time(0); // trả về thời gian hiện tại của hệ thống
        string dt = ctime(&now); // trả về chuỗi thời gian
        stringstream ss(dt);
        string word;
        while(ss>>word){
            vTime.push_back(word);
        }
    }
    vector<string> getTime(){
        return vTime;
    }
    string getMonth(){return vTime[1];}
    string getDay(){return vTime[2];}
    string getTimeOfDay(){return vTime[3];}
    string getYear(){return vTime[4];}
    
};