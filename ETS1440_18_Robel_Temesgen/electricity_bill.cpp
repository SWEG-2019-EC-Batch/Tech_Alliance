#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    cout << fixed<< setprecision (2);
    const double first_rate =1.50;
    const double second_rate =2.00;
    const double service_charge =10.00;
    const int first_limit =50;
    int units;

    double energycharge ,totalbill;

    cout << "Enter electricity units used (kwh):";
    cin >> units;

    energycharge = (units <= first_limit) ? (units * first_rate) 
    : (first_limit * first_rate + (units - first_limit)
    
    * second_rate);

    totalbill = energycharge + service_charge;

    cout << "Energy Charge: " << energycharge << "birr" << endl;
    cout << "Service Charge: " << service_charge << "birr" << endl;
    cout << "Total Bill: " << totalbill << "birr" << endl;

    return 0;
}