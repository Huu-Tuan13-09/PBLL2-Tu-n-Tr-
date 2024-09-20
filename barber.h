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

    Barber(int ex) : experience(ex), barberId("B"+to_string(userId)){};
    
    void setWorking(){
        while(true){
            pair<string,vector<string>> w;
            cout<<"Nhap ngay: ";string day;cin>>day;w.first=day;
            cout<<"Nhap ca lam viec(cac ca lam ngan cach boi dau phay): ";string ca;cin>>ca;
            stringstream ss(ca);
            string tmp; 
            while(getline(ss,tmp,',')){
                w.second.push_back(tmp);
            }
            vWorking.push_back(w);
            cout<<"Tiep tuc them ngay? (Y/N)";
            char a;cin>>a;
            if(a=='N'||a=='n')break;
        }
    }

    void changeWorking(){
        string changeDay;
        cout<<"Nhap ngay can thay doi ca lam: ";
        cin>>changeDay;
        for(auto x:vWorking){
            if(x.first==changeDay){
                x.second.clear();
                cout<<"Nhap ca lam viec(cac ca lam ngan cach boi dau phay): ";string ca;cin>>ca;
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
        cout<<"Nhap ngay can xoa: ";
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

    void 

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