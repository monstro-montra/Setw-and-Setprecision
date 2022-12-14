#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

int columnSize = 23;

class Employee {
public:
    string employeeName; //name of the employee
    double hoursWorked{}; //how many hours the employee worked
    double rateOfPay{}; //the rate of pay for the employee
    double overTimeHours{}; //how many overtime hours the employee worked
    double* pHoursWorked = new double;
    double* pRateOfPay = new double;
    double* pOvertimeHours = new double;

    Employee(string name, double hours, double rate, double OT){ //parameterized constructor. this class requires four parameters on object creation.
        employeeName = std::move(name); //Clang-Tidy: Parameter 'name' is passed by value and only copied once; consider moving it to avoid unnecessary copies
        hoursWorked = hours;
        rateOfPay = rate;
        overTimeHours = OT;
    }

    Employee() = default; //no args constructor. use with getData()

    double compensation() const{ //calculate the total compensation of this employee using this method.
        double result; //store result into this double
        result = (hoursWorked * rateOfPay) + (overTimeHours * (rateOfPay * 1.5)); //set result to this. 1.5 is the multiplier for overtime hours
        return result; //return the result of this calculation.
    }

    void printAddress() const{
        cout <<setw (columnSize) << " "; //empty first column up
        cout <<setw (columnSize) << " "; //empty second column
        cout << setw(columnSize) << left << pRateOfPay; //return pointer for rate of pay
        cout << setw(columnSize) << left << pHoursWorked; //return pointer for hours worked
        cout << setw(columnSize) << left << pOvertimeHours << endl; //return pointer for overtime hours and end line
    }

    void getData(){ //to be used with the no-args constructor. this method simply initializes each class field using cout and cin.
        cout << "Enter employee name:";
        cin >> employeeName;

        cout << "Enter amount of hours worked:";
        cin >> hoursWorked;

        cout << "Enter rate of pay:";
        cin >> rateOfPay;

        cout << "Enter amount of overtime hours:";
        cin >> overTimeHours;

        cout << endl;

    }
};

void enterData(Employee array [], int size){
    for (int i = 0; i < size; i++){ // loop as long as # of iterations is less than size
        cout << "Employee " << i + 1  << endl; //print employee @ i + 1 for readability
        array[i].getData(); //call getData function on employee i
    }
}

void PrintEmployeeArray(Employee array[], int size){ //format the fields of each employee in employee array along with the addresses for each field and total compensation.
    for(int i = 0; i < size; i++){
        //align to left, with each columnSize being 23. setprecision will decide how precise a double will be.
        cout << setw(columnSize) << left << array[i].employeeName;
        cout << setw(columnSize) << left << setprecision(6) << array[i].compensation();
        cout << setw(columnSize) << left << setprecision(4) << array[i].rateOfPay;
        cout << setw(columnSize) << left << setprecision(4) << array[i].hoursWorked;
        cout << setw(columnSize) << left << setprecision(4) << array[i].overTimeHours << endl;
        array[i].printAddress(); // call printAddress function. this prints the pointers in the Employee class to console.
        cout << endl;
    }
}


int main() { //main method
    int n;
    cout << "Enter number of employees:";
    cin >> n; //set n to user input. this will hold the size of the array
    Employee employees[n]; //create an array of employees of size n

    enterData(employees, n); //call enterData function which calls getData function.

    //generate the first row of columns
    cout << setw(columnSize) << left << "Employee Name";
    cout << setw(columnSize) << left << "Total Compensation";
    cout << setw(columnSize) << left << "Rate of Pay";
    cout << setw(columnSize) << left << "Hours Worked";
    cout << setw(columnSize) << left << "Overtime Hours" << endl;

    PrintEmployeeArray(employees, n); // call PrintEmployeeArray Function

    //delete all the pointers for each element in employees array.
    for(int i = 0; i < n; i++) {
        delete employees[i].pHoursWorked;
        delete employees[i].pOvertimeHours;
        delete employees[i].pRateOfPay;
    }
}

