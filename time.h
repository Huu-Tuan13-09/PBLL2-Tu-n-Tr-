#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

class Time{
private:
    vector<string> vTime; // thứ, tháng, ngày, giờ phút giây, năm
public:
    Time(){
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

    string getDay(){return vTime[2]+" "+vTime[1]+" "+vTime[4];}

    string getTimeOfDay(){return vTime[3];}
    
};