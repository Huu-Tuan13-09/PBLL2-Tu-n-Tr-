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


int main(){

    return 0;
}