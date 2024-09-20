#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "user.h"
using namespace std;

class Barber : public User{
private:
    string barberId;
    int experience;
    vector<string> role;   
public:
    Barber(){};

    Barber(int ex) : experience(ex), barberId("B"+to_string(userId)){};
    
    void setRole(){
        cout<<"Nhập chuyên môn: ";
        string s;
        cin.ignore();
        getline(cin,s);
        stringstream ss(s);
        string tmp;
        while(getline(ss,tmp,',')){
            role.push_back(tmp);
        }     
    }

    void cancelRole(){
        cout<<"Nhập chuyên môn cần xoá: ";
        string s;cin>>s;
        int count =0;
        for(auto x:role){
            if(x==s){
                role.erase(role.begin()+count);
                break;
            }
            ++count;
        }
    }

    string getBarberId(){
        return barberId;
    }
    vector<string> getRole(){
        return role;
    }
    int getExperience(){
        return experience;
    }
};