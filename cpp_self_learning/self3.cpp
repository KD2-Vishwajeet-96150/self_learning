#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    float marks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Marks: " << marks << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    
    Student* students = new Student[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of student " << i + 1 << endl;
        students[i].input();
    }

    
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    
    float maxMarks = students[0].marks;
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (students[i].marks > maxMarks) {
            maxMarks = students[i].marks;
            maxIndex = i;
        }
    }

    cout << "\n--- Student with Highest Marks ---\n";
    students[maxIndex].display();

    
    delete[] students;

    return 0;
}