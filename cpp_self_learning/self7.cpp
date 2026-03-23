 #include <iostream>
using namespace std;


namespace college {

    
    class Student {
    private:
        int rollNo;
        string name;

    public:
        
        Student(int r, string n) {
            rollNo = r;
            name = n;
        }

        
        void setRollNo(int r) {
            rollNo = r;
        }

        void setName(string n) {
            name = n;
        }

        
        int getRollNo() {
            return rollNo;
        }

        string getName() {
            return name;
        }

        
        void display() {
            cout << "Student Roll No: " << rollNo << endl;
            cout << "Student Name: " << name << endl;
        }
    };

    
    class Teacher {
    private:
        int id;
        string name;

    public:
        
        Teacher(int i, string n) {
            id = i;
            name = n;
        }

        void setId(int i) {
            id = i;
        }

        void setName(string n) {
            name = n;
        }

        int getId() {
            return id;
        }

        string getName() {
            return name;
        }

        
        void display() {
            cout << "Teacher ID: " << id << endl;
            cout << "Teacher Name: " << name << endl;
        }
    };

} 


int main() {


    college::Student s1(1, "Vishwajeet");
    college::Teacher t1(101, "Dr. Sharma");

    
    s1.display();
    cout << endl;
    t1.display();

    
    s1.setName("Rahul");
    t1.setName("Dr. Mehta");

    cout << "\nAfter Updating:\n";
    s1.display();
    cout << endl;
    t1.display();

    return 0;
}