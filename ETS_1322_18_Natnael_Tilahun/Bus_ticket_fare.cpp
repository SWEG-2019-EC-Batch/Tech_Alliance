/*
IPO (Input-Process-Output)

1. Input and Output

a. Input
   - seat_left: number of available seats
   - destination: destination number (1-5)
   - age: age of the passenger
   - student: student status (y/n)
   - baggage_weight: baggage weight in kg

   Destinations and fares (departure: Addis Ababa):
   1. Beijing (China) - 850 USD
   2. Los Angeles (USA) - 1400 USD
   3. Liverpool (England) - 950 USD
   4. Rome (Italy) - 700 USD
   5. Berlin (Germany) - 800 USD

   Constants: free baggage limit = 20 kg, baggage rate = 12 USD per extra kg

b. Output
   - If seat_left <= 0: "Sorry, all seats have been sold."
   - If destination is not 1-5: "Invalid destination number. Please enter a number from 1 to 5."
   - Otherwise:
     - Trip fare (USD)
     - Baggage fare (USD)
     - Total fare (USD)

2. Process

   1. Read the number of available seats.
   2. If seat_left <= 0, display the sold-out message and stop.
   3. Otherwise, display the destinations with their fares and read the destination number.
   4. Use a switch to set trip_fare from the destination:
      - 1: 850
      - 2: 1400
      - 3: 950
      - 4: 700
      - 5: 800
      - Any other number: display the invalid destination message and stop.
   5. Read the age and the student status.
   6. Apply only one discount, checked in this order:
      - If age < 12: trip_fare = trip_fare - 50% of trip_fare
      - Else if student is 'y' or 'Y': trip_fare = trip_fare - 30% of trip_fare
      - Else if age > 65: trip_fare = trip_fare - 25% of trip_fare
      - Otherwise: no discount
   7. Read the baggage weight.
   8. Calculate the baggage fare:
      - If baggage_weight > 20: baggage_fare = (baggage_weight - 20) x 12
      - Otherwise: baggage_fare = 0
   9. Calculate total_fare = trip_fare + baggage_fare.
   10. Display the trip fare, baggage fare, and total fare with 2 decimal places.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float baggage_fare, baggage_weight, total_fare, trip_fare;
    int seat_left, age, destination;
    char student;

    cout << "Enter the number of available seats: ";
    cin >> seat_left;

    if (seat_left <= 0) {
        cout << "Sorry, all seats have been sold." << endl;
    } else {
        cout << "\nAvailable destinations (departure: Addis Ababa):" << endl;
        cout << "1. Beijing (China) - 850 USD" << endl;
        cout << "2. Los Angeles (USA) - 1400 USD" << endl;
        cout << "3. Liverpool (England) - 950 USD" << endl;
        cout << "4. Rome (Italy) - 700 USD" << endl;
        cout << "5. Berlin (Germany) - 800 USD" << endl;
        cout << "Enter your destination number (1-5): ";
        cin >> destination;

        switch (destination) {
            case 1: trip_fare = 850; break;
            case 2: trip_fare = 1400; break;
            case 3: trip_fare = 950; break;
            case 4: trip_fare = 700; break;
            case 5: trip_fare = 800; break;
            default:
                cout << "Invalid destination number. Please enter a number from 1 to 5." << endl;
                return 0;
        }

        cout << "Enter your age: ";
        cin >> age;
        cout << "Are you a student? (y/n): ";
        cin >> student;

        if (age < 12) {
            trip_fare = trip_fare - trip_fare * 0.50;
        } else if (student == 'y' || student == 'Y') {
            trip_fare = trip_fare - trip_fare * 0.30;
        } else if (age > 65) {
            trip_fare = trip_fare - trip_fare * 0.25;
        }

        cout << "Enter your baggage weight (kg): ";
        cin >> baggage_weight;

        baggage_fare = 0;
        if (baggage_weight > 20) {
            baggage_fare = (baggage_weight - 20) * 12;
        }
        total_fare = trip_fare + baggage_fare;

        cout << fixed << setprecision(2);
        cout << "\nTrip fare:    " << trip_fare << " USD" << endl;
        cout << "Baggage fare: " << baggage_fare << " USD" << endl;
        cout << "Total fare:   " << total_fare << " USD" << endl;
    }
    return 0;
}
