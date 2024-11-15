#include "Person/Person.cpp"
#include "Appointment/Appointment.cpp"
#include "Manager/Manager.cpp"

void login(Manager& manager){
    string s;
    cout<<"NHAP PASSWORD: ";
    while(cin>>s){
        if(manager.checkPass(s))break;
        else cout<<"VUI LONG NHAP LAI! : ";
    }
}

void menu_Custome(Manager& manager){
    int choice;
    while (true) {
        cout << "\n QUAN LY KHACH HANG:\n";
        cout << string(35,'-') << endl;
        cout << "1. DAT LICH HEN\n";
        cout << "2. CHINH SUA THONG TIN KHACH HANG\n";
        cout << "3. LICH SU CAC LICH HEN\n";
        cout << "4. CHINH SUA LICH HEN\n";
        cout << "0. QUAY TRO LAI MENU\n";
        cout << "KHACH HANG - LICH HEN -> ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.booking();
                break;
            case 2:{
                cout<<"NHAP SO DIEN THOAI KHACH HANG CAN THAY DOI THONG TIN: ";
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
                manager.editCustomerInfo(number);
                break;
            }
            case 3:
                manager.viewHistory();
                break;
            case 4:
                manager.changeApp();
                break;
            case 0:
                cout<<string(35,'-')<<endl;
                return; // Exit the program or return to the main menu
            default:
                cout << "LUA CHON KHONG HOP LE. VUI LONG THU LAI.\n";
                break;
        }
    }
}

void menu_Manage(Manager& manager) {
    int choice;
    while (true) {
        cout << "\n QUAN LY NHAN VIEN VA DICH VU:\n";
        cout << string(35,'-') << endl;
        cout << "1.  THEM BARBER\n";
        cout << "2.  XOA BARBER\n";
        cout << "3.  THEM DICH VU\n";
        cout << "4.  XOA DICH VU\n";
        cout << "5.  XOA KHACH HANG\n";
        cout << "6.  DANH SACH KHACH HANG\n";
        cout << "7.  DANH SACH BARBER\n";
        cout << "8.  DANH SACH DICH VU\n";
        cout << "9.  LICH LAM VIEC CUA BARBER\n";
        cout << "10. CHINH SUA LICH LAM VIEC\n";
        cout << "11. XEM BAO CAO THONG KE DICH VU VA KHACH HANG\n";
        cout << "0. QUAY LAI MENU\n";
        cout << "QUAN LY NHAN VIEN - DICH VU ->  ";
        cin >> choice;

        string Id;
        switch (choice) {
            case 1:
                manager.addBarber();
                break;
            case 2:
                cout << "NHAP ID BARBER: "; cin >> Id;
                manager.cancelBarber(Id);
                break;
            case 3:
                manager.addService();
                break;
            case 4:
                cout << "NHAP ID DICH VU: "; cin >> Id;
                manager.cancelService(Id);
                break;
            case 5:
                cout << "NHAP ID KHACH HANG: "; cin >> Id;
                manager.cancelCustomer(Id);
                break;
            case 6:
                manager.displayCustomers();
                break;
            case 7:
                manager.displayBarbers();
                break;
            case 8:
                manager.displayServices();
                break;
            case 9:
                manager.showSchedule();
                break;
            case 10:
                manager.adjustSchedule();
                break;
            case 11:
                manager.Customer_Service_Analytics();
                break;
            case 0:
                cout<<string(35,'-')<<endl;
                return;  // Exit and return to the main menu
            default:
                cout << "LUA CHON KHONG HOP LE. VUI LONG THU LAI.\n";
                break;
        }
    }
}

void menu(Manager& manager){
    int choice = -1;
    while(true){
        cout << "1. QUAN LY KHACH HANG\n";
        cout << "2. QUAN LY NHAN VIEN VA DICH VU\n";
        cout << "0. THOAT\n";
        cout << "CHON CHUC NANG (0-2): ";
        cin >> choice;

        switch(choice){
        case 1:
            menu_Custome(manager);
            break;
        case 2:
            menu_Manage(manager);
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

int main(){
    Manager manager;
    login(manager);
    menu(manager);
    return 0;
}