 #include <iostream>
using namespace std;


void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside swapByValue(): ";
    cout << "a = " << a << ", b = " << b << endl;
}


void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside swapByReference(): ";
    cout << "a = " << a << ", b = " << b << endl;
}


int main() {
    int x = 10, y = 20;

    cout << "Before swapByValue(): ";
    cout << "x = " << x << ", y = " << y << endl;

    swapByValue(x, y);

    cout << "After swapByValue(): ";
    cout << "x = " << x << ", y = " << y << endl;

    cout << endl;

    cout << "Before swapByReference(): ";
    cout << "x = " << x << ", y = " << y << endl;

    swapByReference(x, y);

    cout << "After swapByReference(): ";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}