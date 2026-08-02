// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;


// Function prototypes
bool getInt(string message, int &value);
bool getDouble(string message, double &value);
double calculateSum(double numbers[], int size);
double calculateAverage(double numbers[], int size);
double calculateMaximum(double numbers[], int size);
double calculateMinimum(double numbers[], int size);



// Integer input validation
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

            cout << "Invalid input. Enter a number.\n";
        }
    }
}



// Double input validation
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



// Calculate sum
double calculateSum(double numbers[], int size)
{
    double sum = 0;


    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }


    return sum;
}



// Calculate average
double calculateAverage(double numbers[], int size)
{
    return calculateSum(numbers, size) / size;
}



// Calculate maximum
double calculateMaximum(double numbers[], int size)
{
    double maximum = numbers[0];


    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }


    return maximum;
}



// Calculate minimum
double calculateMinimum(double numbers[], int size)
{
    double minimum = numbers[0];


    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }


    return minimum;
}



int main()
{
    while (true)
    {
        string choice;


        cout << "   ARRAY STATISTICS CALCULATOR\n";
        cout << "1. Calculate Statistics\n";
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
            int size;


            getInt("How many numbers? ", size);



            if (size <= 0)
            {
                cout << "Number of values must be positive.\n";
                continue;
            }


            double numbers[100];



            for (int i = 0; i < size; i++)
            {
                getDouble("Enter number " + to_string(i + 1) + ": ",
                          numbers[i]);
            }



            cout << fixed << setprecision(2);


            cout << "\nResults:\n";
            cout << "Sum:     " 
                 << calculateSum(numbers, size)
                 << endl;

            cout << "Average: "
                 << calculateAverage(numbers, size)
                 << endl;

            cout << "Maximum: "
                 << calculateMaximum(numbers, size)
                 << endl;

            cout << "Minimum: "
                 << calculateMinimum(numbers, size)
                 << endl;
        }


        else
        {
            cout << "Invalid choice. Enter 1 or Q.\n";
        }
    }


    return 0;
}