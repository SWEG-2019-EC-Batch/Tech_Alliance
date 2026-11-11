/*
 #Input
   - Distance of the trip (km, double)
   - Travel time: hours (int) and minutes (int)
   - Fuel use (liters per 100 km, double)
   - Price per liter (birr, double)

 #Outputs
   - Average speed (km/h, two decimals)
   - Fuel used (liters, two decimals)
   - Fuel cost (birr, two decimals)

 #Process
   1, Define constants: minutes per hour = 60, distance base for fuel use = 100.
   2, Read the distance, hours, minutes, fuel use and price.
   3, Convert the time to hours: total hours = hours + (minutes / 60).
   4, Calculate average speed = distance / total hours.
   5, Calculate fuel used = distance × fuel use per 100 km / 100.
   6, Calculate fuel cost = fuel used × price per liter.
   7, Display the speed, fuel used and fuel cost with two decimal places.

 #Program Design
   1, Start
   2, Declare double variables distance, fuel_per_100, price
   3, Declare int variables hours, minutes
   4, Declare the constants: MINUTES_PER_HOUR = 60.0, FUEL_BASE = 100.0
   5, Display "Enter distance (km): " and read it into distance
   6, Display "Enter travel time (hours and minutes): " and read hours and minutes
   7, Display "Enter fuel use (L per 100 km): " and read it into fuel_per_100
   8, Display "Enter price per liter (birr): " and read it into price
   9, Declare a double total_hours and calculate it: total_hours = hours + (minutes / MINUTES_PER_HOUR)
  10, Declare a double avg_speed and calculate it: avg_speed = distance / total_hours
  11, Declare a double fuel_used and calculate it: fuel_used = distance × fuel_per_100 / FUEL_BASE
  12, Declare a double fuel_cost and calculate it: fuel_cost = fuel_used × price
  13, Set the output format to fixed with two decimal places
  14, Display "Average Speed: " followed by avg_speed
  15, Display "Fuel Used: " followed by fuel_used
  16, Display "Fuel Cost: " followed by fuel_cost
  17, End
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double distance, fuel_per_100, price;
    int hours, minutes;
    const double MINUTES_PER_HOUR = 60.0;
    const double FUEL_BASE = 100.0;

    cout << "Enter distance (km): " << endl;
    cin >> distance;
    cout << "Enter travel time (hours and minutes): " << endl;
    cin >> hours >> minutes;
    cout << "Enter fuel use (L per 100 km): " << endl;
    cin >> fuel_per_100;
    cout << "Enter price per liter (birr): " << endl;
    cin >> price;

    double total_hours = hours + (minutes / MINUTES_PER_HOUR);
    double avg_speed = distance / total_hours;
    double fuel_used = distance * fuel_per_100 / FUEL_BASE;
    double fuel_cost = fuel_used * price;

    cout << fixed << setprecision(2);
    cout << "Average Speed: " << avg_speed << " km/h" << endl;
    cout << "Fuel Used: " << fuel_used << " liters" << endl;
    cout << "Fuel Cost: " << fuel_cost << " birr" << endl;

    return 0;
}
