/*
  a) i. Inputs
  -distance
  -hours
  -minutes
  -fuelRate
  -pricePerLiter
     ii. Outputs
     -averageSpeed
     -fuelUsed
     -fuelCost
  b) Process
  1. Start the program.
  2. Declare variables fot the inputs and outputs.
  3. Read the distance, hours, minutes, fuel consumption rate, and price per liter.
  4. Convert the total travel time into hours by dividing the minutes by 60 and adding the hours.
  5. Calculate the average speed by dividing the distance by the total travel time in hours.
  6. Calculate the fuel used by multiplying the distance by the fuel consumption rate and dividing by 100.
  7. Calculate the fuel cost by multiplying the fuel used by the price per liter.
  8. Display the average speed, fuel used, and fuel cost with two decimal places.
  9. End the program.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Declare variables
    double distance, fuelRate, pricePerLiter;
    int hours, minutes;

    double totalTime, averageSpeed, fuelUsed, fuelCost;

    // Read inputs
    cout << "Enter distance (km): ";
    cin >> distance;

    cout << "Enter travel time (hours and minutes): ";
    cin >> hours >> minutes;

    cout << "Enter fuel consumption (liters per 100 km): ";
    cin >> fuelRate;

    cout << "Enter price per liter (birr): ";
    cin >> pricePerLiter;

    // Calculate total time in hours
    totalTime = hours + static_cast<double>(minutes) / 60;

    // Calculate average speed
    averageSpeed = distance / totalTime;

    // Calculate fuel used
    fuelUsed = (distance * fuelRate) / 100;

    // Calculate fuel cost
    fuelCost = fuelUsed * pricePerLiter;

    // Display results
    cout << fixed << setprecision(2);

    cout << "\nAverage speed: " << averageSpeed << " km/h" << endl;
    cout << "Fuel used: " << fuelUsed << " liters" << endl;
    cout << "Fuel cost: " << fuelCost << " birr" << endl;

    return 0;
}
