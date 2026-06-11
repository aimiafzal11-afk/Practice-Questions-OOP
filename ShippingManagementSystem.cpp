/* Design a Shipment Management System using function overloading to calculate shipping cost based on weight, weight + distance, 
and weight + distance + express delivery. Overload + and == operators for shipment management and validate weight and distance*/

#include <iostream>
using namespace std;

class Shipment {
private:
    int static id;
    double weight;
    double distance;
    bool isExpress;
    double totalCost;

public:
    Shipment(){
        id++;
        weight = 0.0;
        distance = 0.0;
        isExpress = false;
        totalCost = 0.0;
    }
    double calculateCost(double w) {
        if (w < 0) {
            cout << "Invalid input!\n";
            return 0;
        }
        if (w > 0 && w < 100)
            totalCost = 50;
        else if (w > 100 && w < 200)
            totalCost = 100;
        else if (w > 200)
            totalCost = 150;
        return totalCost;
    }
    double calculateCost(double w, double dis) {
        if (w < 0 || dis < 0) {
            cout << "Invalid input!\n";
            return 0;
        }
        if (w > 0 && w < 100)
            totalCost = 50;
        else if (w > 100 && w < 200)
            totalCost = 100;
        else if (w > 200)
            totalCost = 150;

        totalCost += dis * 2;       //rate per km = 2
        return totalCost;
    }
    double calculateCost(double w, double dis, bool express) {
        if (w < 0 || dis < 0) {
            cout << "Invalid input!\n";
            return 0;
        }
        if (w > 0 && w < 100)
            totalCost = 50;
        else if (w > 100 && w < 200)
            totalCost = 100;
        else if(w > 200)
            totalCost = 150;

        totalCost += (dis * 2) + 100;    //express delivery charges = 100  
        return totalCost;
    }
    Shipment operator+(const Shipment& obj) {
        Shipment temp;
        temp.totalCost = totalCost + obj.totalCost;
        return temp;
    }
    bool operator==(const Shipment& obj) const {
        return(totalCost == obj.totalCost);
    }
    void display() {
        cout << "Shipment ID = " << Shipment::id << endl;
        cout << "Total Cost = " << totalCost << endl;
    }
};
int Shipment::id = 0;
int main()
{
    Shipment s1;
    cout << "Shipment 1 (weight only)" << endl;
    s1.calculateCost(50);
    s1.display();

    Shipment s2;
    cout << "\nShipment 2 (weight and distance)" << endl;
    s2.calculateCost(50, 100);
    s2.display();

    Shipment s3;
    cout << "\nShipment 3 (weight, distance and express charges)" << endl;
    s3.calculateCost(50, 100, true);
    s3.display();

    cout << "\nCombined Shipment 1 and 2" << endl;
    Shipment add = s1 + s2;
    add.display();

    cout << "\nComparison of Shipment 2 and 3" << endl;
    if (s2 == s3)
        cout << "Both Shipments are equal." << endl;
    else
        cout << "Both Shipments are NOT equal." << endl;
    return 0;
}

