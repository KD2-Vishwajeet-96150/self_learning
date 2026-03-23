 #include <iostream>
using namespace std;


int myStrlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


void myStrcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  
}

int main() {
    char source[100], destination[100];

    cout << "Enter a string: ";
    cin.getline(source, 100);

    
    int len = myStrlen(source);
    cout << "Length of string: " << len << endl;

    
    myStrcpy(destination, source);
    cout << "Copied string: " << destination << endl;

    return 0;
}