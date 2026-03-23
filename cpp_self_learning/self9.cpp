 #include <iostream>
using namespace std;


class Person {
protected:
    string name;
    int age;

public:
    
    Person(string n, int a) {
        name = n;
        age = a;
    }

    
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    
    virtual void work() = 0;
};


class Student : public Person {
private:
    int marks;

public:
    Student(string n, int a, int m) : Person(n, a) {
        marks = m;
    }

    void study() {
        cout << "Student is studying" << endl;
    }

    
    void work() {
        cout << "Student's work: Learning and studying" << endl;
    }

    void display() {
        Person::display();
        cout << "Marks: " << marks << endl;
    }
};


class Teacher : public Person {
private:
    double salary;

public:
    Teacher(string n, int a, double s) : Person(n, a) {
        salary = s;
    }

    void teach() {
        cout << "Teacher is teaching" << endl;
    }

    
    void work() {
        cout << "Teacher's work: Teaching students" << endl;
    }

    void display() {
        Person::display();
        cout << "Salary: " << salary << endl;
    }
};


int main() {

    
    Person* p;

    Student s1("Vishwajeet", 20, 85);
    Teacher t1("Dr. Sharma", 40, 50000);

    
    p = &s1;
    p->display();
    p->work();   
    cout << endl;

    
    p = &t1;
    p->display();
    p->work();   

    return 0;
}