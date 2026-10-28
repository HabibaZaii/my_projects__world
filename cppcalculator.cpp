#include <iostream>
using namespace std;

double calculator(double num1, double num2, char op, bool& success)
{
    success = true;

    switch (op)
    {
        case '+':
            return num1 + num2;

        case '-':
            return num1 - num2;

        case '*':
            return num1 * num2;

        case '/':
        	
            if (num2 == 0)
            {
                cout << "Error: Cannot divide by zero.\n";
                success = false;
                return 0;
            }
            return num1 / num2;

        case '%':
            if (num2 == 0)
            {
                cout << "Error: Cannot take modulus by zero.\n";
                success = false;
                return 0;
            }

            if (num1 != static_cast<int>(num1) ||
                num2 != static_cast<int>(num2))
            {
                cout << "\n\nError: Modulus requires whole numbers, not fractional.\n";
                success = false;
                return 0;
            }

            return static_cast<int>(num1) %
                   static_cast<int>(num2);

        default:
            cout << "Error: Invalid operator.\n";
            success = false;
            return 0;
    }
}

int main()
{
    double num1, num2, result;
    char op;
    char choice;
    bool success;

    cout << "====================";
    cout << "C++ CALCULATOR";
    cout << "====================\n";

    do
    {
        cout << "\nEnter first number: ";

        if (!(cin >> num1))
        {
            cout << "Invalid number input.\n";
            return 1;
        }

        cout << "\n\nEnter operator (+, -, *, /, %): ";
        cin >> op;

        cout << "\n\nEnter second number: ";

        if (!(cin >> num2))
        {
            cout << "Invalid number input.\n";
            return 1;
        }

        result = calculator(num1, num2, op, success);

        if (success)
        {
            cout << "\n\nResult: " << result << '\n';
        }

        cout << "\n\nDo you want to calculate again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThanks and goodbye!\n";

    return 0;
}

