/*
  a) i. inputs
   -assignment mark out of 100.
   -midterm mark out of 100.
   -final mark out of 100.

     ii. outputs
   -Total mark.
   -Result of Pass/Fail based on students total mark.

   b) Process
   1. Start the program.
   2. Declare the variables to store the assignment, midterm, final marks and total marks.
   3. Read and store the assignment, midterm, and final marks.
   4. Calculate the weighted total by multiplying the assignment mark by 20%, the midterm mark by 30%,
    and the final exam mark by 50%, then adding the results.
   5. Use the conditional operator to determine whether the student passes or fails (50 or above = Pass; below 50 = Fail).
   6. Print the total mark to one decimal place.
   7. Print the result (Pass or Fail).
   8. Stop the program.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

   // Declare variables for assignment, midterm, final marks.
   double assignment, midterm, final, total;

   // Declare the constants
   const double AssWeight = 0.20;
   const double MidWeight = 0.30;
   const double FinalWeight = 0.50;
   const double PassMark= 50;

    // Read the three marks.
    cout << "Enter your assignment mark out of 100: "; //20% of total
    cin >> assignment;

    cout << "Enter your midterm mark out of 100: "; //30% of total
    cin >> midterm;

    cout << "Enter your final mark of 100: "; //50% of total
    cin >> final;

    // Calculate the total mark
    total = (assignment * AssWeight) + (midterm * MidWeight) + (final * FinalWeight);

   // Print the total and Decide Pass/Fail.
    cout << fixed << setprecision(1);
    cout << "\n"<< "Your total mark is: "<< total<< "\n";
    cout << "Your result: "<< (total >=PassMark ? "Pass": "Fail")<< endl;

    return 0;
}
