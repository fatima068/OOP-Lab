/*Write a C++ program that:
     Dynamically allocates a 2D array using pointers (not using vector or standard containers).
     Fills the array with random integers between 1 and 100.
     Pass the 2D array to function to perform these tasks:
     Calculates and prints The sum of all elements in the array.
     Calculates and prints The sum of each row and each column.
     Calculates and prints The row and column with the highest sum.
     Pass the 2D array to a function to transpose the matrix and print the resulting matrix.
Free the dynamically allocated memory.
Note:
Use functions to perform the calculations and matrix operations (do not write all code inside main()). Handle edge cases, such as when the array has no elements or is improperly allocated.

Sample Output:

Original Matrix:
[ 12 35 56 ]
[ 8 45 67 ]
[ 23 54 34 ]
Sum of all elements: 434
Row sums: 103, 120, 111
Column sums: 43, 134, 157
Row with highest sum: Row 2
Column with highest sum: Column 3

Transposed Matrix:
[ 12 8 23 ]
[ 35 45 54 ]
[ 56 67 34 ]*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sumAll(int** matrix, int rows, int cols);
void sumRow(int** matrix, int rows, int cols);
void sumCol(int** matrix, int rows, int cols);
void highestRow(int** matrix, int rows, int cols);
void highestCol(int** matrix, int rows, int cols);
void transpose(int** matrix, int rows, int cols);

int main (){
    int rows, cols;
    cout << "Enter rows and cols" << endl; ;
    cin >> rows;
    cin >> cols;

    //dynamically allocating memory
    int** matrix = new int*[rows];
    for (int i = 0; i<rows; i++){
        matrix[i] = new int[cols];
    }

    //filling with random integers
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1; 
        }
    }

    //print the generated array
    cout << "\nRANDOMLY GENERATED ARRAY" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //performing given functions on the 2d array
    sumAll(matrix, rows, cols);
    sumRow(matrix, rows, cols);
    sumCol(matrix, rows, cols);
    highestRow(matrix, rows, cols);
    highestCol(matrix, rows, cols);
    transpose(matrix, rows, cols);

    //freeing the memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }

    delete[] matrix;  
}

void sumAll(int** matrix, int rows, int cols){
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    cout << "Sum of all elements is " << sum << endl;
}

void sumRow(int** matrix, int rows, int cols){
    cout << "row sums: ";
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];  
        }
        cout << sum << " ";
    }
    cout << endl;
}

void sumCol(int** matrix, int rows, int cols){
    cout << "column sums: ";
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void highestRow(int** matrix, int rows, int cols) {
    int highestRowIndex = 0;
    int highestRowSum = 0;

    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];  
        }
        
        if (rowSum > highestRowSum) {
            highestRowSum = rowSum;
            highestRowIndex = i;
        }
    }

    cout << "\nRow with the highest sum: " << highestRowIndex + 1 << endl;
}

void highestCol(int** matrix, int rows, int cols) {
    int highestColIndex = 0;
    int highestColSum = 0;

    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j]; 
        }

        if (colSum > highestColSum) {
            highestColSum = colSum;
            highestColIndex = j;
        }
    }

    cout << "\nColumn with the highest sum: " << highestColIndex + 1 << endl;
}

void transpose(int** matrix, int rows, int cols) {

    int** transposed = new int*[cols];
    for (int i = 0; i < cols; i++) {
        transposed[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j]; 
        }
    }

    cout << "\nTransposed Matrix:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}
