/*Task 2: Electricity Bill Calculator 

1. Determine the Inputs and Outputs
Inputs: Electricity units consumed in kWh (whole number).

Outputs: Energy charge, service charge (10 birr), and total bill (each formatted to two decimal places).

process:
step1: Prompt and read the total electricity units used (kWh) as an integer.

step2: Use the conditional operator to compute units charged at the base rate (first 50 units at 1.50 birr) versus extra units (units above 50 at 2.00 birr).

step3: Calculate the total energy charge by adding the base tier cost and the excess tier cost.

step4: Add the fixed service charge of 10.00 birr to find the final total bill.

step5: Display the energy charge, service charge, and total bill formatted to two decimal places.
*/


#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int units;
    const double SERVICE_CHARGE = 10.00;

    cout << "Enter electricity units consumed (kWh): ";
    cin >> units;

    double energyCharge = (units <= 50) ? (units * 1.50) : (50 * 1.50 + (units - 50) * 2.00);

    double totalBill = energyCharge + SERVICE_CHARGE;

    cout << fixed << setprecision(2);
    cout << "Energy charge: " << energyCharge << " birr" << endl;
    cout << "Service charge: " << SERVICE_CHARGE << " birr" << endl;
    cout << "Total bill: " << totalBill << " birr" << endl;

    return 0;
}
