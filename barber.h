#include <bits/stdc++.h>
#include "user.h"
using namespace std;

class Barber : public User{
private:
    string barberId;
    int experience;
    vector<string> role;   
public:
    Barber(){};

    Barber(int ex):experience(ex),barberId("B"+to_string(userId)){};
    
    void setRole(){
        cout<<"Nhap chuyen mon: ";
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
        cout<<"Nhap chuyen mon can xoa: ";
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
    void check(){
        cout<<"hello";
    }
};