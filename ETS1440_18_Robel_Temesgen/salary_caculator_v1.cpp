/*
Exercise 32 - salary calculator
   Design and develop a program that use to calcualte salary of an employee
   The programm will ask the user to input the base salary and  the number of hours worked in a week
   An employee is expected to work for 40 hrs per week.
   If the worker hours exceed the expectd working hr the employee is entitled for bonus payment
   The bonus rate should be input from the user
   The program is expected calculate gross salary, bonus payment, tax deduction, and net salary.
   The program also deduct 7% of the gross salary as pension.
   The tax is calculated from gross salary as follow:
        from 0-3500 is free
        from 3500-10,000 included is 10%
        from 10,000-25,000 included is 15%
        from 25,000- 50,000 included is 20%
        from 50,000-100,000 included is 25%
        above 100,000 is 30%

    both pension and tax are applied on gross salary
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    float base_salary, bonus_rate, bonus_payment, gross_salary, tax_deducted, pension, net_salary;
    int worked_hrs, choice;
    string deducted_or_bonus;

    const int EXPECTED_HR = 40;

    cout << "Enter the base salary: ";
    cin >> base_salary;
    cout << "Enter the worked hrs: ";
    cin >> worked_hrs;

    bonus_payment = 0;
    if (worked_hrs >= EXPECTED_HR)
    {
        cout << "Enter the bonus rate: ";
        cin >> bonus_rate;
        bonus_payment = (worked_hrs - EXPECTED_HR) * bonus_rate;
    }
    else{
        bonus_payment = -1 * (EXPECTED_HR - worked_hrs) * (base_salary/EXPECTED_HR);
    }
    deducted_or_bonus = worked_hrs >= 40 ? "bonus" : "deducted";
    gross_salary = base_salary + bonus_payment;

    if (gross_salary >= 0 && gross_salary <= 3500)
    {
        tax_deducted = 0;
    }
    else if (gross_salary <= 10000)
    {
        tax_deducted = gross_salary * 0.1;
    }
    else if (gross_salary <= 25000)
    {
        tax_deducted = gross_salary * 0.15;
    }
    else if (gross_salary <= 50000)
    {
        tax_deducted = gross_salary * 0.2;
    }
    else if (gross_salary <= 100000)
    {
        tax_deducted = gross_salary * 0.25;
    }
    else if (gross_salary > 100000)
    {
        tax_deducted = gross_salary * 0.3;
    }

    pension = gross_salary * 0.07;

    net_salary = gross_salary - (tax_deducted + pension);

    cout << fixed << setprecision(2);
    cout << "Chosse which item to display" << endl;
    cout << "1. bonus payment" << endl
         << "2. tax deducted" << endl
         << "3. pension" << endl
         << "4. gross salary" << endl
         << "5. net salary" << endl
         << "6. all" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "The "<<deducted_or_bonus<< " payment is: " << bonus_payment << " birr." << endl;
        break;

    case 2:
        cout << "The tax deducted is: " << tax_deducted << " birr." << endl;
        break;

    case 3:
        cout << "The pension deducted is: " << pension << " birr." << endl;
        break;

    case 4:
        cout << "The gross salary is: " << gross_salary << " birr:" << endl;
        break;

    case 5:
        cout << "The net salary is: " << net_salary << " birr " << endl;
        break;

    case 6:
        cout << "The "<<deducted_or_bonus<< " payment is: " << bonus_payment << " birr." << endl;
        cout << "The tax deducted is: " << tax_deducted << " birr." << endl;
        cout << "The pension deducted is: " << pension << " birr." << endl;
        cout << "The gross salary is: " << gross_salary << " birr:" << endl;
        cout << "The net salary is: " << net_salary << " birr " << endl;
        break;

    default:
        cout << "Invalid choice:";
    }

}
