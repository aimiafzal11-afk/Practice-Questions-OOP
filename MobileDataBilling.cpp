/* Design a MobileData class to calculate bills using function overloading for data, 
minutes, and SMS. Overload == operator to compare two bills after type conversion. */

#include <iostream>
using namespace std;

class MobileData {
private:
    double bill;
public:
    MobileData() {
        bill = 0;
    }
    double calculateBill(double data) {
        if (data < 0) {
            cout << "Invalid input!" << endl;
            return 0;
        }
        bill = data * 10;    //base rate per mb = 10
        return bill;
    }
    double calculateBill(double data, double min) {
        if (data < 0 || min < 0) {
            cout << "Invalid input!" << endl;
            return 0;
        }
        bill = (data * 10) + (min * 3);  //base rate per minute = 3
        return bill;
    }
    double calculateBill(double data, double min, double sms) {
        if (data < 0 || min < 0 || sms < 0) {
            cout << "Invalid input!" << endl;
            return 0;
        }
        bill = (data * 10) + (min * 2) + (sms * 2);  //base rate per sms = 2
        return bill;
    }
    MobileData operator+(const MobileData& obj) {
        MobileData temp;
        temp.bill = bill + obj.bill;
        return temp;
    }
    bool operator==(const MobileData& obj) const{
        return (int)bill == (int)obj.bill;
    }
    void display() {
        cout << "Bill = " << bill << endl;
    }
};

int main()
{
    MobileData m1, m2, m3;
    cout << "Bill 1 (data only)" << endl;
    m1.calculateBill(30.4);
    m1.display();
    cout << "Bill 2 (data and minutes)" << endl;
    m2.calculateBill(30.4, 8);
    m2.display();
    cout << "Bill 3 (data, minutes and sms)" << endl;
    m3.calculateBill(30.4, 9, 3);
    m3.display();

    MobileData total = m1 + m2;
    cout << "\nCombined Bill 1 and 2" << endl;
    total.display();
    
    cout << "\nComparison of Bill 2 and 3 " << endl;
    if (m2 == m3)
        cout << "Bill 2 and 3 are equal" << endl;
    else
        cout << "Bill 2 and 3 are not equal" << endl;
    return 0;
}