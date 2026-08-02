// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <limits>
#include <string>
using namespace std;


// Function prototypes
bool isPrime(int number);
bool getInt(string message, int &value);



// Input validation
bool getInt(string message, int &value)
{
    while (true)
    {
        cout << message;


        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }


        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a whole number.\n";
        }
    }
}



// Prime number checker
bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }


    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }


    return true;
}



int main()
{
    while (true)
    {
        string choice;


        cout << "      PRIME NUMBER CHECKER\n";
        cout << "1. Check Prime Number\n";
        cout << "Q. Quit\n";
        cout << "Enter choice: ";


        cin >> choice;



        if (choice == "q" || choice == "Q")
        {
            cout << "Goodbye!\n";
            break;
        }


        else if (choice == "1")
        {
            int number;


            getInt("Enter a number: ", number);



            if (isPrime(number))
            {
                cout << number << " is a prime number.\n";
            }

            else
            {
                cout << number << " is NOT a prime number.\n";
            }
        }


        else
        {
            cout << "Invalid choice. Enter 1 or Q.\n";
        }
    }


    return 0;
}