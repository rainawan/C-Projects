/*
*   Raina Wan
*   Quadratic Formula Calculator
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //variable declaration
    double numA, numB, numC, discriminant, ans1, ans2;

    //user interface
    cout << "Quadratic Formula Calculator:\n" << endl;
    cout << "First, enter the numerical value for 'a': ";
    cin >> numA;
    cout << "Now enter the numerical value for 'b': ";
    cin >> numB;
    cout << "Finally, enter the numerical value for 'c': ";
    cin >> numC;

    //trace through following if denominator is zero
    if (numA == 0)
    {
        cout << endl << "This is not a quadratic equation.";
        if (numB == 0)
        {
            cout << endl << "a = 0" << endl << "b = 0" << endl << "Goodbye!";
        }
        else
        {
            ans1 = -numC / numB;
            cout << "There is one solution: " << endl << "x = ";
            cout << ans1;
        }
    }

    //trace through following if denominator is not equal to zero
    else
    {
        discriminant = pow(numB, 2) - (4 * numA * numC);

        if (discriminant < 0)
        {
            cout << endl << "No real answer. You cannot take the square root of a negative value.\n";
        }
        else if (discriminant == 0)
        {
            ans1 = -numB / (2 * (numA));
            cout << endl << "There is one solution:\n";
            cout << "x = " << ans1 << endl;
        }
        else
        {
            ans1 = (-numB + sqrt(discriminant)) / (2 * numA);
            ans2 = (-numB - sqrt(discriminant)) / (2 * numA);
            cout << endl << "There are two solutions:\n";
            cout << "x = " << ans1 << endl;
            cout << "x = " << ans2 << endl;
        }
    }
    return 0;
}