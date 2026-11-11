#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double distance, fuelUsePer100Km, pricePerLiter;
    int hours, minutes;
    double totalTime, averageSpeed, fuelUsed, fuelCost;

    cout << "Enter distance of the trip (km): ";
    cin >> distance;

    cout << "Enter travel time (hours and minutes): ";
    cin >> hours >> minutes;

    cout << "Enter fuel use (liters per 100 km): ";
    cin >> fuelUsePer100Km;

    cout << "Enter price per liter (birr): ";
    cin >> pricePerLiter;

    totalTime = hours + (static_cast<double>(minutes) / 60);
    averageSpeed = distance / totalTime;
    fuelUsed = (distance / 100) * fuelUsePer100Km;
    fuelCost = fuelUsed * pricePerLiter;

    cout << fixed << setprecision(2);
    cout << "Average speed: " << averageSpeed << " km/h" << endl;
    cout << "Fuel used: " << fuelUsed << " liters" << endl;
    cout << "Fuel cost: " << fuelCost << " birr" << endl;

    return 0;
}