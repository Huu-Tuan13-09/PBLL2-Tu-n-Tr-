    #include "Manager.h"
    #include <iomanip>

    //Khoi tao dich vu
    void Manager::createServices() {
        ifstream file("Appointment/service.csv");
        if (!file.is_open()) {
            cerr << "KHONG THE MO FILE CHUA THONG TIN DICH VU!" << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            string name, price, dur;
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, price, ',');
            getline(ss, dur, ',');

            if (!name.empty() && !price.empty() && !dur.empty()) {
                Service newSer(name, stod(price), stoi(dur));
                services.push_back(newSer);
            }
        }
        file.close();
    }
    //khoi tao barber
    void Manager::createBarber() {
        ifstream file("Person/barbers.csv");
        if (!file.is_open()) {
            cerr << "KHONG THE MO FILE CHUA THONG TIN BARBER!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone, ex, working;
            vector<string> workingDays;
            getline(ss, name, '.');
            getline(ss, phone, '.');
            getline(ss, ex, '.');
            getline(ss,working,'.');
            string workingDaysStr;
            stringstream tmp(working);
            while (getline(tmp, workingDaysStr, '-')) {
                workingDays.push_back(workingDaysStr);
            }

            if (!name.empty() && !phone.empty() && !ex.empty()) {
                Barber newBar(name, phone, stoi(ex));
                newBar.createRole(workingDays);
                newBar.setWorking(ss.str());
                barbers.push_back(newBar);
            }
        }
        file.close();
    }
    //Xem danh sach Barber
    void Manager::displayBarbers(){
        cout<<left<<setw(8)<<"ID"<<setw(20)<<"NAME"<<setw(15)<<"PHONE"<<setw(12)<<"EXPERIENCE"<<"ROLE\n";
        cout<<string(80, '-')<<endl;
        for(auto barber : barbers){
            cout<<left<<setw(8)<<barber.getBarberId()
            <<setw(20)<<barber.getName()
            <<setw(15)<<barber.getPhone()
            <<setw(12)<<barber.getExperience();
            vector<string> roles = barber.getRole();
            if(!roles.empty()){
                cout<<roles[0]<<endl;
                for(int i=1;i<roles.size();i++){
                    cout<<setw(55)<<""<<roles[i]<<endl;
                }
                cout<<endl;
            }
            else cout<<endl;
        }
    }
    //Xem danh sach khach hang
    void Manager::displayCustomers() {
    cout << left << setw(10) << "ID"
         << setw(20) << "NAME"
         << setw(15) << "PHONE"
         << right << setw(8) << "AGE"
         << setw(8) << "SEX"
         << setw(15) << "LOYALTYLEVEL" << endl;
    cout << string(80, '-') << endl;
        for (auto customer : customers) {
            cout<<left<<setw(10)<< customer.getCustomerId() 
                << setw(20) << customer.getName() 
                << setw(15) << customer.getPhone() 
                <<right<<setw(8)<< customer.getAge() 
                << setw(8) << customer.getSex() 
                << setw(15) << customer.getLoyaltyLevel() << "\n";
        }
    }
    //Theo doi lich lam viec
    void Manager::showSchedule(){
        sche.showScheduled();
    }
    //Dieu chinh lich lam viec cua tat ca cac tho
    void Manager::adjustSchedule(){
        string s1,s2;
        cout<<"SUA HAY XOA: ";cin>>s1;
        cout<<"NHAP ID BARBER: ";cin>>s2;
        if(s1=="sua"||s1=="SUA"||s1=="Sua"){
            if(findBarId(s2)!=nullptr)findBarId(s2)->changeWorking();    
        }else {
            if(findBarId(s2)!=nullptr)findBarId(s2)->deleteWorking();
        }
    }
    // Xem báo cáo chi tiết và phân tích dịch vụ khách hàng
    void Manager::Customer_Service_Analytics() {
        cout << "SO LUONG DICH VU DA CUNG CAP: " << appointments.size() << endl;

        // Tính tổng doanh thu từ các dịch vụ đã cung cấp
        double totalRevenue = 0;
        for (const auto& appointment : appointments) {
            Service* service = findSerId(appointment.getSerId());
            if (service != nullptr) {
                totalRevenue += service->getPrice();
            }
        }
        cout << "TONG DOANH THU TU DICH VU: " << totalRevenue << " VND" << endl;

        // Thống kê số lần đặt lịch theo dịch vụ
        map<string, int> serviceCount;
        for (const auto& appointment : appointments) {
            Service* service = findSerId(appointment.getSerId());
            if (service != nullptr) {
                serviceCount[service->getNameService()]++;
            }
        }
        cout << "SO LAN DAT LICH THEO DICH VU:" << endl;
        for (const auto& entry : serviceCount) {
            cout << entry.first << ": " << entry.second << " lan" << endl;
        }
    }
    //Xem dich vu
    void Manager::displayServices(){
        for(Service ser : services){
            cout << ser.getServiceId() << "," << ser.getNameService() << "(" 
            << ser.getDuration() << ")," << ser.getPrice() << endl;
        }
    }
    //Cap nhat muc do than thiet cua khach hang
    void Manager::updateLoyaltyLevel(string cusId, int loyaltyLevel){
        if(findCusId(cusId)!=nullptr){
            findCusId(cusId)->setLoyaltyLevel(loyaltyLevel);
        }
    }
    //xem lich su 
    void Manager::viewHistory(){
        for(auto it:appointments){
            cout<<it.getAptId()<<','<<it.getTimeApp().getDay()<<' '<<it.getTimeApp().getTimeOfDay()<<
            ','<<it.getTime()<<','<<findCusId(it.getCusId())->getName() <<','<<findSerId(it.getSerId())->getNameService()<<',';
            Time now;
            string tmp=it.getTime();
            vector<string> v;
            stringstream ss(tmp);
            string word;
            while(ss>>word){
                v.push_back(word);
            }
            if(v[0]>now.getDay())cout<<"PENDING"<<endl;
            else {
                if(now.getTimeOfDay()>v[1]){cout<<"COMPLETED"<<endl;it.setStatus("COMPLETED");}
                else cout<<"PENDING"<<endl; 
            }
        }
    }
    //Dat lich va chon dich vu
    void Manager::booking(){
        bool check=false;
        cout<<"NHAP SO DIEN THOAI KHACH HANG: ";
        string number;
        while(cin>>number){
            if(number[0]=='0'&&(number[1]>='1'&&number[1]<='9')&&number.length()==10){
                bool check=false;
                for(int i=2;i<number.length();i++){
                    if(number[i]<'0'||number[i]>'9'){
                        check=true;
                        break;
                    }
                }
                if(!check)break;
            }
            cout<<"SO DIEN THOAI KHONG HOP LE !\nVUI LONG NHAP LAI: ";
        }
        Customer tmp;
        for(auto it : customers){
            if(number==it.getPhone()){
                it.setLoyaltyLevel(it.getLoyaltyLevel()+1);
                check=true;
                tmp=it;
                break;
            }
        }
        if(!check){
            cout<<"CHUA CO KHACH HANG NAY! "<<endl;
            Customer newCus(number);
            customers.push_back(newCus);
            tmp=newCus;
        }
        displayServices();
        cout<<"NHAP ID DICH VU: ";
        string idSer;
        auto itBegin=services.begin(),itEnd=services.end();
        --itEnd;        
        while(cin>>idSer){
            if(idSer>=(*itBegin).getServiceId() && idSer<=(*itEnd).getServiceId())break;
            cout<<"KHONG CO DICH VU NAY! \nVUI LONG NHAP LAI ID DICH VU: ";
        }
        showSchedule();
        cout<<"THOI GIAN: ";
        string TIME;
        cin.ignore(1);
        while(getline(cin,TIME)){
            if(sche.scheduled[TIME]>=4){
                cout<<"DA QUA NHIEU LICH CHO THOI GIAN NAY!\nCHON THOI GIAN KHAC: ";
            }else break;
        }
        sche.scheduled[TIME]+=1;
        Appointment newApp(tmp.getCustomerId(),idSer,TIME);
        appointments.push_back(newApp);
    }
    //Thay doi lich hen
    void Manager::changeApp(){
        cout<<"NHAP ID LICH HEN CAN THAY DOI : ";
        string Id ; cin>>Id;
        cout<<"THOI GIAN : ";
        string TIME;
        cin.ignore(1);
        getline(cin,TIME);
        findAptId(Id)->setTime(TIME);
    }
    //Them Barber
    void Manager::addBarber(){
        char check;
        do{
            string name;getline(cin,name);
            string phone ;cin>>phone;
            int ex;cin>>ex;
            Barber newBarber(name, phone, ex);
            newBarber.setRole();
            barbers.push_back(newBarber);
            cout<<"Tiep tuc them ? (Y/N) : ";cin>>check;
        }while(check=='Y'||check=='y');
    }
    // Them Service
    void Manager::addService(){
        char check;
        do{
            cout << "NAME: "; string name; getline(cin,name);
            cout << "PRICE: "; double price; cin >> price;
            cout << "DURATION: "; int duration; cin >> duration;
            Service newSer(name,price,duration);
            services.push_back(newSer);
            cout<<"TIEP TUC THEM ? (Y/N) : ";cin>>check;
        }while(check=='Y'||check=='y');
    }   
    // Huỷ thành viên từng class theo id
    void Manager::cancelCustomer(string Id){
        for(int i = customers.size() - 1; i >= 0; i--){
            if(customers[i].getCustomerId() == Id){
                customers.erase(customers.begin()+i);
            }
        }       
    }

    void Manager::cancelBarber(string Id){
        for(int i = barbers.size() - 1; i >= 0; i--){
            if(barbers[i].getBarberId() == Id){
                barbers.erase(barbers.begin()+i);
            }
        }
    }

    void Manager::cancelService(string Id){
        for(int i = services.size() - 1; i >= 0; i--){
            if(services[i].getServiceId() == Id){
                services.erase(services.begin()+i);
            }
        }
    }

    void Manager::cancelAppointment(string Id){
        for(int i = appointments.size() - 1; i >= 0; i--){
            if(appointments[i].getAptId() == Id){
                appointments.erase(appointments.begin()+i);
            }
        }
    }
    // Tìm kiếm id
    Customer* Manager::findCusId(const string& Id) {
        for (auto& customer : customers) {
            if (customer.getCustomerId() == Id) {
                return &customer;
            }
        }
        return nullptr;
    }
   
    Barber* Manager::findBarId(const string& Id) {
        for (auto& barber : barbers) {
            if (barber.getBarberId() == Id) {
                return &barber;
            }
        }
        return nullptr;
    }
   
    Service* Manager::findSerId(const string& Id) {
        for (auto& service : services) {
            if (service.getServiceId() == Id) {
                return &service;
            }
        }
        return nullptr;
    }
   
    Appointment*Manager::findAptId(const string& Id) {
        for (auto& appointment : appointments) {
            if (appointment.getAptId() == Id) {
                return &appointment;
            }
        }
        return nullptr;
    }
    // Kiểm tra mật khẩu 
    bool Manager::checkPass(string tmp){
        if(password==tmp)return true;
        return false;
    }
