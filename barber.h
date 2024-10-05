#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "user.h"
#include <algorithm>

using namespace std;

class Barber : public User{
private:
    string barberId;
    int experience;
    vector<string> role; 
    vector<pair<string,vector<string>>> vWorking;
public:
    Barber(){};

    Barber(string name, string phone, string role, int ex) : experience(ex), barberId("B"+to_string(userId)), User(name, phone, role) {};
    
    void setWorking(){
        while(true){
            pair<string,vector<string>> w;
            cout<<"Nhập ngày: "; cin>>w.first;
            cout<<"Nhập ca làm việc(các ca làm ngăn cách bởi dấu phẩy): ";string ca;cin>>ca;
            stringstream ss(ca);
            string tmp; 
            while(getline(ss,tmp,',')){
                w.second.push_back(tmp);
            }
            vWorking.push_back(w);
            cout<<"Tiếp tục thêm ngày? (Y/N)";
            char a;cin>>a;
            if(a=='N'||a=='n')break;
        }
    }

    void changeWorking(){
        string changeDay;
        cout<<"Nhập ngày cần thay đổi ca làm: ";
        cin>>changeDay;
        for(auto x:vWorking){
            if(x.first==changeDay){
                x.second.clear();
                cout<<"Nhập ca làm việc(các ca làm ngăn cách bởi dấu phẩy): ";string ca;cin>>ca;
                stringstream ss(ca);
                string tmp;
                while(getline(ss,tmp,',')){
                    x.second.push_back(tmp);
                }
            }
        }
    }

    void deleteWorking(){
        string changeDay;
        cout<<"Nhập ngày cần xoá: ";
        cin>>changeDay;
        auto it1=vWorking.begin();
        for(auto it=vWorking.begin();it!=vWorking.end();++it){
            if((*it).first==changeDay){
                it1=it;
                break;
            }
        }
        vWorking.erase(it1);
    }

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
    vector<pair<string,vector<string>>> getWorking(){
        return vWorking;
    }
};