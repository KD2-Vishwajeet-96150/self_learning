 #include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    
    void createAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        }
    }


    void display() {
        cout << "\nAccount Details:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;

    
    acc.createAccount(101, "Vishwajeet", 5000);

    
    acc.deposit(2000);
    acc.withdraw(1500);

    acc.display();

    return 0;
}