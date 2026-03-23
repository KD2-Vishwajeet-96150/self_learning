
#include<iostream>
#include<fstream>
using namespace std;

class Student {
    int id;
    char name[20];

public:
    void accept() {
        cout << "Enter id and name: ";
        cin >> id >> name;
    }

    void display() {
        cout << id << " " << name << endl;
    }
};

int main() {
    Student s;

    ofstream fout("student.dat", ios::binary);
    s.accept();
    fout.write((char*)&s, sizeof(s));
    fout.close();

    ifstream fin("student.dat", ios::binary);
    Student s2;
    fin.read((char*)&s2, sizeof(s2));
    s2.display();

    return 0;
}

