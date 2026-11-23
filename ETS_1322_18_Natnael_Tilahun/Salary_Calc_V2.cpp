/*COMMON TO BOTH WORKER TYPES

Input
- Worker type (1 = Employee, 2 = Laborer)
- Output choice (1-7), entered after the calculation

Output
- An error message if the worker type is invalid
- The chosen result, or an error message if the choice is not 1-7

Process
- Check the worker type and go to the matching section. Any other value ends the program.
- After calculating, display the result that matches the output choice.


EMPLOYEE (WORKER TYPE 1)

Input
- Monthly base salary
- Hours worked this week
- Overtime bonus rate per extra hour

Output
- Gross salary
- Bonus payment
- Penalty
- Tax deduction
- Pension
- Net salary

Process
1. If hours worked are more than 40: bonus = (hours - 40) x overtime rate.
2. If hours worked are less than 40: penalty = (40 - hours) x (base salary / 40).
3. Gross salary = base salary + bonus - penalty.
4. Find the tax rate from the gross salary:
   - up to 3,500: 0%
   - up to 10,000: 10%
   - up to 25,000: 15%
   - up to 50,000: 20%
   - up to 100,000: 25%
   - above 100,000: 30%
5. Tax = gross salary x tax rate.
6. Pension = gross salary x 7%.
7. Net salary = gross salary - pension - tax.


LABORER (WORKER TYPE 2)

Input
- Hours worked
- Hourly rate
- Whether machinery was damaged (1 = Yes, 0 = No)
- If damaged: the penalty amount
- If not damaged: whether there is a bonus (1 = Yes, 0 = No), and the bonus amount if yes

Output
- Gross salary
- Bonus payment
- Penalty
- Tax deduction (always 0)
- Pension (always 0)
- Net salary

Process
1. If machinery was damaged, read the penalty amount. No bonus is asked about.
2. If not damaged, ask about a bonus and read the amount if there is one.
3. Gross salary = hours x hourly rate + bonus.
4. Tax and pension are always 0 for laborers.
5. Net salary = gross salary - penalty.


OUTPUT MENU

Input
- A choice from 1 to 7

Output
- 1: full summary of all values
- 2: gross salary
- 3: pension contribution
- 4: bonus payment
- 5: tax deduction
- 6: penalty
- 7: net salary

Process
- Select the result that matches the choice and display it.

*/

#include <iostream>
using namespace std;

int main()
{
    const double PENSION_RATE = 0.07;
    const int STANDARD_WEEKLY_HOURS = 40;

    int workerType;
    int outputChoice;
    double hoursWorked;
    double grossSalary;
    double bonusAmount = 0.0;
    double penaltyAmount = 0.0;
    double taxAmount = 0.0;
    double pensionAmount = 0.0;
    double netSalary;

    cout << "Select worker type:" << endl;
    cout << "  1. Employee" << endl;
    cout << "  2. Laborer" << endl;
    cout << "Enter 1 or 2: ";
    cin >> workerType;

    if (workerType == 1)
    {
        double baseSalary, overtimeRatePerHour, taxRate;

        cout << "Enter the monthly base salary: ";
        cin >> baseSalary;
        cout << "Enter the hours worked this week: ";
        cin >> hoursWorked;
        cout << "Enter the overtime bonus rate per extra hour: ";
        cin >> overtimeRatePerHour;

        if (hoursWorked > STANDARD_WEEKLY_HOURS)
        {
            bonusAmount = (hoursWorked - STANDARD_WEEKLY_HOURS) * overtimeRatePerHour;
        }
        else if (hoursWorked < STANDARD_WEEKLY_HOURS)
        {
            penaltyAmount = (STANDARD_WEEKLY_HOURS - hoursWorked) * (baseSalary / STANDARD_WEEKLY_HOURS);
        }

        grossSalary = baseSalary + bonusAmount - penaltyAmount;

        if (grossSalary <= 3500)       taxRate = 0.0;
        else if (grossSalary <= 10000) taxRate = 0.10;
        else if (grossSalary <= 25000) taxRate = 0.15;
        else if (grossSalary <= 50000) taxRate = 0.20;
        else if (grossSalary <= 100000) taxRate = 0.25;
        else                           taxRate = 0.30;

        taxAmount = grossSalary * taxRate;
        pensionAmount = grossSalary * PENSION_RATE;
        netSalary = grossSalary - pensionAmount - taxAmount;
    }
    else if (workerType == 2)
    {
        double hourlyRate;
        int damagedMachinery;

        cout << "Enter the hours worked: ";
        cin >> hoursWorked;
        cout << "Enter the hourly rate: ";
        cin >> hourlyRate;
        cout << "Did the laborer damage any machinery? (1 = Yes, 0 = No): ";
        cin >> damagedMachinery;

        if (damagedMachinery == 1)
        {
            cout << "Enter the penalty amount: ";
            cin >> penaltyAmount;
        }
        else
        {
            int receivesBonus;
            cout << "Is the laborer receiving a bonus? (1 = Yes, 0 = No): ";
            cin >> receivesBonus;

            if (receivesBonus == 1)
            {
                cout << "Enter the bonus amount: ";
                cin >> bonusAmount;
            }
        }

        grossSalary = hoursWorked * hourlyRate + bonusAmount;
        netSalary = grossSalary - penaltyAmount;
    }
    else
    {
        cout << "Invalid worker type. Please run the program again and enter 1 or 2." << endl;
        return 0;
    }

    cout << "\nWhat would you like to see?" << endl;
    cout << "  1. Full salary summary" << endl;
    cout << "  2. Gross salary" << endl;
    cout << "  3. Pension contribution" << endl;
    cout << "  4. Bonus payment" << endl;
    cout << "  5. Tax deduction" << endl;
    cout << "  6. Penalty" << endl;
    cout << "  7. Net salary" << endl;
    cout << "Enter your choice (1-7): ";
    cin >> outputChoice;

    switch (outputChoice)
    {
    case 1:
        cout << "\n--- Salary Summary ---" << endl;
        cout << "Gross salary:   " << grossSalary << endl;
        cout << "Bonus payment:  " << bonusAmount << endl;
        cout << "Penalty:        " << penaltyAmount << endl;
        cout << "Tax deduction:  " << taxAmount << endl;
        cout << "Pension:        " << pensionAmount << endl;
        cout << "Net salary:     " << netSalary << endl;
        break;
    case 2:
        cout << "Your gross salary is: " << grossSalary << endl;
        break;
    case 3:
        cout << "Your pension contribution is: " << pensionAmount << endl;
        break;
    case 4:
        cout << "Your bonus payment is: " << bonusAmount << endl;
        break;
    case 5:
        cout << "Your tax deduction is: " << taxAmount << endl;
        break;
    case 6:
        cout << "Your penalty is: " << penaltyAmount << endl;
        break;
    case 7:
        cout << "Your net salary is: " << netSalary << endl;
        break;
    default:
        cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        break;
    }

    return 0;
}
