 #include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10];  

public:
    
    void input() {
        cout << "Enter rows and columns: ";
        cin >> rows >> cols;

        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    
    Matrix operator+(Matrix m) {
        Matrix result;
        result.rows = rows;
        result.cols = cols;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    
    Matrix operator-(Matrix m) {
        Matrix result;
        result.rows = rows;
        result.cols = cols;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return result;
    }

    
    Matrix operator*(Matrix m) {
        Matrix result;
        result.rows = rows;
        result.cols = m.cols;

        
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                result.mat[i][j] = 0;
            }
        }

        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix m1, m2, sum, diff, prod;

    cout << "Enter Matrix 1:\n";
    m1.input();

    cout << "\nEnter Matrix 2:\n";
    m2.input();

    
    sum = m1 + m2;
    diff = m1 - m2;
    prod = m1 * m2;

    cout << "\nSum:\n";
    sum.display();

    cout << "\nDifference:\n";
    diff.display();

    cout << "\nProduct:\n";
    prod.display();

    return 0;
}