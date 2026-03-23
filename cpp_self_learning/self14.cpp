 #include <iostream>
#include <string>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        
        if (amount < 0) {
            throw amount; 
        }
        balance += amount;
        std::cout << "Successfully deposited: $" << amount << ". New Balance: $" << balance << std::endl;
    }

    void withdraw(double amount) {
        
        if (amount < 0) {
            throw amount;
        }
        
        if (amount > balance) {
            throw std::string("Error: Insufficient funds for withdrawal.");
        }
        balance -= amount;
        std::cout << "Successfully withdrew: $" << amount << ". New Balance: $" << balance << std::endl;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(1000.0);

    
    double testAmounts[] = {500.0, -100.0, 1500.0, 200.0};

    for (double amt : testAmounts) {
        try {
            std::cout << "\nAttempting transaction of $" << amt << "..." << std::endl;
            
            
            if (amt > 0 && amt < 1000) {
                account.deposit(amt);
            } else {
                account.withdraw(amt);
            }
        } 
        
        catch (double e) {
            std::cerr << "Caught Exception: Invalid amount provided: $" << e << std::endl;
        } 
        
        catch (std::string e) {
            std::cerr << "Caught Exception: " << e << std::endl;
        }
    }

    std::cout << "\nFinal Balance: $" << account.getBalance() << std::endl;
    return 0;
}