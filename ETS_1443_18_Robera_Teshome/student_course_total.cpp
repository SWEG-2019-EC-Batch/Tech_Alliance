// Task 1: Student course total
// (a) Inputs: assignment, midterm and final marks (each out of 100)
//     Outputs: course total (1 decimal) and Pass or Fail
// (b) Process:
// 1. Define constants for the weights (0.20, 0.30, 0.50) and pass mark (50)
// 2. Read the assignment, midterm and final marks
// 3. total = assignment*0.20 + midterm*0.30 + final*0.50
// 4. Use the conditional operator to choose Pass if total >= 50, else Fail
// 5. Print the total with one decimal place and the result

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double ASSIGNMENT_WEIGHT = 0.20;
    const double MIDTERM_WEIGHT = 0.30;
    const double FINAL_WEIGHT = 0.50;
    const double PASS_MARK = 50;

    double assignment, midterm, finalMark;

    cout << "Enter assignment mark: ";
    cin >> assignment;
    cout << "Enter midterm mark: ";
    cin >> midterm;
    cout << "Enter final mark: ";
    cin >> finalMark;

    double total = assignment * ASSIGNMENT_WEIGHT
                 + midterm * MIDTERM_WEIGHT
                 + finalMark * FINAL_WEIGHT;

    string result = (total >= PASS_MARK) ? "Pass" : "Fail";

    cout << fixed << setprecision(1);
    cout << "Total: " << total << endl;
    cout << "Result: " << result << endl;

    return 0;
}
