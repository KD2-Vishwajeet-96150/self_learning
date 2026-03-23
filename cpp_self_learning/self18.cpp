 #include <iostream>
#include <stdexcept>

// Generic Array class using templates
template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    // Constructor
    Array(size_t s) : size(s) {
        data = new T[size]; // Dynamic allocation
    }

    // Destructor to prevent memory leakage
    ~Array() {
        delete[] data;
    }

    // Copy Constructor (Deep Copy) to prevent double-free errors
    Array(const Array& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Overloading Assignment Operator (=)
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data; // Clean up existing memory
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Overloading Subscript Operator ([]) for element access
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    size_t getSize() const { return size; }
};

// Example User-Defined Data Type
struct Student {
    std::string name;
    int id;

    // Default constructor required for array allocation
    Student() : name("Unknown"), id(0) {}
    Student(std::string n, int i) : name(n), id(i) {}
};

int main() {
    try {
        Array<Student> classList(2);
        classList[0] = Student("Alice", 101);
        classList[1] = Student("Bob", 102);

        for (size_t i = 0; i < classList.getSize(); ++i) {
            std::cout << "ID: " << classList[i].id << ", Name: " << classList[i].name << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
