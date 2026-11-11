/*
 #Input
   - Assignment mark (out of 100, double)
   - Midterm mark (out of 100, double)
   - Final mark (out of 100, double)

 #Outputs
   - Course total (one decimal)
   - The word Pass or Fail

 #Process
   1, Define constants: assignment weight = 0.20, midterm weight = 0.30, final weight = 0.50, pass mark = 50.
   2, Read the three marks.
   3, Calculate total = (assignment × 0.20) + (midterm × 0.30) + (final × 0.50).
   4, Decide the result using the conditional operator: Pass if total >= 50, otherwise Fail.
   5, Display the total with one decimal place and the result.

 #Program Design
   1, Start
   2, Declare double variables assignment, midterm, final_mark
   3, Declare the constants: ASSIGN_WEIGHT = 0.20, MID_WEIGHT = 0.30, FINAL_WEIGHT = 0.50, PASS_MARK = 50
   4, Display "Enter assignment, midterm and final marks: "
   5, Read the marks into assignment, midterm and final_mark
   6, Declare a double total and calculate it: total = (assignment × ASSIGN_WEIGHT) + (midterm × MID_WEIGHT) + (final_mark × FINAL_WEIGHT)
   7, Declare a string result and use the conditional operator to set it: if total >= PASS_MARK, result = "Pass"; otherwise result = "Fail"
   8, Set the output format to fixed with one decimal place
   9, Display "Total: " followed by total
  10, Display "Result: " followed by result
  11, End
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    double assignment, midterm, final_mark;
    const double ASSIGN_WEIGHT = 0.20;
    const double MID_WEIGHT = 0.30;
    const double FINAL_WEIGHT = 0.50;
    const double PASS_MARK = 50;

    cout << "Enter assignment, midterm and final marks: " << endl;
    cin >> assignment >> midterm >> final_mark;

    double total = (assignment * ASSIGN_WEIGHT) + (midterm * MID_WEIGHT) + (final_mark * FINAL_WEIGHT);
    string result = total >= PASS_MARK ? "Pass" : "Fail";

    cout << fixed << setprecision(1);
    cout << "Total: " << total << endl;
    cout << "Result: " << result << endl;

    return 0;
}
