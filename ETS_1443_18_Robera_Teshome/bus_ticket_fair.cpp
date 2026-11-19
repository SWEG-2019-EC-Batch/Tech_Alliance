#include <iostream>
#include <string>
using namespace std;

int main() {
    // some fixed numbers
    const double FREE_KG = 20;
    const double EXTRA_PRICE = 10;   // per kg
    const double SENIOR = 0.25;
    const double CHILD = 0.50;
    const double STUDENT = 0.15;

    int seats;
    double fare, bag, age;
    char stu;

    double extraKg = 0;
    double extraPay = 0;
    double rate = 0;
    string dtype = "None";

    cout << "=====================================" << endl;
    cout << "         BUS TICKET SYSTEM           " << endl;
    cout << "=====================================" << endl;

    cout << "Seats available: ";
    cin >> seats;

    // stop if the bus is full
    if (seats <= 0) {
        cout << "Sorry, no seats left!" << endl;
        return 0;
    }

    cout << "Trip fare (birr): ";
    cin >> fare;
    cout << "Bag weight (kg): ";
    cin >> bag;
    cout << "Age: ";
    cin >> age;
    cout << "Student? (y/n): ";
    cin >> stu;

    // extra bag fee
    if (bag > FREE_KG) {
        extraKg = bag - FREE_KG;
        extraPay = extraKg * EXTRA_PRICE;
    }

    double subtotal = fare + extraPay;

    // age discount
    if (age >= 60) {
        rate = SENIOR;
        dtype = "Senior (60+)";
    }
    else if (age <= 12) {
        rate = CHILD;
        dtype = "Child (12 and under)";
    }

    // student discount, only if it's bigger than the one above
    if ((stu == 'y' || stu == 'Y') && STUDENT > rate) {
        rate = STUDENT;
        dtype = "Student";
    }

    double discount = subtotal * rate;
    double total = subtotal - discount;

    // receipt
    cout << "\n=====================================" << endl;
    cout << "              RECEIPT                " << endl;
    cout << "=====================================" << endl;
    cout << "Base fare:\t\t" << fare << " birr" << endl;

    if (extraKg > 0) {
        cout << "Extra baggage:\t\t" << extraKg << " kg x " << EXTRA_PRICE
             << " = " << extraPay << " birr" << endl;
    }

    cout << "Subtotal:\t\t" << subtotal << " birr" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Discount:\t\t" << dtype << endl;
    cout << "Discount amount:\t-" << discount << " birr" << endl;
    cout << "=====================================" << endl;
    cout << "TOTAL TO PAY:\t\t" << total << " birr" << endl;
    cout << "=====================================" << endl;

    seats--;
    cout << "Seats left: " << seats << endl;
    cout << "Thank you for travelling with us!" << endl;

    return 0;
}
