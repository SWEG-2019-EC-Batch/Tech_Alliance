#include <iostream>
using namespace std;

int main() {
    // ---------- Constants ----------
    const double PENSION_RATE = 0.07;
    const double STANDARD_HOURS = 40;

    // ---------- Common variables ----------
    int worker_type, choice;
    double work_hours;
    double gross_salary, net_salary;

    // ---------- Employee variables ----------
    double base_salary = 0, ot_rate, extra = 0;   // extra: overtime (+) or absence deduction (-)
    double tax_rate = 0, tax = 0, pension = 0;

    // ---------- Laborer variables ----------
    double hourly_rate = 0, hours_pay = 0;
    double bonus = 0, penalty = 0;
    char has_bonus, has_damage;

    // ---------- Worker type ----------
    cout << "=============================" << endl;
    cout << "      SALARY CALCULATOR      " << endl;
    cout << "=============================" << endl;
    do {
        cout << "Are you an:\n  1. Employee\n  2. Laborer\nYour choice: ";
        cin >> worker_type;
        if (worker_type != 1 && worker_type != 2)
            cout << "Invalid choice, try again.\n\n";
    } while (worker_type != 1 && worker_type != 2);

    cout << endl;
    cout << "How many hours did you work this week? ";
    cin >> work_hours;

    if (worker_type == 1) {
        // ======================= EMPLOYEE =======================
        cout << "What is your base salary? ";
        cin >> base_salary;

        if (work_hours < STANDARD_HOURS) {
            extra = -base_salary / STANDARD_HOURS * (STANDARD_HOURS - work_hours);
        } else if (work_hours > STANDARD_HOURS) {
            cout << "What is the overtime payment per hour? ";
            cin >> ot_rate;
            extra = ot_rate * (work_hours - STANDARD_HOURS);
        }

        gross_salary = base_salary + extra;

        if (gross_salary <= 3500)        tax_rate = 0;
        else if (gross_salary <= 10000)  tax_rate = 0.10;
        else if (gross_salary <= 25000)  tax_rate = 0.15;
        else if (gross_salary <= 50000)  tax_rate = 0.20;
        else if (gross_salary <= 100000) tax_rate = 0.25;
        else                             tax_rate = 0.30;

        tax = gross_salary * tax_rate;
        pension = gross_salary * PENSION_RATE;
        net_salary = gross_salary - tax - pension;
    }
    else {
        // ======================= LABORER =======================
        cout << "What is your hourly rate? ";
        cin >> hourly_rate;
        hours_pay = work_hours * hourly_rate;

        cout << "Do you have a bonus? (y/n): ";
        cin >> has_bonus;
        if (has_bonus == 'y' || has_bonus == 'Y') {
            cout << "Bonus amount: ";
            cin >> bonus;
        }

        cout << "Did you damage any machinery? (y/n): ";
        cin >> has_damage;
        if (has_damage == 'y' || has_damage == 'Y') {
            cout << "Penalty amount: ";
            cin >> penalty;
        }

        gross_salary = hours_pay + bonus;
        net_salary = gross_salary - penalty;       // no tax or pension for laborers
        if (net_salary < 0) net_salary = 0;        // salary can't go below zero
    }

    // ---------- Menu ----------
    do {
        cout << "\n=============================" << endl;
        cout << "   WHAT DO YOU WANT TO SEE?  " << endl;
        cout << "=============================" << endl;
        if (worker_type == 1) {
            cout << "  Press 1 to see Tax\n"
                    "  Press 2 to see Pension\n"
                    "  Press 3 to see Overtime / Deduction\n";
        } else {
            cout << "  Press 1 to see Pay for hours worked\n"
                    "  Press 2 to see Bonus\n"
                    "  Press 3 to see Machinery penalty\n";
        }
        cout << "  Press 4 to see Gross Salary\n"
                "  Press 5 to see Net Salary\n"
                "  Press 6 to see Everything\n"
                "  Press 0 to Exit\n"
                "=============================\n"
                "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                if (worker_type == 1)
                    cout << "Tax (" << tax_rate * 100 << "%): " << tax << " birr" << endl;
                else
                    cout << "Pay for hours: " << work_hours << " hrs x " << hourly_rate
                         << " = " << hours_pay << " birr" << endl;
                break;
            case 2:
                if (worker_type == 1)
                    cout << "Pension (" << PENSION_RATE * 100 << "%): " << pension << " birr" << endl;
                else
                    cout << "Bonus: " << bonus << " birr" << endl;
                break;
            case 3:
                if (worker_type == 1) {
                    if (extra > 0)      cout << "Overtime: " << extra << " birr" << endl;
                    else if (extra < 0) cout << "Deduction for missed hours: " << -extra << " birr" << endl;
                    else                cout << "No overtime or deduction" << endl;
                } else {
                    cout << "Machinery penalty: " << penalty << " birr" << endl;
                }
                break;
            case 4:
                cout << "Gross salary: " << gross_salary << " birr" << endl;
                break;
            case 5:
                if (worker_type == 1)
                    cout << "Net salary = " << gross_salary << " - " << tax << " - "
                         << pension << " = " << net_salary << " birr" << endl;
                else
                    cout << "Net salary = " << gross_salary << " - " << penalty
                         << " = " << net_salary << " birr" << endl;
                break;
            case 6:
                cout << "---------- PAYSLIP ----------" << endl;
                if (worker_type == 1) {
                    cout << "Base salary:\t" << base_salary << " birr" << endl;
                    if (extra >= 0) cout << "Overtime:\t+" << extra << " birr" << endl;
                    else            cout << "Deduction:\t" << extra << " birr" << endl;
                    cout << "Gross salary:\t" << gross_salary << " birr" << endl;
                    cout << "Tax (" << tax_rate * 100 << "%):\t-" << tax << " birr" << endl;
                    cout << "Pension (" << PENSION_RATE * 100 << "%):\t-" << pension << " birr" << endl;
                } else {
                    cout << "Hours worked:\t" << work_hours << " hrs" << endl;
                    cout << "Hourly rate:\t" << hourly_rate << " birr" << endl;
                    cout << "Pay for hours:\t" << hours_pay << " birr" << endl;
                    cout << "Bonus:\t\t+" << bonus << " birr" << endl;
                    cout << "Gross salary:\t" << gross_salary << " birr" << endl;
                    cout << "Penalty:\t-" << penalty << " birr" << endl;
                    cout << "(no tax or pension)" << endl;
                }
                cout << "Net salary:\t" << net_salary << " birr" << endl;
                cout << "-----------------------------" << endl;
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
