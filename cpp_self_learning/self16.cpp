
#include<iostream>
#include<memory>
using namespace std;

class Student {
public:
    void display() {
        cout << "Student info\n";
    }
};

int main() {
    try {
        // Using smart pointer
        unique_ptr<Student> s(new Student());

        s->display();
    }
    catch(...) {
        cout << "Invalid input\n";
    }

    return 0;
}

