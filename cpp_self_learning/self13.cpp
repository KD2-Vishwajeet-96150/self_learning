 #include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Payment {
public:
    
    virtual void makePayment(double amount) = 0;
    
    
    virtual ~Payment() {}
};


class CreditCard : public Payment {
public:
    void makePayment(double amount) override {
        cout << "[Credit Card] Processing $" << amount << " via Secure Gateway..." << endl;
        cout << "Transaction Successful! (Reward points added)." << endl;
    }
};

class UPI : public Payment {
public:
    void makePayment(double amount) override {
        cout << "[UPI] Initiating transfer of $" << amount << "..." << endl;
        cout << "Transaction Successful! (VPA verified)." << endl;
    }
};

class Cash : public Payment {
public:
    void makePayment(double amount) override {
        cout << "[Cash] Payment of $" << amount << " received at counter." << endl;
        cout << "Transaction Successful! (Receipt printed)." << endl;
    }
};


class PaymentFactory {
public:
    
    static Payment* create(const char* mode) {
        if (strcasecmp(mode, "CreditCard") == 0) {
            return new CreditCard();
        } else if (strcasecmp(mode, "UPI") == 0) {
            return new UPI();
        } else if (strcasecmp(mode, "Cash") == 0) {
            return new Cash();
        } else {
            return nullptr;
        }
    }
};


int main() {
    char mode[20];
    double amount;

    cout << "Enter Payment Mode (CreditCard, UPI, Cash): ";
    cin >> mode;
    cout << "Enter Amount: ";
    cin >> amount;

    
    Payment* myPayment = PaymentFactory::create(mode);

    if (myPayment != nullptr) {
        myPayment->makePayment(amount);
        delete myPayment; 
    } else {
        cout << "Error: Invalid payment mode entered." << endl;
    }

    return 0;
}