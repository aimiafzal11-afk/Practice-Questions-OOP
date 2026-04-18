/* Create class Vehicle and derived Car.
Overload == to compare cars */

#include <iostream>
using namespace std;

class Vehicle{
protected:
    string brand;
    string color;
public:
    Vehicle(string b="", string clr="") {
        brand = b;
        color = clr;
    }
};

class Car : public Vehicle {
private:
    int price;
public:
    Car(string b = "", string clr = "", int p=0) : Vehicle(b, clr) {
        price = p;
    }
    void display() {
        cout << "Name: " << brand
            << "\nColor: " << color
            << "\nPrice: " << price << endl;
    }
    bool operator==(const Car& obj)const {
        return (brand == obj.brand &&
            color == obj.color &&
            price == obj.price);
    }
};

int main()
{
    Car c1("Mehran", "Grey", 500000);
    Car c2("Toyota", "White", 800000);
    Car c3("Mehran", "Grey", 500000);

    cout << "CAR 1" << endl;
    c1.display();
    cout << "CAR 2" << endl;
    c2.display();
    cout << "CAR 3" << endl;
    c3.display();

    if (c1 == c2)
        cout << "\ncar1 and car2 are same"<<endl;
    else
        cout << "\ncar1 and car2 are not same" << endl;

    if (c1 == c3)
        cout << "car1 and car3 are same" << endl;
    else
        cout << "car1 and car3 are not same" << endl;

    return 0;
}


