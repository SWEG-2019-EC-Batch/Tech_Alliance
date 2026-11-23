/*
IPO (Input-Process-Output)

1. Input and Output

a. Input
   - base_salary: the salary
   - work_hours: hours worked per week
   - bonus_rate: pay per overtime hour
   - choice: the menu option (1-7)

   Constants: pension_rate = 0.07, threshold_hr = 40

b. Output
   Depending on the menu choice:
   1. Bonus
   2. Penalty
   3. Pension
   4. Tax
   5. Gross salary
   6. Net salary
   7. All of the above
   - Any other number: "Invalid choice!! Please enter between 1-7"

2. Process

   1. Read the salary, weekly work hours, and bonus rate.
   2. If work_hours < 40:
      - penalty = (40 - work_hours) x base_salary / 40
      - gross_salary = base_salary - penalty
   3. Otherwise:
      - bonus = (work_hours - 40) x bonus_rate
      - gross_salary = base_salary + bonus
   4. Find the tax rate from the gross salary:
      - 0 to 3,500: 0%
      - 3,501 to 10,000: 10%
      - 10,001 to 25,000: 15%
      - 25,001 to 50,000: 20%
      - 50,001 to 100,000: 25%
      - Above 100,000: 30%
   5. Calculate pension = gross_salary x 0.07.
   6. Calculate tax = gross_salary x tax_rate.
   7. Calculate net_salary = gross_salary - pension - tax.
   8. Display the menu, read choice, and use a switch to select what to show.
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    // Declare variables
    float base_salary;
    float work_hours;
    float bonus_rate;
    int choice;
    float tax = 0;
    float tax_rate = 0;
    float gross_salary = 0;
    float net_salary = 0;
    float bonus = 0;
    float penalty = 0;
    float pension;

    // Define constants
    const float pension_rate = 0.07;
    const int threshold_hr = 40;

    // Read Salary, Work hr and Bonus rate
    cout << "How much is your salary?: ";
    cin >> base_salary;
    cout << "How much is your work hours in a week?: ";
    cin >> work_hours;
    cout << "How much is your bonus rate?: ";
    cin >> bonus_rate;

    // Bonus and Penalty
    if (work_hours < threshold_hr) {
        penalty = (threshold_hr - work_hours) * base_salary / threshold_hr;
        gross_salary = base_salary - penalty;
    }

    else {
        bonus = (work_hours - threshold_hr) * bonus_rate;
        gross_salary = base_salary + bonus;
    }

    // tax
    if (gross_salary >= 0 && gross_salary <= 3500) {
        tax_rate = 0;
    }
    else if (gross_salary > 3500 && gross_salary <= 10000) {
        tax_rate = 0.1;
    }
    else  if (gross_salary > 10000 && gross_salary <= 25000) {
        tax_rate = 0.15;
    }
    else  if (gross_salary > 25000 && gross_salary <= 50000) {
        tax_rate = 0.2;
    }
    else if (gross_salary > 50000 && gross_salary <= 100000) {
        tax_rate = 0.25;
    }
    else {
        tax_rate = 0.3;
    }

    // Calculate Pension tax and Net Salary
    pension = gross_salary * pension_rate;
    tax = gross_salary * tax_rate;
    net_salary = gross_salary - (pension) - (tax);

    cout << fixed<< setprecision(2);
    cout << "\n"<<"Choose what you want to see\n";
    cout << "1. Bonus\n";
    cout << "2. Penalty\n";
    cout << "3. Pension\n";
    cout << "4. Tax\n";
    cout << "5. Gross Salary\n";
    cout << "6. Net Salary\n";
    cout << "7. For All\n\n";
    cout << "Enter the number of you want to see (1-7): ";

    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\n"<< "selected: Bonus: " << bonus;
        break;

    case 2:
        cout << "\n"<<"selected: Penalty: " << penalty;
        break;

    case 3:
        cout << "\n"<<"selected: Pension: " << pension;
        break;

    case 4:
        cout << "\n"<<"selected: Tax: " << tax;
        break;

    case 5:
        cout << "\n"<<"selected: Gross salary " << gross_salary;
        break;

    case 6:
        cout << "\n"<<"selected: Net salary: " << net_salary;
        break;

    case 7:
        cout << "\n"<<"selected: For All" << "\n";
        cout << "1. Bonus: "<< bonus<< "\n";
        cout << "2. Penalty: "<< penalty<< "\n";
        cout << "3. Pension: "<< pension<< "\n";
        cout << "4. Tax: "<< tax<< "\n";
        cout << "5. Gross Salary: "<< gross_salary<< "\n";
        cout << "6. Net Salary: "<< net_salary<< endl;
        break;

    default:
        cout << "Invalid choice!! Please enter between 1-7" << endl;
        break;
    }

    return 0;
}
