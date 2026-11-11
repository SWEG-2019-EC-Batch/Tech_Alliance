#include <iostream>

#include<iomanip>
using namespace std;

int main(){

    double assignment,midterm,finalexam;
    double total;
    cout << "Enter your assignment mark: ";
    cin >> assignment;

    cout << "Enter your midterm mark: ";
    cin >> midterm;

    cout << "Enter your final exam mark: ";
    cin >> finalexam;

    total = (assignment * 0.20) +
            (midterm * 0.30) +
            (finalexam * 0.50);

    cout << fixed << setprecision(1);

    cout << "Course total: " << total << endl;

    cout << "Result: " << (total >= 50 ? "Pass" : "Fail");
    return  0;



}
