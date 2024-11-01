#include <iostream>
using namespace std;
const int SIZE = 4; // Global variable for matrix size
class Matrix {
    private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
    public:
        // 1. Read values from stdin into a matrix
        void readFromStdin(){
            for(int i =0; i< SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    cin >> data[i][j];
            }   
            }
        }
        // 2. Display a matrix
        void display() const{
            for(int i =0; i< SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    cout << data[i][j] << " ";
            }   
            cout << endl;
            }
        }
        // 3. Add two matrices (operator overloading for +)
        Matrix operator+(const Matrix& other) const{
            Matrix ans;
            for(int i =0; i< SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    ans.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return ans;
        }
        // 4. Multiply two matrices (operator overloading for *)
        Matrix operator*(const Matrix& other) const{
            Matrix ans;
            for(int i =0; i< SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    int sum = 0;
                    for(int k=0; k<SIZE; k++){
                        sum += data[i][k]*other.data[k][j];
                    }
                    ans.data[i][j] = sum;
                }
            } 
            return ans;
        }
        // 5. Compute the sum of matrix diagonal elements
        int sumOfDiagonals() const{
            int d1 = 0;
            int d2 = 0;
            for(int i=0; i< SIZE; i++){
                d1 += data[i][i];
            }
            for(int j=0; j< SIZE; j++){
                d2 += data[j][j];
            }
            return d1+d2;

        }
        // 6. Swap matrix rows
        void swapRows(int row1, int row2){
            for(int i=0; i < SIZE; i++){
                int temp = data[row1][i];
                data[row1][i] = data[row2][i];
                data[row2][i] = temp;
            }
        }
    };
int main() {
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
return 0;
}
