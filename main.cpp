#include "Person/Person.cpp"
#include "Appointment/Appointment.cpp"
#include "Manager/Manager.cpp"
using namespace std;
Manager manager;

void menu_Custome(){
    int choice;
    while (true) {
        cout << "\nCustomer Menu:\n";
        cout << "1. Book Appointment\n";
        cout << "2. View Customer Details\n";
        cout << "3. Edit Customer Info\n";
        cout << "4. View Appointment History\n";
        cout << "5. Adjust Appointment\n";
        cout << "6. View Barber Schedule\n";
        cout << "7. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.booking();
                break;
            case 2:
                //viewCustomerDetails();
                break;
            case 3:
                //editCustomerInfo();
                break;
            case 4:
                manager.viewHistory();
                break;
            case 5:
                manager.changeApp();
                break;
            case 6:
                manager.showSchedule();
                break;
            case 7:
                return; // Exit the program or return to the main menu
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    }
}

void menu_Manage() {
    int choice;
    while (true) {
        cout << "\nManager Menu:\n";
        cout << "1. Add Barber\n";
        cout << "2. Remove Barber\n";
        cout << "3. Add Service\n";
        cout << "4. Remove Service\n";
        cout << "5. Delete Customer\n";
        cout << "6. View Customer List\n";
        cout << "7. View Barber List\n";
        cout << "8. View Service List\n";
        cout << "9. View Barber Schedule\n";
        cout << "10. Adjust Barber Schedule\n";
        cout << "11. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string Id;
        switch (choice) {
            case 1:
                manager.addBarber();
                break;
            case 2:
                cout << "Enter ID of Barber: "; cin >> Id;
                manager.cancelBarber(Id);
                break;
            case 3:
                manager.addService();
                break;
            case 4:
                cout << "Enter ID of Service: "; cin >> Id;
                manager.cancelService(Id);
                break;
            case 5:
                cout << "Enter ID of Customer: "; cin >> Id;
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
                return;  // Exit and return to the main menu
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void menu(){
    int choice = -1;
    while(true){
        cout << "1. Custome\n";
        cout << "2. Manage\n";
        cout << "0. Exit\n";
        cout << "Chọn chức năng(0-2): ";
        cin >> choice;

        switch(choice){
        case 1:
            menu_Custome();
            break;
        case 2:
            menu_Manage();
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
    string s;
    cout<<"NHAP PASSWORD: ";
    while(cin>>s){
        if(manager.checkPass(s))break;
        else cout<<"VUI LONG NHAP LAI! : ";
    }
    manager.createServices();
    manager.createBarber();
    // manager.displayBarbers();
    // manager.booking();
    // manager.booking();
    // manager.displayCustomers();
    menu();
    return 0;
}