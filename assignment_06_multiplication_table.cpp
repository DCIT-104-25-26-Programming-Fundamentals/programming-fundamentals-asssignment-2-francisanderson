// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <limits>
#include <string>
using namespace std;


// Function prototypes
bool getInt(string message, int &value);
void singleTable(int number);
void tablesFromOneToN(int n);


// Input validation
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



// PART A - Single multiplication table
void singleTable(int number)
{
    cout << "\nMultiplication Table for " << number << ":\n";


    for (int i = 1; i <= 12; i++)
    {
        cout << number << " x " << i 
             << " = " << number * i << endl;
    }
}



// PART B - Tables from 1 to N
void tablesFromOneToN(int n)
{
    if (n <= 0)
    {
        cout << "Number must be positive.\n";
        return;
    }


    for (int number = 1; number <= n; number++)
    {
        cout << "\nMultiplication Table for " << number << ":\n";


        for (int i = 1; i <= 12; i++)
        {
            cout << number << " x " << i 
                 << " = " << number * i << endl;
        }

    }
}



int main()
{
    while (true)
    {
        string choice;


        cout << "\n===== MULTIPLICATION TABLE GENERATOR =====\n";
        cout << "1. Generate Single Table\n";
        cout << "2. Generate Tables From 1 to N\n";
        cout << "Q. Quit\n";
        cout << "Enter choice: ";

        cin >> choice;


        if (choice == "q" || choice == "Q")
        {
            break;
        }


        else if (choice == "1")
        {
            int number;

            getInt("Enter number: ", number);

            singleTable(number);
        }


        else if (choice == "2")
        {
            int n;

            getInt("Enter N: ", n);

            tablesFromOneToN(n);
        }


        else
        {
            cout << "Invalid choice. Enter 1, 2 or Q.\n";
        }
    }


    cout << "Program ended.\n";

    return 0;
}