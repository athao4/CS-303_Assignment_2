// A Chao Thao
// CS-303 Assignment Part 2
// 03/06/2023

#include <iostream>
using namespace std;
#include "Employee.h"

int main()
{
    // create a professional employee with hourly rate of $50 and 10 vacation days
    Professional profEmp(50.0, 10);

    // calculate and print the weekly salary
    cout << "Professional employee weekly salary: $" << profEmp.calculateWeeklySalary() << endl;

    // calculate and print the health care contributions
    cout << "Professional employee health care contributions: $"
        << profEmp.calculateHealthCareContributions() << endl;

    // calculate and print the vacation days
    cout << "Professional employee vacation days: " << profEmp.calculateVacationDays() << endl;
    cout << endl;

    //--------------------------------------------------------------

    // create a nonprofessional employee with hourly rate of $20 and 80 vacation hours
    Nonprofessional nonProfEmp(20.0, 80);

    // calculate and print the weekly salary
    cout << "Nonprofessional employee weekly salary: $"
        << nonProfEmp.calculateWeeklySalary() << endl;

    // calculate and print the health care contributions
    cout << "Nonprofessional employee health care contributions: $"
        << nonProfEmp.calculateHealthCareContributions() << endl;

    // calculate and print the vacation days
    cout << "Nonprofessional employee vacation days: " << nonProfEmp.calculateVacationDays()
        << endl;

    return 0;

}
