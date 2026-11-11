/*
 #Input
   - Units of electricity used in the month (kWh, int)

 #Outputs
   - Energy charge (two decimals)
   - Service charge (two decimals)
   - Total bill (two decimals)

 #Process
   1, Define the constants: tier limit = 50, first rate = 1.50, second rate = 2.00, service charge = 10.
   2, Read the units used.
   3, First tier units = the smaller of units and 50 (conditional operator).
   4, Second tier units = units - 50 if units is above 50, otherwise 0 (conditional operator).
   5, Energy charge = (first tier units x 1.50) + (second tier units x 2.00).
   6, Total bill = energy charge + service charge.
   7, Display the three values with two decimal places.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Constants
    const int TIER_LIMIT = 50;
    const double FIRST_RATE = 1.50;
    const double SECOND_RATE = 2.00;
    const double SERVICE_CHARGE = 10.00;

    // Input
    int units;
    cout << "Enter electricity unit in KWH: ";
    cin >> units;

    // Split the units into two tiers
    int first_tier  = units < TIER_LIMIT ? units : TIER_LIMIT;
    int second_tier = units > TIER_LIMIT ? units - TIER_LIMIT : 0;

    // Calculations
    double energy_charge = (first_tier * FIRST_RATE) + (second_tier * SECOND_RATE);
    double total_bill = energy_charge + SERVICE_CHARGE;

    // Output
    cout << fixed << setprecision(2);
    cout << "Energy Charge: " << energy_charge << endl;
    cout << "Service Charge: " << SERVICE_CHARGE << endl;
    cout << "Total Bill: " << total_bill << endl;

    return 0;
}
