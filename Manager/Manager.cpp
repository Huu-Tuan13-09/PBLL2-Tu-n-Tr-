    #include "Manager.h"
    #include <iomanip>

    //Constructor
    Manager::Manager(){
        createBarber();
        createServices();
    }
    //Khoi tao dich vu
    void Manager::createServices() {
        ifstream file("Appointment/service.dat");
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
        ifstream file("Person/barbers.dat");
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
                string tmp;
                getline(ss,tmp);
                newBar.setWorking(tmp);
                barbers.push_back(newBar);
            }
        }
        file.close();
    }
    //Xem danh sach Barber
    void Manager::displayBarbers(){
        cout<<endl;
        string title = "DANH SACH NHAN VIEN VA DICH VU DAM NHAN";
        int tableWidth = 80;
        cout << string((tableWidth - title.length()) / 2, ' ') << title << endl;
        cout << string(tableWidth, '-') << endl;       
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
    //Xem dich vu
    void Manager::displayServices(){
        string title = "THONG TIN DICH VU";
        int tableWidth = 65;
        cout << string((tableWidth - title.length()) / 2, ' ') << title << endl;
        cout << string(tableWidth, '-') << endl;
        cout<<left<<setw(10)<<"ID"
            <<setw(30)<<"NAMESERVICE"
            <<setw(10)<<"TIME"
            <<setw(15)<<" PRICE"<<endl;
        cout<<string(65,'-')<<endl; 
        for(Service ser : services){
            cout<<left<<setw(10)<< ser.getServiceId() 
            <<setw(30)<< ser.getNameService() 
            <<setw(10)<< ser.getDuration()
            <<setw(15)<< ser.getPrice() << endl;
        }
    }
    //Theo doi lich lam viec
    void Manager::showSchedule(){
        sche.showScheduled();
    }
    //Dieu chinh lich lam viec cua tat ca cac tho
    void Manager::adjustSchedule() {
        string action, barberId;
        cout << "SUA HAY XOA: ";
        cin >> action;
        cout << "NHAP ID BARBER: ";
        cin >> barberId;
        transform(action.begin(), action.end(), action.begin(), ::tolower);
        auto barber = findBarId(barberId);
        if (barber != nullptr) {
            if (action == "sua") {
                barber->changeWorking();
        } else {
                barber->deleteWorking();
            }
        } else {
            cout << "BARBER KHONG TON TAI!\n";
        }
    }
    // Dieu chinh thong tin khach hang
    void Manager::editCustomerInfo(const string& phone){
        Customer* customer=findCusId_Phone(phone);
        if(!customer){
            cout<<"KHONG TIM THAY KHACH HANG VOI SO DIEN THOAI NAY.\n";
            return;
        }
        int choice;
        while (true) {
            cout << "\n DIEU CHINH THONG TIN KHACH HANG:\n";
            cout << string(35,'-') << endl;
            cout << "1. CAP NHAT TEN\n";
            cout << "2. CAP NHAT SO DIEN THOAI\n";
            cout << "3. CAP NHAT MUC DO THAN THIET\n";
            cout << "4. CAP NHAT TUOI\n";
            cout << "0. QUAY TRO LAI MENU\n";
            cout << "DIEU CHINH -> ";
            cin >> choice;

            switch (choice) {
                case 1:{
                    string name;
                    cin.ignore();
                    cout<<"NHAP TEN MOI: ";
                    while(getline(cin,name)){
                        if(name!=customer->getName())break;
                        cout<<"DA CO TEN NAY! VUI LONG NHAP LAI: ";
                    }
                    customer->setName(name);
                    cout<<"TEN DA DUOC CAP NHAT.\n";
                    break;
                }    
                case 2:{
                    bool check=false;
                    cout<<"NHAP SO DIEN THOAI CAN CAP NHAT: ";
                    string number;
                    while(cin>>number){
                        if(number==customer->getPhone()){
                            cout<<"SO DIEN THOAI NAY DA TON TAI, BAN MUON GIU LAI SO NAY KHONG! (Y/N) ";
                            char Check;cin>>Check;
                            if(toupper(Check)=='Y')break;
                        }
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
                    customer->setPhone(number);
                    cout<<"SO DIEN THOAI DA DUOC CAP NHAT.\n";
                    break;
                }
                case 3:{
                    cout<<"MUC DO THAN THIET MOI(1-4) :";
                    int level;cin>>level;
                    customer->setLoyaltyLevel(level);
                    cout<<"MUC DO THAN THIET DA DUOC CAP NHAT. \n";
                    break;
                }
                case 4:{
                    cout<<"TUOI CAN CAP NHAT: ";
                    int age;cin>>age;
                    customer->setAge(age);
                    cout<<"TUOI DA DUOC CAP NHAT.\n";
                    break;
                }
                case 0:
                    cout<<string(35,'-')<<endl;
                    return; // Exit the program or return to the main menu
                default:
                    cout << "LUA CHON KHONG HOP LE. VUI LONG THU LAI.\n";
                    break;
            }
        }
    }
    // Xem bao cao thong ke dich vu khach hang
    void Manager::Customer_Service_Analytics() {
        cout<<"\nTHONG KE DICH VU VA KHACH HANG\n";
        cout<<string(45,'-')<<endl;
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
            cout << entry.first << ": " << entry.second << " LAN" << endl;
        }
    }
    //Cap nhat muc do than thiet cua khach hang
    void Manager::updateLoyaltyLevel(string cusId, int loyaltyLevel){
        if(findCusId_Phone(cusId)!=nullptr){
            findCusId_Phone(cusId)->setLoyaltyLevel(loyaltyLevel);
            cout<<"DA CAP NHAT THANH CONG!"<<endl;
        }
        else {
            cout<<"KHONG TIM THAY KHACH HANG NAY!"<<endl;
        }
    }
    //xem lich su 
    void Manager::viewHistory(){
        for(auto it:appointments){
            cout<<it.getAptId()<<','<<it.getTimeApp().getDay()<<' '<<it.getTimeApp().getTimeOfDay()<<
            ','<<it.getTime()<<','<<findCusId_Phone(it.getCusId())->getName() <<','<<findSerId(it.getSerId())->getNameService()<<',';
            Time now;
            string tmp=it.getTime();
            vector<string> v;
            stringstream ss(tmp);
            string word;
            while(ss>>word){
                v.push_back(word);
            }
            if(v[0]>now.getDay())cout<<"CHUA HOAN THANH"<<endl;
            else {
                if(now.getTimeOfDay()>v[1]){cout<<"HOAN THANH"<<endl;it.setStatus("HOAN THANH");}
                else cout<<"CHUA HOAN THANH"<<endl; 
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
        for(auto &it : customers){
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
        cout<<"THOI GIAN (VD:12-12-2024 07:00): ";
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
        cout<<string(65,'-')<<endl;
        cout<<"          DA DAT LICH HEN THANH CONG!\n";
    }
    //Thay doi lich hen
    void Manager::changeApp(){
        cout<<"NHAP ID LICH HEN CAN THAY DOI : ";
        string Id ; cin>>Id;
        cout<<"THOI GIAN (VD:12-12-2024 07:00): ";
        string TIME;
        cin.ignore(1);
        getline(cin,TIME);
        findAptId(Id)->setTime(TIME);
        cout<<"DA THAY DOI LICH HEN THANH CONG!"<<endl;
    }
    //Them Barber
    void Manager::addBarber(){
        char check;
        do{
            cout<<"TEN NHAN VIEN: ";
            cin.ignore();
            string name;getline(cin,name);
            cout<<"SO DIEN THOAI NHAN VIEN: ";
            string phone ;cin>>phone;
            cout<<"KINH NGHIEM HIEN TAI: ";
            int ex;cin>>ex;
            Barber newBarber(name, phone, ex);
            newBarber.setRole();
            barbers.push_back(newBarber);
            cout<<"DA THEM BARBER THANH CONG! BAN CO MUON TIEP TUC THEM ? (Y/N) : ";cin>>check;
        }while(check=='Y'||check=='y');
    }
    // Them Service
    void Manager::addService(){
        char check;
        do{
            cin.ignore(1);
            cout << "TEN: "; string name; getline(cin,name);
            cout << "GIA TIEN: "; double price; cin >> price;
            cout << "THOI GIAN (PHUT): "; int duration; cin >> duration;
            Service newSer(name,price,duration);
            services.push_back(newSer);
            cout<<"DA THEM DICH VU THANH CONG! BAN CO MUON TIEP TUC THEM ? (Y/N) : ";cin>>check;
        }while(check=='Y'||check=='y');
    }   
    // Huỷ thành viên từng class theo id
    void Manager::cancelCustomer(string Id_Phone){
        for(int i = customers.size() - 1; i >= 0; i--){
            if(customers[i].getCustomerId() == Id_Phone || customers[i].getPhone() == Id_Phone){
                customers.erase(customers.begin()+i);
                cout<<"DA XOA KHACH HANG THANH CONG!"<<endl;
                return;
            }
        }       
        cout<<"KHACH HANG KHONG TON TAI!"<<endl;
    }

    void Manager::cancelBarber(string Id){
        for(int i = barbers.size() - 1; i >= 0; i--){
            if(barbers[i].getBarberId() == Id){
                barbers.erase(barbers.begin()+i);
                cout<<"DA XOA BARBER THANH CONG!"<<endl;
                return;
            }
        }
        cout<<"BARBER KHONG TON TAI!"<<endl;
    }

    void Manager::cancelService(string Id){
        for(int i = services.size() - 1; i >= 0; i--){
            if(services[i].getServiceId() == Id){
                services.erase(services.begin()+i);
                cout<<"DA XOA DICH VU THANH CONG!"<<endl;
                return;
            }
        }
        cout<<"DICH VU KHONG TON TAI!"<<endl;
    }

    void Manager::cancelAppointment(string Id){
        for(int i = appointments.size() - 1; i >= 0; i--){
            if(appointments[i].getAptId() == Id){
                appointments.erase(appointments.begin()+i);
                cout<<"DA XOA LICH HEN THANH CONG!"<<endl;
                return;
            }
        }
        cout<<"KHONG CO LICH HEN NAY!"<<endl;
    }
    // Tìm kiếm id
    Customer* Manager::findCusId_Phone(const string& Id_Phone) {
        for (auto& customer : customers) {
            if (customer.getCustomerId() == Id_Phone||customer.getPhone() == Id_Phone) {
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