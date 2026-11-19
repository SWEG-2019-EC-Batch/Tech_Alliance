#include <iostream>
using namespace std;

int main() {
    // ---------- Constants ----------
    const double FREE_BAGGAGE_KG  = 20;     // free baggage allowance
    const double EXTRA_RATE       = 10;     // birr per extra kg
    const double SENIOR_DISCOUNT  = 0.25;   // age 60 and above
    const double CHILD_DISCOUNT   = 0.50;   // age 12 and below
    const double STUDENT_DISCOUNT = 0.15;   // students

    // ---------- Variables ----------
    int    available_seats;
    double base_fare, baggage_weight, age;
    char   is_student;
    double extra_weight = 0, extra_fare = 0;
    double discount_rate = 0, discount_amount = 0;
    double subtotal, final_fare;
    int    discount_type = 0;   // 0 = none, 1 = senior, 2 = child, 3 = student

    // ---------- Header ----------
    cout << "=====================================" << endl;
    cout << "         BUS TICKET SYSTEM           " << endl;
    cout << "=====================================" << endl;

    // ---------- Seats ----------
    cout << "Available seats: ";
    cin >> available_seats;

    if (available_seats <= 0) {
        cout << endl << "Sorry, there are no available seats!" << endl;
        return 0;
    }

    // ---------- Passenger details ----------
    cout << "Base trip fare (birr): ";
    cin >> base_fare;
    cout << "Baggage weight (kg): ";
    cin >> baggage_weight;
    cout << "Passenger age: ";
    cin >> age;
    cout << "Are you a student? (y/n): ";
    cin >> is_student;

    // ---------- Extra baggage ----------
    if (baggage_weight > FREE_BAGGAGE_KG) {
        extra_weight = baggage_weight - FREE_BAGGAGE_KG;
        extra_fare = extra_weight * EXTRA_RATE;
    }
    subtotal = base_fare + extra_fare;

    // ---------- Discount: the best single discount is applied ----------
    if (age >= 60) {
        discount_rate = SENIOR_DISCOUNT;
        discount_type = 1;
    }
    else if (age <= 12) {
        discount_rate = CHILD_DISCOUNT;
        discount_type = 2;
    }

    if ((is_student == 'y' || is_student == 'Y') && STUDENT_DISCOUNT > discount_rate) {
        discount_rate = STUDENT_DISCOUNT;
        discount_type = 3;
    }

    discount_amount = subtotal * discount_rate;
    final_fare = subtotal - discount_amount;

    // ---------- Receipt ----------
    cout << endl;
    cout << "=====================================" << endl;
    cout << "              RECEIPT                " << endl;
    cout << "=====================================" << endl;
    cout << "Base fare:\t\t" << base_fare << " birr" << endl;

    if (extra_weight > 0) {
        cout << "Extra baggage:\t\t" << extra_weight << " kg x " << EXTRA_RATE
             << " = " << extra_fare << " birr" << endl;
    }

    cout << "Subtotal:\t\t" << subtotal << " birr" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Discount:\t\t";
    if (discount_type == 1)      cout << "Senior (60+)" << endl;
    else if (discount_type == 2) cout << "Child (12 and under)" << endl;
    else if (discount_type == 3) cout << "Student" << endl;
    else                         cout << "None" << endl;
    cout << "Discount amount:\t-" << discount_amount << " birr" << endl;
    cout << "=====================================" << endl;
    cout << "TOTAL TO PAY:\t\t" << final_fare << " birr" << endl;
    cout << "=====================================" << endl;

    available_seats--;
    cout << "Seats left: " << available_seats << endl;
    cout << "Thank you for travelling with us!" << endl;

    return 0;
}
