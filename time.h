#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

class Time{
private:
    vector<string> vTime; // thứ, tháng, ngày, giờ phút giây, năm
    int s;
public:
    void setTime(){
         // current date/time based on current system
        time_t now = time(0); // trả về thời gian hiện tại của hệ thống

        // convert now to string form
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
};