#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;
class Employee {
public:
    string employeeName;
    double hoursWorked;
    double rateOfPay;
    double overTimeHours;

    Employee(string name, double hours, double rate, double OT){
        employeeName = std::move(name); //Clang-Tidy: Parameter 'name' is passed by value and only copied once; consider moving it to avoid unnecessary copies
        hoursWorked = hours;
        rateOfPay = rate;
        overTimeHours = OT;
    }

    double compensation() const{
        double result;
        result = (hoursWorked * rateOfPay) + (overTimeHours * (rateOfPay * 1.5));
        return result;
    }
};

int main() {
    Employee employee1("Alex", 40.572, 27.90, 10);
    int columnSize = 20;
    //row 1
    cout << setw(columnSize) << left << "Employee Name";
    cout << setw(columnSize) << right << "Total Compensation";
    cout << setw(columnSize) << right << "Rate of Pay";
    cout << setw(columnSize) << right << "Hours Worked" << endl;

    //row 2
    cout << setfill('=') << setw(50);


}
