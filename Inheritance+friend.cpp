#include <iostream>
using namespace std;

class Children {
protected:
    string name;
    int age;
public:
    Children(string n = "", int years = 0) {
        name = n;
        age = years;
    }
};

class Student : public Children {
private:
    string rollno;
public:
    Student(string n = "", int years = 0, string roll = "") : Children(n, years) {
        rollno = roll;
    }
    friend void input(Student& s) {
        cout << "Enter Student name : ";
        cin >> s.name;
        cout << "Enter Student age : ";
        cin >> s.age;
        cout << "Enter Student rollno : ";
        cin >> s.rollno;
    }
    friend void display(Student s) {
        cout << "\nSTUDENT DETAILS\n";
        cout << "Student name : " << s.name << endl;
        cout << "Student age : " << s.age << endl;
        cout << "Student rollno : " << s.rollno << endl;
    }
};

int main()
{
    Student s1;
    input(s1);
    display(s1);

    return 0;
}
