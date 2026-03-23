 #include <iostream>
#include <string>
#include <vector>

using namespace std;


class Product {
protected:
    string title;
    float price;

public:
    virtual void accept() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    
    virtual void display() = 0; 
    
    
    virtual ~Product() {}
};


class Book : public Product {
    int pages;

public:
    void accept() override {
        Product::accept();
        cout << "Enter number of pages: ";
        cin >> pages;
    }

    void display() override {
        cout << "Pages: " << pages << endl;
    }
};


class Tape : public Product {
    float playtime;

public:
    void accept() override {
        Product::accept();
        cout << "Enter playtime (mins): ";
        cin >> playtime;
    }

    void display() override {
        cout << "Playtime: " << playtime << " mins" << endl;
    }
};

int main() {
    Product *arr[5]; 
    int choice;

    for (int i = 0; i < 5; i++) {
        cout << "\nItem " << i + 1 << " - 1. Book, 2. Tape. Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arr[i] = new Book();
                arr[i]->accept();
                break;
            case 2:
                arr[i] = new Tape();
                arr[i]->accept();
                break;
            default:
                cout << "Invalid choice, defaulting to Book." << endl;
                arr[i] = new Book();
                arr[i]->accept();
                break;
        }
    }

    
    cout << "\n--- Specific Details (Pages/Playtime) ---" << endl;
    for (int i = 0; i < 5; i++) {
        arr[i]->display();
    }

    
    for (int i = 0; i < 5; i++) {
        delete arr[i];
    }

    return 0;
}