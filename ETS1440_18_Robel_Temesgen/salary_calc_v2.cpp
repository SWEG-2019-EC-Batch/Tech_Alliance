/*
Exercise 32 - Salary Calculator (Version 2)

This program calculates the salary of both employees and laborers.

Employees:
- Work 40 hours per week.
- Get bonus payment for extra hours.
- Have tax and pension deductions.

Laborers:
- Are paid according to the hours they work.
- Can receive a bonus.
- Can have a penalty if they damage machinery.
- Do not have tax or pension deductions.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int worker_type, choice;
    int worked_hrs;
    const int EXPECTED_HR = 40;

    float base_salary, bonus_rate, bonus_payment;
    float gross_salary, tax_deducted, pension, net_salary;
    float hourly_rate, damage_penalty;
    float total_deductions;

    string deducted_or_bonus;

    // Initialize the amounts before doing the calculations
    bonus_payment = 0;
    tax_deducted = 0;
    pension = 0;
    damage_penalty = 0;
    net_salary = 0;
    gross_salary = 0;

    cout << "========== Salary Calculator ==========" << endl;
    cout << "1. Employee" << endl;
    cout << "2. Laborer" << endl;
    cout << "Choose worker type: ";
    cin >> worker_type;

    if (worker_type == 1)
    {
        cout << "\nEnter the base salary: ";
        cin >> base_salary;

        cout << "Enter the worked hours: ";
        cin >> worked_hrs;

        if (worked_hrs >= EXPECTED_HR)
        {
            cout << "Enter the bonus rate: ";
            cin >> bonus_rate;

            bonus_payment = (worked_hrs - EXPECTED_HR) * bonus_rate;
        }
        else
        {
            // Deduct salary when the employee works less than 40 hours
            bonus_payment = -1 * (EXPECTED_HR - worked_hrs) * (base_salary / EXPECTED_HR);
        }

        if (worked_hrs >= EXPECTED_HR)
            deducted_or_bonus = "bonus";
        else
            deducted_or_bonus = "deducted";

        gross_salary = base_salary + bonus_payment;

        // Calculate tax based on the gross salary
        if (gross_salary >= 0 && gross_salary <= 3500)
        {
            tax_deducted = 0;
        }
        else if (gross_salary <= 10000)
        {
            tax_deducted = gross_salary * 0.10;
        }
        else if (gross_salary <= 25000)
        {
            tax_deducted = gross_salary * 0.15;
        }
        else if (gross_salary <= 50000)
        {
            tax_deducted = gross_salary * 0.20;
        }
        else if (gross_salary <= 100000)
        {
            tax_deducted = gross_salary * 0.25;
        }
        else
        {
            tax_deducted = gross_salary * 0.30;
        }

        pension = gross_salary * 0.07;

        total_deductions = tax_deducted + pension;
        net_salary = gross_salary - total_deductions;

        cout << fixed << setprecision(2);
        cout << "\nChoose which item to display" << endl;
        cout << "1. Bonus payment / salary deducted" << endl;
        cout << "2. Tax deducted" << endl;
        cout << "3. Pension" << endl;
        cout << "4. Gross salary" << endl;
        cout << "5. Net salary" << endl;
        cout << "6. All" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "The " << deducted_or_bonus << " payment is: " << bonus_payment << " birr." << endl;
            break;

        case 2:
            cout << "The tax deducted is: " << tax_deducted << " birr." << endl;
            break;

        case 3:
            cout << "The pension deducted is: " << pension << " birr." << endl;
            break;

        case 4:
            cout << "The gross salary is: " << gross_salary << " birr." << endl;
            break;

        case 5:
            cout << "The net salary is: " << net_salary << " birr." << endl;
            break;

        case 6:
            cout << "The " << deducted_or_bonus << " payment is: " << bonus_payment << " birr." << endl;
            cout << "The tax deducted is: " << tax_deducted << " birr." << endl;
            cout << "The pension deducted is: " << pension << " birr." << endl;
            cout << "The gross salary is: " << gross_salary << " birr." << endl;
            cout << "The net salary is: " << net_salary << " birr." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    }
    else if (worker_type == 2)
    {
        cout << "\nEnter the number of hours worked: ";
        cin >> worked_hrs;

        cout << "Enter the hourly rate: ";
        cin >> hourly_rate;

        // A laborer may or may not have a bonus
        int has_bonus;
        cout << "Does the laborer have a bonus? (1 = Yes, 0 = No): ";
        cin >> has_bonus;

        if (has_bonus == 1)
        {
            cout << "Enter the bonus amount: ";
            cin >> bonus_payment;
        }

        // Check if any machinery was damaged
        int damaged_machine;
        cout << "Did the laborer damage any machinery? (1 = Yes, 0 = No): ";
        cin >> damaged_machine;

        if (damaged_machine == 1)
        {
            cout << "Enter the salary penalty amount: ";
            cin >> damage_penalty;
        }

        float basic_pay = worked_hrs * hourly_rate;
        gross_salary = basic_pay + bonus_payment;

        // Laborers do not pay tax or pension
        tax_deducted = 0;
        pension = 0;

        total_deductions = damage_penalty + tax_deducted + pension;
        net_salary = gross_salary - total_deductions;

        cout << fixed << setprecision(2);
        cout << "\nChoose which item to display" << endl;
        cout << "1. Bonus payment" << endl;
        cout << "2. Machinery damage penalty" << endl;
        cout << "3. Gross salary" << endl;
        cout << "4. Net salary" << endl;
        cout << "5. All" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "The bonus payment is: " << bonus_payment << " birr." << endl;
            break;

        case 2:
            cout << "The machinery damage penalty is: " << damage_penalty << " birr." << endl;
            break;

        case 3:
            cout << "The gross salary is: " << gross_salary << " birr." << endl;
            break;

        case 4:
            cout << "The net salary is: " << net_salary << " birr." << endl;
            break;

        case 5:
            cout << "The worked hours are: " << worked_hrs << " hours." << endl;
            cout << "The hourly rate is: " << hourly_rate << " birr." << endl;
            cout << "The basic pay is: " << basic_pay << " birr." << endl;
            cout << "The bonus payment is: " << bonus_payment << " birr." << endl;
            cout << "The machinery damage penalty is: " << damage_penalty << " birr." << endl;
            cout << "Tax deducted: " << tax_deducted << " birr." << endl;
            cout << "Pension deducted: " << pension << " birr." << endl;
            cout << "The gross salary is: " << gross_salary << " birr." << endl;
            cout << "The net salary is: " << net_salary << " birr." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    }
    else
    {
        cout << "Invalid worker type." << endl;
    }

    return 0;
}
