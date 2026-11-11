// Task 3: Trip speed and fuel cost
// (a) Inputs: distance (km), hours, minutes, fuel use (liters per 100 km), price per liter (birr)
//     Outputs: average speed (km/h), fuel used (liters), fuel cost (birr), each 2 decimals
// (b) Process:
// 1. Define constants: 60 minutes per hour, 100 km base
// 2. Read distance, hours, minutes, fuel use and price per liter
// 3. totalHours = hours + minutes / 60.0 (cast avoids integer division)
// 4. Average speed = distance / totalHours
// 5. Fuel used = distance * fuel use / 100
// 6. Fuel cost = fuel used * price per liter
// 7. Print the three values with two decimals

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double MINUTES_PER_HOUR = 60.0;
    const double KM_BASE = 100.0;

    double distance, fuelPer100, pricePerLiter;
    int hours, minutes;

    cout << "Enter distance (km): ";
    cin >> distance;
    cout << "Enter travel time hours: ";
    cin >> hours;
    cout << "Enter travel time minutes: ";
    cin >> minutes;
    cout << "Enter fuel use (liters per 100 km): ";
    cin >> fuelPer100;
    cout << "Enter price per liter (birr): ";
    cin >> pricePerLiter;

    double totalHours = static_cast<double>(hours) + minutes / MINUTES_PER_HOUR;

    double averageSpeed = distance / totalHours;
    double fuelUsed = distance * fuelPer100 / KM_BASE;
    double fuelCost = fuelUsed * pricePerLiter;

    cout << fixed << setprecision(2);
    cout << "Average speed: " << averageSpeed << " km/h" << endl;
    cout << "Fuel used: " << fuelUsed << " liters" << endl;
    cout << "Fuel cost: " << fuelCost << " birr" << endl;

    return 0;
}
