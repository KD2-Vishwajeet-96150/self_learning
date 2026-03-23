 #include <iostream>
using namespace std;


inline int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


inline int power(int base, int exp) {
    int result = 1;
    for(int i = 1; i <= exp; i++) {
        result *= base;
    }
    return result;
}


int main() {
    int num, base, exp;

    cout << "Enter number for factorial: ";
    cin >> num;

    cout << "Factorial = " << factorial(num) << endl;

    cout << "\nEnter base and exponent: ";
    cin >> base >> exp;

    cout << "Power = " << power(base, exp) << endl;

    return 0;
}