/*Task 3: Trip Speed and Fuel Cost
1. Determine the Inputs and Outputs
Inputs: Trip distance (km), travel time in hours and minutes (whole numbers), fuel efficiency (liters per 100 km), and fuel price per liter (birr).

Outputs: Average speed (km/h), total fuel used (liters), and total fuel cost (birr) — all with two decimal places.

2. process
step1: Prompt and read the distance, hours, minutes, fuel consumption rate per 100 km, and price per liter.

step2: Convert the total travel time into hours as a decimal (hours + minutes / 60.0).

step3: Calculate average speed by dividing distance by total hours.

step4: Calculate total fuel used by multiplying distance by fuel consumption rate and dividing by 100.

step5: Calculate total fuel cost by multiplying total fuel used by the price per liter.

step6: Display average speed, fuel used, and fuel cost, each formatted to two decimal places.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double distance, fuelRatePer100Km, pricePerLiter;
    int hours, minutes;

    cout << "Enter trip distance (km): ";
    cin >> distance;

    cout << "Enter travel time - hours: ";
    cin >> hours;

    cout << "Enter travel time - minutes: ";
    cin >> minutes;

    cout << "Enter car's fuel use (liters per 100 km): ";
    cin >> fuelRatePer100Km;

    cout << "Enter price per liter (birr): ";
    cin >> pricePerLiter;

    
    double totalHours = hours + (minutes / 60.0);

    
    double averageSpeed = distance / totalHours;
    double fuelUsed = (distance * fuelRatePer100Km) / 100.0;
    double fuelCost = fuelUsed * pricePerLiter;


    cout << fixed << setprecision(2);
    cout << "Average speed: " << averageSpeed << " km/h" << endl;
    cout << "Fuel used: " << fuelUsed << " liters" << endl;
    cout << "Fuel cost: " << fuelCost << " birr" << endl;

    return 0;
}
