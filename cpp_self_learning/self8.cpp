 #include <iostream>
using namespace std;


class Programmer {
public:
    Programmer() {
        cout << "Programmer Constructor Called" << endl;
    }

    void work() {
        cout << "Programmer is coding" << endl;
    }
};


class Teacher {
public:
    Teacher() {
        cout << "Teacher Constructor Called" << endl;
    }

    void work() {
        cout << "Teacher is teaching" << endl;
    }
};


class ProgrammingTeacher : public Programmer, public Teacher {
public:
    ProgrammingTeacher() {
        cout << "ProgrammingTeacher Constructor Called" << endl;
    }
};


int main() {
    ProgrammingTeacher pt;

    

    
    pt.Programmer::work();
    pt.Teacher::work();

    return 0;
}