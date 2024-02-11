#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

class Employee {
private:
    string employeeName;
    string jobTitle;
    double hourlyWage;

public:
    Employee(string name, string title, double wage)
        : employeeName(name), jobTitle(title), hourlyWage(wage) {}

    string getEmployeeName() const {
        return employeeName;
    }

    string getJobTitle() const {
        return jobTitle;
    }

    double getHourlyWage() const {
        return hourlyWage;
    }

    void setHourlyWage(double wage) {
        if (wage >= 0) {
            hourlyWage = wage;
        } else {
            cout << "Invalid hourly wage. Please enter a non-negative value." << endl;
        }
    }
};

// Function to print the list of employees
void printEmployeeList(const vector<Employee>& employees) {
    cout << "\nEmployee List:\n";
    for (const auto& employee : employees) {
        cout << "Name: " << employee.getEmployeeName() << " | Job Title: " << employee.getJobTitle()
                  << " | Hourly Wage: $" << fixed << setprecision(2) << employee.getHourlyWage() << endl;
    }
}

// Function to calculate total wages
void calculateTotalWages(const vector<Employee>& employees) {
    double totalWages = 0.0;

    for (const auto& employee : employees) {
        double hoursWorked;

        cout << "Enter total hours worked for " << employee.getEmployeeName() << ": ";
        while (!(cin >> hoursWorked) || hoursWorked < 0) {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        totalWages += hoursWorked * employee.getHourlyWage();
    }

    cout << "\nTotal Wages for the week: $" << fixed << setprecision(2) << totalWages << endl;
}

int main() {
    vector<Employee> employees = {
        {"John Doe", "Software Engineer", 25.50},
        {"Jane Smith", "Marketing Specialist", 20.75},
        {"Bob Johnson", "Sales Associate", 18.00},
        {"Alice Brown", "Customer Service Representative", 15.25},
        {"Charlie Davis", "Manager", 30.00}
    };

    while (true) {
        cout << "Employee Management System" << endl;
        cout << "1. Print list of employees" << endl;
        cout << "2. Calculate total wages" << endl;
        cout << "3. Exit application" << endl;
        cout << "Enter your choice (1-3): " << endl;

        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid input. Please enter a number between 1 and 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                printEmployeeList(employees);
                break;
            case 2:
                calculateTotalWages(employees);
                break;
            case 3:
                cout << "Exiting the application. Goodbye!\n";
                return 0;
        }
    }
    return 0;
}
