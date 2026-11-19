#include <iostream>
using namespace std;
int main()
{

    // declaration of inputs
    int base_salary, worked_hours, bonus_rate;

    // declaration of outputs
    float pension, gross_salary, tax, net_salary;
    float base_rate= worked_hours/40;
    int bonus_salary;
    int extra_hours = 0;

    // input stage
    cout << "enter the base salary: ";
    cin >> base_salary;
    cout << "enter weekly worked hours (>= 40hrs/week): ";
    cin >> worked_hours;
    cout << "enter bonus rate (..ETB/hrs): ";
    cin >> bonus_rate;

    // extra hour calculation
    if (worked_hours > 40)
    {
        extra_hours = worked_hours - 40;}
    
    else if(worked_hours<40){
        base_salary=base_salary-base_rate*worked_hours;
    }

    // bonus calculation
    bonus_salary = bonus_rate * extra_hours;

    // assign gross
    gross_salary = base_salary + bonus_salary;

    // pension deduction 7% of gross
    pension = gross_salary * (0.07);

    if (gross_salary <= 3500)
    {
        tax = 0;
    }
    else if (gross_salary > 3500 && gross_salary <= 10000)
    {
        tax = gross_salary * 0.1;
    }
    else if (gross_salary > 10000 && gross_salary <= 25000)
    {
        tax = gross_salary * 0.15;
    }
    else if (gross_salary > 25000 && gross_salary <= 50000)
    {
        tax = gross_salary * 0.2;
    }
    else if (gross_salary > 50000 && gross_salary <= 100000)
    {
        tax = gross_salary * 0.25;
    }
    else
    {
        tax = gross_salary * (0.3);
    }

    // net salary calculation
    net_salary = gross_salary - pension - tax;

    // printing the outputs
int display;

cout<<"dsplay all? press 1: "<<endl;

cout<<"dsplay bonuse payment? press 2: "<<endl;
cout<<"dsplay deducted pension? press 3: "<<endl;
cout<<"dsplay net salary? press 4: "<<endl;
cout <<"display gross_salary? press5: "<<endl;
cin>> display;

switch(display) {
    case 1: 
    cout << "\nthe gross salary is: birr " << gross_salary << endl;
    cout << "the bonus payment is: birr " << bonus_salary << endl;
    cout << "the deducted tax is: birr " << tax << endl;
    cout << "the deducted pension is: birr " << pension << endl;
    cout << "the net salary is: birr " << net_salary << endl;
    break;
    case 2:
   cout << "the bonus payment is: birr " << bonus_salary << endl;
   break;
    case 3:
      cout << "the deducted pension is: birr " << pension << endl;
      break;
    case 4:
     cout << "the net salary is: birr " << net_salary << endl;
     break;
     case 5:
      cout << "\nthe gross salary is: birr " << gross_salary << endl;
      case 6:
      cout << "\ndeducted tax: birr " << tax << endl;
      break;
      default: 
      cout<<"invalid input"<<endl;
      return 0;



}
}
