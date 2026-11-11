/*
    Determine the Inputs and Outputs
Inputs:  Assignment mark (out of 100), Midterm mark (out of 100), Final exam mark (out of 100).
Outputs: Total course mark (formatted to one decimal place) and status ("Pass" or "Fail").
    process
    step1: Provide the Process as a Numbered ListPrompt and read the assignment, midterm, and final exam marks from the user.
    step2: Compute the weighted components: 20% for the assignment, 30% for the midterm, and 50% for the final exam.
    step3: Add the weighted marks together to calculate the overall course total.
    step4: Format the output to display the total with one decimal place.
    step5: Use the conditional operator to check if the total is greater than or equal to 50, printing "Pass" if true and "Fail" otherwise.

    
#include <iostream>
using namespace std;
int main(){
    double assignment;
    cout<< "enter assignment marks: ";
    cin >> assignment;
    double mid;
    cout<< "enter mid marks: ";
    cin >> mid;
    double final;
    cout<< "enter final exam marks: ";
    cin >> final;
    assignment= (20*assignment)/100;
    mid= (mid*30)/100;
    final=(final*50)/100;
    double total= assignment+mid+final;
    cout<< "your total marks are " << total<< endl;
    total>=50? cout<< "congrats you have passed": cout<< "you have failed";
        return 0;
}
