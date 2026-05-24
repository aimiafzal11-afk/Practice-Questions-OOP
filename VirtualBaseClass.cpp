#include <iostream>
using namespace std;

class Student {
protected:
    int rollno;
public:
    void set_rollno(int no) {
        rollno = no;
    }
    void show_rollno() {
        cout << "You roll no is: " << rollno << endl;
    }
};

class Marks : virtual public Student {
protected:
    float eng, math, sci;
public:
    void set_marks(float e, float m, float s) {
        eng = e;
        math = m;
        sci = s;
    }
    void show_marks() {
        cout << "Your marks are: " << endl
            << "English = " << eng << endl
            << "Math = " << math << endl
            << "Science = " << sci << endl;
    }
};

class Sports : virtual public Student {
protected:
    int score;
public:
    void set_score(int sc) {
        score = sc;
    }
    void show_score() {
        cout << "Your sports score are: " << score << endl;
    }
};

class Result : public Marks, public Sports {
private:
    float total;
public:
    void show_result() {
        total = eng + math + sci + score;
        show_rollno();
        show_marks();
        show_score();
        cout << "Your total marks are: " << total << endl;
    }
    
};

int main()
{
    Result student;
    student.set_rollno(10);
    student.set_marks(54, 90, 78);
    student.set_score(9);
    student.show_result();
    return 0;
}
