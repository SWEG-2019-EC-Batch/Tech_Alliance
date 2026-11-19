#include <iostream>
using namespace std;

int main() {
    int salary, hours, bonusRate;
    float pension, gross, tax, net;
    int bonus = 0;
    int extraHours = 0;

    // get the inputs
    cout << "Enter base salary: ";
    cin >> salary;
    cout << "Enter weekly worked hours (40 or more): ";
    cin >> hours;
    cout << "Enter bonus rate (ETB per hour): ";
    cin >> bonusRate;

    // overtime or missing hours
    if (hours > 40) {
        extraHours = hours - 40;
    }
    else if (hours < 40) {
        // paid only for the hours worked
        salary = salary * hours / 40;
    }

    bonus = bonusRate * extraHours;
    gross = salary + bonus;

    // pension is 7% of gross
    pension = gross * 0.07;

    // tax brackets
    if (gross <= 3500) {
        tax = 0;
    }
    else if (gross <= 10000) {
        tax = gross * 0.10;
    }
    else if (gross <= 25000) {
        tax = gross * 0.15;
    }
    else if (gross <= 50000) {
        tax = gross * 0.20;
    }
    else if (gross <= 100000) {
        tax = gross * 0.25;
    }
    else {
        tax = gross * 0.30;
    }

    net = gross - pension - tax;

    // menu
    int choice;
    cout << "\nWhat do you want to see?" << endl;
    cout << "1 - Everything" << endl;
    cout << "2 - Bonus payment" << endl;
    cout << "3 - Pension" << endl;
    cout << "4 - Net salary" << endl;
    cout << "5 - Gross salary" << endl;
    cout << "6 - Tax" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nGross salary: birr " << gross << endl;
            cout << "Bonus payment: birr " << bonus << endl;
            cout << "Tax: birr " << tax << endl;
            cout << "Pension: birr " << pension << endl;
            cout << "Net salary: birr " << net << endl;
            break;
        case 2:
            cout << "Bonus payment: birr " << bonus << endl;
            break;
        case 3:
            cout << "Pension: birr " << pension << endl;
            break;
        case 4:
            cout << "Net salary: birr " << net << endl;
            break;
        case 5:
            cout << "Gross salary: birr " << gross << endl;
            break;
        case 6:
            cout << "Tax: birr " << tax << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}
