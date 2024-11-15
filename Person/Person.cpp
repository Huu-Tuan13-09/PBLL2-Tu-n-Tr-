#include "Person.h"

int Person::personId = 1000;

Person::Person() {}

Person::Person(const string& phone) : phone(phone) {
    ++personId;
}

string Person::getName() const {
    return name;
}

string Person::getPhone() const {
    return phone;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setPhone(const string& phone){
    this->phone=phone;
}

// Implementation of Barber class

Barber::Barber() {}

Barber::Barber(const string& name, const string& phone, int ex)
    : Person(phone), experience(ex), barberId("B" + to_string(personId)) {
    setName(name);
}

void Barber::createRole(const vector<string>& Role) {
    this->role = Role;
}

void Barber::setWorking(string s) {
    string tmp;
    stringstream ss(s);
    while (getline(ss, tmp, ';')) {
        int i = tmp.find('-');
        if (i == string::npos) {
            // Không in lỗi, chỉ bỏ qua chuỗi không hợp lệ
            continue;
        }

        string day = tmp.substr(0, i);
        string shifts = tmp.substr(i + 1);

        // Kiểm tra giá trị day
        int number = 0;
        if (day == "cn" || day == "Cn" || day == "CN" || day == "cN") {
            number = 8; // Chủ Nhật
        } else {
            try {
                number = stoi(day); // Chuyển day thành số
            } catch (const std::invalid_argument&) {
                // Bỏ qua chuỗi không hợp lệ nếu không thể chuyển thành số
                continue;
            } catch (const std::out_of_range&) {
                // Bỏ qua chuỗi không hợp lệ nếu giá trị ngoài phạm vi
                continue;
            }
        }

        // Lấy các ca làm việc
        stringstream shiftStream(shifts);
        string shift;
        while (getline(shiftStream, shift, ',')) {
            sche.day[number][shift] += name + ",";
            vWorking[day].push_back(shift);
        }
    }
}

void Barber::changeWorking() {
    cout << "NHAP NGAY CAN THAY DOI CA LAM: ";
    string changeDay;
    cin >> changeDay;
    int number = (changeDay == "cn"||changeDay == "CN"||changeDay == "Cn"||changeDay == "cN") ? 8 : stoi(changeDay);

    for (auto& [key, shifts] : vWorking) {
        if (key == changeDay) {
            shifts.clear();
            for (auto& [shift, names] : sche.day[number]) {
                auto pos = names.find(getName());
                if (pos != string::npos) {
                    names.erase(pos, getName().length() + 1);
                }
            }
            break;
        }
    }
        cout << "NHAP CA LAM VIEC (CAC CA NGAN CACH BANG DAU PHAY): ";
        string ca;
        cin >> ca;
        stringstream ss(ca);
        string tmp;
        while (getline(ss, tmp, ',')) {
            sche.day[number][tmp] += this->getName() + ',';
            vWorking[changeDay].push_back(tmp);
        }
}

void Barber::deleteWorking() {
    cout << "NHAP NGAY CAN XOA: ";
    string changeDay;
    cin >> changeDay;
    int number = (changeDay == "cn"||changeDay == "CN"||changeDay == "Cn"||changeDay == "cN") ? 8 : stoi(changeDay);

    for (auto& [shift, names] : sche.day[number]) {
        auto pos = names.find(getName());
        if (pos != string::npos) {
            names.erase(pos, getName().length() + 1);
        }
    }

    auto it = vWorking.find(changeDay);
    if (it != vWorking.end()) {
        vWorking.erase(it);
    }
}

void Barber::setRole() {
    cout << "NHAP CHUYEN MON (CAC CHUYEN MON NGAN CACH NHAU BOI DAU PHAY): ";
    string specialties;
    cin.ignore();
    getline(cin, specialties);
    stringstream ss(specialties);
    string specialty;
    while (getline(ss, specialty, ',')) {
        role.push_back(specialty);
    }
}

void Barber::cancelRole() {
    cout << "NHAP CHUYEN MON CAN XOA: ";
    string s;
    cin >> s;
    auto it = find(role.begin(), role.end(), s);
    if (it != role.end()) {
        role.erase(it);
    }
}

string Barber::getBarberId() const {
    return barberId;
}

vector<string> Barber::getRole() const {
    return role;
}

int Barber::getExperience() const {
    return experience;
}

map<string, vector<string>> Barber::getWorking() const {
    return vWorking;
}

// Implementation of Customer class

Customer::Customer() {}

Customer::Customer(const string& phone) : Person(phone) {
    customerId = "C" + to_string(personId);
    setLoyaltyLevel();

    cout << "TEN KHACH HANG: ";
    string name;
    cin.ignore();
    getline(cin, name);
    setName(name);

    cout << "GIOI TINH: ";
    while(cin>>sex){
        if(sex=="nu"||sex=="Nu"||sex=="NU"||sex=="nU"){
            sex="NU";
            break;
        }
        else if(sex=="Nam"||sex=="nam"||sex=="NAm"||sex=="Nam"||sex=="nAM"||sex=="NaM"||sex=="nAm"||sex=="NAM"){
            sex="NAM";
            break;
        }
        cout<<"GIOI TINH KHONG DUNG \nVUI LONG NHAP LAI: ";
    }
    
    cout << "TUOI: ";cin>>age;
}

void Customer::setLoyaltyLevel(int level) {
    loyaltyLevel = min(level, 4);
}

void Customer::setSex(string sex){
    this->sex=sex;
}

void Customer::setAge(int age){
    this->age=age;
}

int Customer::getLoyaltyLevel() const {
    return loyaltyLevel;
}

string Customer::getCustomerId(){
    return customerId;
}

int Customer::getAge() const {
    return age;
}

string Customer::getSex() const {
    return sex;
}

void Schedule::showScheduled(){
    for(int i=2;i<=8;i++){
        if(i==8)cout<<endl<<"CHU NHAT:"<<endl;
        else cout<<endl<<"THU "<<i<<":"<<endl;
        if(!day[i].empty())
        for(auto it:day[i]){
            cout<<string(4,' ')<<it.first<<": "<<it.second<<endl;
        }
    }
}
