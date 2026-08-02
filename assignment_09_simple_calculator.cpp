// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
using namespace std;


// Function prototypes
bool getDouble(string message, double &value);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double &result);
int modulus(int a, int b);
double exponent(double base, int power);



// Input validation
bool getDouble(string message, double &value)
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

            cout << "Invalid input. Enter a number.\n";
        }
    }
}



// Addition
double add(double a, double b)
{
    return a + b;
}



// Subtraction
double subtract(double a, double b)
{
    return a - b;
}



// Multiplication
double multiply(double a, double b)
{
    return a * b;
}



// Division
bool divide(double a, double b, double &result)
{
    if (b == 0)
    {
        return false;
    }


    result = a / b;

    return true;
}



// Modulus
int modulus(int a, int b)
{
    return a % b;
}



// Exponentiation
double exponent(double base, int power)
{
    double result = 1;


    for (int i = 0; i < power; i++)
    {
        result *= base;
    }


    return result;
}



int main()
{
    while (true)
    {
        string choice;


        cout << "       SIMPLE CALCULATOR\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";


        cin >> choice;


        if (choice == "7" || choice == "q" || choice == "Q")
        {
            cout << "Goodbye!\n";
            break;
        }


        else if (choice >= "1" && choice <= "6")
        {
            double first, second;


            getDouble("Enter first number: ", first);
            getDouble("Enter second number: ", second);



            cout << fixed << setprecision(2);


            if (choice == "1")
            {
                cout << "Result: "
                     << add(first, second)
                     << endl;
            }


            else if (choice == "2")
            {
                cout << "Result: "
                     << subtract(first, second)
                     << endl;
            }


            else if (choice == "3")
            {
                cout << "Result: "
                     << multiply(first, second)
                     << endl;
            }


            else if (choice == "4")
            {
                double result;


                if (divide(first, second, result))
                {
                    cout << "Result: "
                         << result
                         << endl;
                }
                else
                {
                    cout << "Error: Cannot divide by zero.\n";
                }
            }


            else if (choice == "5")
            {
                if ((int)second == 0)
                {
                    cout << "Error: Cannot perform modulus by zero.\n";
                }
                else
                {
                    cout << "Result: "
                         << modulus((int)first, (int)second)
                         << endl;
                }
            }


            else if (choice == "6")
            {
                cout << "Result: "
                     << exponent(first, (int)second)
                     << endl;
            }
        }


        else
        {
            cout << "Invalid choice. Enter 1-7 or Q.\n";
        }
    }


    return 0;
}

