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
