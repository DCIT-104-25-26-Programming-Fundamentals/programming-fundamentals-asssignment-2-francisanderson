// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
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
void printFibonacci(int n);
void checkFibonacci(int number);


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


// PART A - Print first N Fibonacci terms
void printFibonacci(int n)
{
    if (n <= 0)
    {
        cout << "Number of terms must be positive.\n";
        return;
    }


    int first = 0;
    int second = 1;


    cout << "Fibonacci sequence: ";


    for (int i = 0; i < n; i++)
    {
        cout << first << " ";


        int next = first + second;

        first = second;
        second = next;
    }


    cout << endl;
}



// PART B - Check Fibonacci number
void checkFibonacci(int number)
{
    if (number < 0)
    {
        cout << number << " is NOT a Fibonacci number.\n";
        return;
    }


    int first = 0;
    int second = 1;


    while (first <= number)
    {
        if (first == number)
        {
            cout << number << " is a Fibonacci number.\n";
            return;
        }


        int next = first + second;

        first = second;
        second = next;
    }


    cout << number << " is NOT a Fibonacci number.\n";
}



int main()
{
    while (true)
    {
        string choice;


        cout << "\n===== FIBONACCI PROGRAM =====\n";
        cout << "1. Print First N Fibonacci Terms\n";
        cout << "2. Check Fibonacci Number\n";
        cout << "Q. Quit\n";
        cout << "Enter choice: ";

        cin >> choice;


        if (choice == "q" || choice == "Q")
        {
            break;
        }


        else if (choice == "1")
        {
            int n;

            getInt("How many terms? ", n);

            printFibonacci(n);
        }


        else if (choice == "2")
        {
            int number;

            getInt("Enter a number to check: ", number);

            checkFibonacci(number);
        }


        else
        {
            cout << "Invalid choice. Enter 1, 2 or Q.\n";
        }
    }


    cout << "Program ended.\n";

    return 0;
}

