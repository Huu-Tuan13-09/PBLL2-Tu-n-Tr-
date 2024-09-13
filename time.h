#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

class Time{
private:
    vector<string> vTime;
public:
    void setTime(){
         // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char* dt = ctime(&now);
        string s="";
        stringstream ss(s);
        string word;
        while(ss>>word){
            vTime.push_back(word);
        }
    }
    vector<string> getTime(){
        return vTime;
    }
};