// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int MAX = 10;

// Function prototypes
bool getInt(string message, int &value);
void inputMatrix(int matrix[10][10], int &rows, int &cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices(int A[10][10], int B[10][10], int rows, int cols);
void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int rowsB, int colsB);


// Get valid integer input
bool getInt(string message, int &value)
{
    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            return true;
        }

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number.\n";
        }
    }
}


// Input matrix
void inputMatrix(int matrix[10][10], int &rows, int &cols)
{
    while (true)
    {
        getInt("Enter number of rows (1-10): ", rows);
        getInt("Enter number of columns (1-10): ", cols);

        if (rows >= 1 && rows <= 10 &&
            cols >= 1 && cols <= 10)
        {
            break;
        }

        cout << "Rows and columns must be between 1 and 10.\n";
    }


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            getInt("Enter element [" + to_string(i) + "][" + 
                   to_string(j) + "]: ", matrix[i][j]);
        }
    }
}


// Display matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }

        cout << endl;
    }
}


// Part A - Transpose
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int result[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }


    cout << "\nTransposed Matrix:\n";
    displayMatrix(result, cols, rows);
}


// Part B - Addition
void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int result[10][10];


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }


    cout << "\nMatrix Addition Result:\n";
    displayMatrix(result, rows, cols);
}


// Part C - Multiplication
void multiplyMatrices(int A[10][10], int B[10][10],
                      int rowsA, int colsA,
                      int rowsB, int colsB)
{

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication not possible.\n";
        return;
    }


    int result[10][10] = {0};


    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    cout << "\nMatrix Multiplication Result:\n";
    displayMatrix(result, rowsA, colsB);
}



int main()
{
    while (true)
    {
        string choice;


        cout << "\n===== MATRIX OPERATIONS =====\n";
        cout << "1. Transpose Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "Q. Quit\n";
        cout << "Enter choice: ";

        cin >> choice;


        if (choice == "q" || choice == "Q")
        {
            break;
        }


        else if (choice == "1")
        {
            int matrix[10][10];
            int rows, cols;


            inputMatrix(matrix, rows, cols);


            cout << "\nOriginal Matrix:\n";
            displayMatrix(matrix, rows, cols);


            transposeMatrix(matrix, rows, cols);
        }


        else if (choice == "2")
        {
            int A[10][10], B[10][10];
            int rowsA, colsA, rowsB, colsB;


            cout << "\nEnter First Matrix\n";
            inputMatrix(A, rowsA, colsA);


            cout << "\nEnter Second Matrix\n";
            inputMatrix(B, rowsB, colsB);


            if (rowsA == rowsB && colsA == colsB)
            {
                addMatrices(A, B, rowsA, colsA);
            }
            else
            {
                cout << "Matrices must have the same size.\n";
            }
        }


        else if (choice == "3")
        {
            int A[10][10], B[10][10];
            int rowsA, colsA, rowsB, colsB;


            cout << "\nEnter Matrix A\n";
            inputMatrix(A, rowsA, colsA);


            cout << "\nEnter Matrix B\n";
            inputMatrix(B, rowsB, colsB);


            multiplyMatrices(A, B, rowsA, colsA, rowsB, colsB);
        }


        else
        {
            cout << "Invalid choice. Enter 1, 2, 3 or Q.\n";
        }
    }


    cout << "Program ended.\n";

    return 0;
}