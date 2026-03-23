
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main() {
    list<int> l = {5, 3, 9, 1, 7, 2, 8, 6, 4, 10};

    // Reverse display
    for(auto it = l.rbegin(); it != l.rend(); it++)
        cout << *it << " ";
    cout << endl;

    // Increment by 5
    for(auto it = l.begin(); it != l.end(); it++)
        *it += 5;

    // Const iterator
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Sort
    l.sort();

    // Display
    for(auto x : l)
        cout << x << " ";

    return 0;
}

