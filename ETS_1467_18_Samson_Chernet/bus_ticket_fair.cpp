#include <iostream>
using namespace std;

const int ROUTE_COUNT = 5;
const char* routeNames[ROUTE_COUNT] = {
    "hawassa", "Diredawa", "bahirdar", "mekele", "Jimma"
};
const float routeFares[ROUTE_COUNT] = {300, 450, 700, 900, 550};

void showRoutes() {
    cout << "Available Routes\n";
    for (int i = 0; i < ROUTE_COUNT; i++) {
        cout << i + 1 << ". Addis Ababa  ->  " << routeNames[i];
        // keep original column alignment
        int pad = 12 - (int)string(routeNames[i]).length();
        for (int p = 0; p < pad; p++) cout << ' ';
        cout << " : " << (int)routeFares[i] << "\n";
    }
    
}

float ageDiscount(int age, float fare) {
    if (age < 12) return fare * 0.50;
    if (age > 60) return fare * 0.25;
    return 0;
}

float baggageFee(float weight) {
    return (weight > 20) ? (weight - 20) * 10 : 0;
}

void printReceipt(float fare, float discount, float studentDiscount,
                  float extra, float total) {
    cout << "\nTICKET SUMMARY \n";
    cout << "Base fare            : " << fare << endl;
    cout << "Age discount         : " << discount << endl;
    cout << "Student discount(30%): " << studentDiscount << endl;
    cout << "Extra baggage fee    : " << extra << endl;
    cout << "------------------------------------\n";
    cout << "TOTAL FARE           : " << total << endl;
    
}

int main() {
    int routeChoice, avaSeat, age, isStudent;
    float bagWeight;

    // Route selection
    showRoutes();
    cout << "Choose your route (1-5): ";
    cin >> routeChoice;

    if (routeChoice < 1 || routeChoice > ROUTE_COUNT) {
        cout << "Invalid route selected. Exiting.\n";
        return 1;
    }
    float fare = routeFares[routeChoice - 1];

    // Seat check
    cout << "Enter Number of available seat: ";
    cin >> avaSeat;

    if (avaSeat <= 0) {
        cout << "All seats are reserved" << endl;
        return 0;
    }

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter baggage weight (kg): ";
    cin >> bagWeight;

    float discount = ageDiscount(age, fare);

    cout << "Are you a student? (1 = Yes, 0 = No): ";
    cin >> isStudent;
    float studentDiscount = (isStudent == 1) ? fare * 0.30 : 0;

    float extra = baggageFee(bagWeight);

    float total = (fare - discount - studentDiscount) + extra;
    if (total < 0) total = 0;

    printReceipt(fare, discount, studentDiscount, extra, total);
    return 0;
}
