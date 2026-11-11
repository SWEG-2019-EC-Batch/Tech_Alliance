/*
a) i. Inputs
    - units – Number of electricity units used (whole number).
    
   ii. Outpits
    -EnergyCharge – Cost of electricity consumed.
    -ServiceCharge – Fixed service charge (10 birr).
    -TotalBill – Total amount to be paid.

b) Process    
   1. Start the program
   2. Declare an integer variable units to store the electricity units.
   3. Declare constants for the first 50 units' rate (1.50 birr), the additional units' rate (2.00 birr), and the service charge (10 birr).
   4. Read the number of electricity units from the user.
   5. Calculate the energy charge using the conditional operator:
      -If units are less than or equal to 50, multiply units by 1.50.
      -Otherwise, calculate the cost of the first 50 units and add the cost of the remaining units at 2.00 birr each.
    6. Add the service charge to the energy charge to calculate the total bill.
    7. Print the energy charge, service charge, and total bill with two decimal places.
    8. End the program.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    // Declare the variables
    int units;
    double EnergyCharge, TotalBill;

    // Define the constants
    const double FirstFifty = 1.50;
    const double AboveFifty = 2.00;
    const double FixedCharge = 10.00;
    const int Threshold = 50;

    // Read the electricity units in KWh
    cout << "Enter the amount used (KWh): ";
    cin >> units;

    // Calculate the energy charge
    EnergyCharge = (units > Threshold)
     ? (Threshold * FirstFifty + (units - Threshold) * AboveFifty)
     : (units * FirstFifty);

    // Calculate the total Bill
    TotalBill = EnergyCharge + FixedCharge;

    // Print the the energy charge, the service charge and the total bii in 2 decimals
    cout << fixed << setprecision(2);
    cout << "\n"<< "Energy charge: "<< EnergyCharge<< "Birr"<< "\n";
    cout << "Service charge: "<< FixedCharge<< "Birr"<< "\n\n"; 
    cout << "Total Bill: "<< TotalBill<< "Birr"<< endl;

    return 0;
}
