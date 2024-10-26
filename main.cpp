#include "manager.h"
using namespace std;

void loadCustomersFromFile(const string& filename, vector<Customer>& customers) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    string line, name, phone, ageStr, sex, loyaltyLevelStr;
    getline(file, line);  // Bỏ qua dòng tiêu đề

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, ageStr, ',');
        getline(ss, sex, ',');
        getline(ss, loyaltyLevelStr, ',');

        int age = stoi(ageStr);
        int loyaltyLevel = stoi(loyaltyLevelStr);

        // Tạo đối tượng Customer và thêm vào vector
        customers.push_back(Customer(name, phone, age, sex, loyaltyLevel));
    }

    file.close();
}

void loadBarbersFromFile(const string& filename, vector<Barber>& barbers) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    string line, name, phone, ageStr, gender, servicesOffered, experienceStr, workShifts;
    getline(file, line);  // Bỏ qua dòng tiêu đề

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, ageStr, ',');
        getline(ss, gender, ',');
        getline(ss, servicesOffered, ',');
        getline(ss, experienceStr, ',');
        getline(ss, workShifts, ',');

        int age = stoi(ageStr);
        int experience = stoi(experienceStr);

        // Chuyển các dịch vụ thành vector<string>
        vector<string> roles;
        stringstream ssServices(servicesOffered);
        string service;
        while (getline(ssServices, service, ';')) {
            roles.push_back(service);
        }

        // Chuyển các ca làm việc thành vector<pair<string, vector<string>>>
        vector<pair<string, vector<string>>> workingShifts;
        stringstream ssShifts(workShifts);
        string shift;
        while (getline(ssShifts, shift, ';')) {
            string day = shift.substr(1);   // Ngày làm việc (2, 3, 4,...)
            string time = shift.substr(0, 1);  // Ca làm việc (A, B, C)
            
            // Kiểm tra nếu ngày đã tồn tại, thêm ca vào ngày đó
            bool found = false;
            for (auto &entry : workingShifts) {
                if (entry.first == day) {
                    entry.second.push_back(time);
                    found = true;
                    break;
                }
            }
            if (!found) {
                workingShifts.push_back({day, {time}});
            }
        }

        // Tạo đối tượng Barber và thêm vào vector
        barbers.push_back(Barber(name, phone, roles, experience, workingShifts));
    }

    file.close();
}

void loadServicesFromFile(const string& filename, vector<Service>& services) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    string line, nameService, priceStr, durationStr;
    getline(file, line);  // Bỏ qua dòng tiêu đề

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, nameService, ',');
        getline(ss, priceStr, ',');
        getline(ss, durationStr, ',');

        double price = stod(priceStr);
        int duration = stoi(durationStr);

        // Tạo đối tượng Service và thêm vào vector
        services.push_back(Service(nameService, price, duration));
    }

    file.close();
}

void loadAppointmentsFromFile(const string& filename, vector<Appointment>& appointments) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    string line, bookingTime, appointmentTime, customerName, serviceName, barberName, status;
    getline(file, line);  // Bỏ qua dòng tiêu đề

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, bookingTime, ',');
        getline(ss, appointmentTime, ',');
        getline(ss, customerName, ',');
        getline(ss, serviceName, ',');
        getline(ss, barberName, ',');
        getline(ss, status, ',');

        // Ở đây cần ánh xạ customerName, barberName, serviceName sang CustomerId, BarberId, ServiceId
        string customerId = getCustomerIdByName(customerName);  // Hàm giả định để lấy ID khách hàng
        string barberId = getBarberIdByName(barberName);        // Hàm giả định để lấy ID thợ cắt tóc
        string serviceId = getServiceIdByName(serviceName);      // Hàm giả định để lấy ID dịch vụ

        // Tạo đối tượng Appointment và thêm vào vector
        appointments.push_back(Appointment(customerId, barberId, serviceId, status, appointmentTime));
    }

    file.close();
}

int menu(){
    int choice = -1;
    while(true){
        cout << "1. Khách hàng\n";
        cout << "2. Thợ cắt tóc\n";
        cout << "3. Dịch vụ\n";
        cout << "4. Lịch hẹn\n";
        cout << "0. Thoát!\n";
        cout << "Chọn chức năng(0-4): ";
        cin >> choice;

        switch (choice){
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
}

int menuOfCustomer(){
    int choice;
    do {
        cout << "===== MENU KHÁCH HÀNG =====" << endl;
        cout << "1. Thêm khách hàng mới" << endl;
        cout << "2. Xem thông tin khách hàng" << endl;
        cout << "3. Cập nhật thông tin khách hàng" << endl;
        cout << "4. Xóa khách hàng" << endl;
        cout << "5. Quay lại menu chính" << endl;
        cout << "Chọn chức năng (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Thêm khách hàng mới" << endl;
                // Thêm mã xử lý thêm khách hàng tại đây
                break;
            case 2:
                cout << "Xem thông tin khách hàng" << endl;
                // Thêm mã xử lý xem thông tin khách hàng tại đây
                break;
            case 3:
                cout << "Cập nhật thông tin khách hàng" << endl;
                // Thêm mã xử lý cập nhật thông tin khách hàng tại đây
                break;
            case 4:
                cout << "Xóa khách hàng" << endl;
                // Thêm mã xử lý xóa khách hàng tại đây
                break;
            case 5:
                cout << "Quay lại menu chính..." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
        cout << endl;
    } while (choice != 5);
}

int menuOfBarber(){
    int choice;
    do {
        cout << "===== MENU THỢ CẮT TÓC =====" << endl;
        cout << "1. Thêm thợ cắt tóc mới" << endl;
        cout << "2. Xem thông tin thợ cắt tóc" << endl;
        cout << "3. Cập nhật thông tin thợ cắt tóc" << endl;
        cout << "4. Xóa thợ cắt tóc" << endl;
        cout << "5. Quản lý lịch làm việc của thợ" << endl;
        cout << "6. Quay lại menu chính" << endl;
        cout << "Chọn chức năng (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Thêm thợ cắt tóc mới" << endl;
                // Thêm mã xử lý thêm thợ cắt tóc tại đây
                break;
            case 2:
                cout << "Xem thông tin thợ cắt tóc" << endl;
                // Thêm mã xử lý xem thông tin thợ cắt tóc tại đây
                break;
            case 3:
                cout << "Cập nhật thông tin thợ cắt tóc" << endl;
                // Thêm mã xử lý cập nhật thông tin thợ cắt tóc tại đây
                break;
            case 4:
                cout << "Xóa thợ cắt tóc" << endl;
                // Thêm mã xử lý xóa thợ cắt tóc tại đây
                break;
            case 5:
                cout << "Quản lý lịch làm việc của thợ" << endl;
                // Thêm mã xử lý quản lý lịch làm việc của thợ tại đây
                break;
            case 6:
                cout << "Quay lại menu chính..." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
        cout << endl;
    } while (choice != 6);
}

int menuOfService(){
    int choice;
    do {
        cout << "===== MENU DỊCH VỤ =====" << endl;
        cout << "1. Thêm dịch vụ mới" << endl;
        cout << "2. Xem danh sách dịch vụ" << endl;
        cout << "3. Cập nhật thông tin dịch vụ" << endl;
        cout << "4. Xóa dịch vụ" << endl;
        cout << "5. Quay lại menu chính" << endl;
        cout << "Chọn chức năng (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Thêm dịch vụ mới" << endl;
                // Thêm mã xử lý thêm dịch vụ tại đây
                break;
            case 2:
                cout << "Xem danh sách dịch vụ" << endl;
                // Thêm mã xử lý xem danh sách dịch vụ tại đây
                break;
            case 3:
                cout << "Cập nhật thông tin dịch vụ" << endl;
                // Thêm mã xử lý cập nhật thông tin dịch vụ tại đây
                break;
            case 4:
                cout << "Xóa dịch vụ" << endl;
                // Thêm mã xử lý xóa dịch vụ tại đây
                break;
            case 5:
                cout << "Quay lại menu chính..." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
        cout << endl;
    } while (choice != 5);
}

int menuOfAppointment(){
    int choice;
    do {
        cout << "===== MENU LỊCH LÀM VIỆC =====" << endl;
        cout << "1. Thêm lịch làm việc mới" << endl;
        cout << "2. Xem lịch làm việc của thợ" << endl;
        cout << "3. Cập nhật lịch làm việc" << endl;
        cout << "4. Xóa lịch làm việc" << endl;
        cout << "5. Quay lại menu chính" << endl;
        cout << "Chọn chức năng (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Thêm lịch làm việc mới" << endl;
                // Thêm mã xử lý thêm lịch làm việc tại đây
                break;
            case 2:
                cout << "Xem lịch làm việc của thợ" << endl;
                // Thêm mã xử lý xem lịch làm việc của thợ tại đây
                break;
            case 3:
                cout << "Cập nhật lịch làm việc" << endl;
                // Thêm mã xử lý cập nhật lịch làm việc tại đây
                break;
            case 4:
                cout << "Xóa lịch làm việc" << endl;
                // Thêm mã xử lý xóa lịch làm việc tại đây
                break;
            case 5:
                cout << "Quay lại menu chính..." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
        cout << endl;
    } while (choice != 5);
}

int main(){
    Manager manager;
    int choice;
    cout << "===== Welcome to Hair Appointment Booking System ===== \n";
    while(1){
        cout << "Please enter the password for manager: ";
        string pass;
        getline(cin, pass);
        if(!checkPassword(pass)){
            cout << "Wrong password!!! \nPlease re-enter: ";
        }
        else break;
    }
    cout << "*** Welcome back manager! ***\n";
    menu();

    return 0;
}