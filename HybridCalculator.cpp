/* Create 2 classes:
1. SimpleCalculator - Take input of 2 numbers using a function and perfom +, -, *, / and display the results using another function.
2. Scientific Calculator - Take 2 numbers as a parameter and perform any four scientific operation of your choice and display the results.
Create another class HybridCalculator and inherit it using these 2 classes */

#include <iostream>
#include<cmath>
using namespace std;

class SimpleCalculator {
protected:
    double n1, n2;
public:
    void input() {
        cout << "Enter two numbers: \n";
        cin >> n1 >> n2;
    }
    void display() {
        cout << "-- SIMPLE CALCULATOR ---" << endl;
        cout << "Sum of " << n1 << " and " << n2 << " = " << n1 + n2 << endl;
        cout << "Subtraction of " << n1 << " and " << n2 << " = " << n1 - n2 << endl;
        cout << "Multiplication of " << n1 << " and " << n2 << " = " << n1 * n2 << endl;
        if (n2 != 0)
            cout << "Division of " << n1 << " and " << n2 << " = " << n1 / n2 << endl;
        else
            cout << "Infinte!" << endl;
    }

};

class ScientificCalculator {
public:
    void show(double num1, double num2) {
        cout << "\n-- SCIENTIFIC CALCULATOR ---" << endl;
        cout << "cos(a+b) = " << cos(num1 + num2) << endl;
        cout << "cos(a-b) = " << cos(num1 - num2) << endl;
        cout << "sin(a+b) = " << sin(num1 + num2) << endl;
        cout << "sin(a-b) = " << sin(num1 - num2) << endl;
        cout << "tan(a+b) = " << tan(num1 + num2) << endl;
        cout << "tan(a-b) = " << tan(num1 - num2) << endl;
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator{
public:
    void calculate() {
        input();
        display();
        show(n1, n2);
    }
};

int main()
{
    HybridCalculator calc;
    calc.calculate();
    return 0;
}

