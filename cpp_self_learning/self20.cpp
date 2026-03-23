 
#include<iostream>
#include<memory>
using namespace std;

int main() {
    // unique_ptr (ownership transfer)
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2 = move(p1);

    // shared_ptr (shared ownership)
    shared_ptr<int> sp1(new int(20));
    shared_ptr<int> sp2 = sp1;

    // weak_ptr (non-owning)
    weak_ptr<int> wp = sp1;

    cout << "Shared value: " << *sp1 << endl;

    return 0;
}

