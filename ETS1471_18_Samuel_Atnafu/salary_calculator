#include <iostream>
using namespace std;

int main() {
    double gross_salary, net_salary, base_salary;
    double pension = 0.07;
    double work_hours, ot_rate, ot = 0;
    double tax = 0;
    double overtime = 0;
    double deduction = 0;
    int score;

    cout << "how many hours did you work this week ";
    cin >> work_hours;

    cout << "what is your base salary ";
    cin >> base_salary;

    if (work_hours < 40) {
        // missed hours are deducted from the base salary
        deduction = base_salary / 40 * (40 - work_hours);
        gross_salary = base_salary - deduction;
    }
    else {
        ot = work_hours - 40;
        cout << "what is the overtime payment per hour ";
        cin >> ot_rate;
        overtime = ot_rate * ot;
        gross_salary = base_salary + overtime;
    }

    if (gross_salary <= 3500) {
        tax = 0;
    }
    else if (gross_salary <= 10000) {
        tax = gross_salary * 0.1;
    }
    else if (gross_salary <= 25000) {
        tax = gross_salary * 0.15;
    }
    else if (gross_salary <= 50000) {
        tax = gross_salary * 0.2;
    }
    else if (gross_salary <= 100000) {
        tax = gross_salary * 0.25;
    }
    else {
        tax = gross_salary * 0.3;
    }

    net_salary = gross_salary - tax - (gross_salary * pension);

    // menu page
    cout << endl;
    cout << "=============================" << endl;
    cout << "   WHAT DO YOU WANT TO SEE?  " << endl;
    cout << "=============================" << endl;
    cout << "  Press 1 to see Tax" << endl;
    cout << "  Press 2 to see Pension" << endl;
    cout << "  Press 3 to see Overtime / Deduction" << endl;
    cout << "  Press 4 to see Gross Salary" << endl;
    cout << "  Press 5 to see Net Salary" << endl;
    cout << "  Press 6 to see Everything" << endl;
    cout << "=============================" << endl;
    cout << "Your choice: ";
    cin >> score;
    cout << endl;

    switch (score) {
        case 1:
            cout << "tax= " << tax << endl;
            break;
        case 2:
            cout << "pension= 7%" << endl;
            break;
        case 3:
            if (overtime > 0)
                cout << "overtime= " << overtime << endl;
            else if (deduction > 0)
                cout << "deduction= " << deduction << endl;
            else
                cout << "no overtime or deduction" << endl;
            break;
        case 4:
            cout << "gross salary: " << gross_salary << endl;
            break;
        case 5:
            cout << "your net salary is " << gross_salary << "-" << tax << "-("
                 << gross_salary << "*7%)= " << net_salary << " birr" << endl;
            break;
        case 6:
            cout << "tax= " << tax << endl;
            cout << "pension= 7%" << endl;
            cout << "gross salary= " << gross_salary << endl;
            cout << "your net salary is " << gross_salary << "-" << tax << "-("
                 << gross_salary << "*7%)= " << net_salary << " birr" << endl;
            break;
        default:
            cout << "invalid input" << endl;
    }

    return 0;
}
