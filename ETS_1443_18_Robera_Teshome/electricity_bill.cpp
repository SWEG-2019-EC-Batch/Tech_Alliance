// Task 2: Electricity bill
// (a) Inputs: units used in the month (kWh, whole number)
//     Outputs: energy charge, service charge, total bill (2 decimals)
// (b) Process:
// 1. Define constants: block limit 50, rate 1.50, rate above 50 is 2.00, service charge 10
// 2. Read the units used
// 3. Use the conditional operator to get units above 50 (units > 50 ? units - 50 : 0)
// 4. Use the conditional operator to get units in the first block (units < 50 ? units : 50)
// 5. Energy charge = first units * 1.50 + extra units * 2.00
// 6. Total bill = energy charge + service charge
// 7. Print the three values with two decimals

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int BLOCK_LIMIT = 50;
    const double RATE_FIRST = 1.50;
    const double RATE_ABOVE = 2.00;
    const double SERVICE_CHARGE = 10.0;

    int units;
    cout << "Enter units used (kWh): ";
    cin >> units;

    int extraUnits = (units > BLOCK_LIMIT) ? units - BLOCK_LIMIT : 0;
    int firstUnits = (units < BLOCK_LIMIT) ? units : BLOCK_LIMIT;

    double energyCharge = firstUnits * RATE_FIRST + extraUnits * RATE_ABOVE;
    double total = energyCharge + SERVICE_CHARGE;

    cout << fixed << setprecision(2);
    cout << "Energy charge: " << energyCharge << " birr" << endl;
    cout << "Service charge: " << SERVICE_CHARGE << " birr" << endl;
    cout << "Total bill: " << total << " birr" << endl;

    return 0;
}
