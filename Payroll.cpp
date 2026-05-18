// Create a payroll system using base class Employee and derived classes.

#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int ID) {
        name = n;
        id = ID;
    }
};
class Manager : public Employee {
private:
    double basicSalary;
    double bonus;
public:
    Manager(string n, int ID, double salary, double b) : Employee(n, ID){
        basicSalary = salary;
        bonus = b;
    }
    void display() {
        cout << "Manager Name: " << name << endl;
        cout << "ID:" << id << endl;
        cout << "Salary: " << basicSalary + bonus << endl << endl;
    }
};

class HourlyWorker : public Employee {
private:
    double hours;
    double hourlyRate;
public:
    HourlyWorker(string n, int ID, double h, double rate) : Employee(n, ID) {
        hours = h;
        hourlyRate = rate;
    }
    void display() {
        cout << "Employee Name: " << name << endl;
        cout << "ID:" << id << endl;
        cout << "Salary: " << hourlyRate * hours << endl << endl;
    }
};

class FreeLancer : public Employee {
private:
    int projects;
    double ratePerProject;
public:
    FreeLancer(string n, int ID, int p, double rate) : Employee(n, ID) {
        projects = p;
        ratePerProject = rate;
    }
    void display() {
        cout << "Employee Name: " << name << endl;
        cout << "ID:" << id << endl;
        cout << "Number of projects done: " << projects << endl;
        cout << "Rate per project: " << ratePerProject << endl;
        cout << "Salary: " << ratePerProject * projects << endl <<endl;
    }
};

int main()
{
    Manager m("Ali", 10, 100000.0, 10000);
    cout << "MANAGER" << endl;
    m.display();
    HourlyWorker h("Ahmed", 56, 200, 500.0);
    cout << "HOURLYWORKER" << endl;
    h.display();
    FreeLancer f("Sana", 34, 4, 20000);
    cout << "FREELANCER" << endl;
    f.display();

    return 0;
}
