/*
*   Raina Wan
*   Purpose: Order a pizza!
*   Objectives: Demonstrate my understanding of programmer-defined functions, 
*               switch statements, loops, simple flow of control, and different data types.
*/

#include <iostream>
#include <string>
using namespace std;

const double TAX_RATE = 0.0795;

void welcome(string& name);
//customer enters their name

bool checkName(string name);
//boolean expression to check if name matches that of owners; 
//if yes, return true. if no, return false

void base(string& size, double& cost);
//if-else decision making to find cost of user's choice of size

string pizzaCrust(string crust);
//switch statement to string full crust name, given user's choice of crust

void pizzaToppings(string& toppings, int& toppingCounter);
//user inputs choice of toppings

void totalCost(double& subtotal, double& cost, int toppingCounter, string name);
//calculate subtotal, including crust, additional toppings, tax, and any discount rate

void receipt(string& size, string& crust, string& toppings, double& subtotal, double& cost);
//print out receipt

int main()
{
    string name, size, crust, toppings = "Cheese ";
    int toppingCounter = 0;
    double cost, subtotal;
    bool discount;

    welcome(name);
    discount = checkName(name);
    base(size, cost);
    crust = pizzaCrust(crust);
    pizzaToppings(toppings, toppingCounter);
    totalCost(subtotal, cost, toppingCounter, name);
    receipt(size, crust, toppings, subtotal, cost);
}

void welcome(string& name)
{
    cout << "Welcome to Raina's Pizzeria!" << endl
        << "Enter your first name: ";
    cin >> name;
}

bool checkName(string name)
{
    if (name == "Raina" || name == "raina")
        return true;
    else
        return false;
}

void base(string& size, double& cost)
{
    int numberSize;
    cout << endl << "What size pizza would you like?\n"
        << "10, 12, 14, 16 (enter the number only): ";
    cin >> numberSize;

    if (numberSize == 10) {
        size = "10-inch pizza";
        cost = 10.99;
    }
    else if (numberSize == 12) {
        size = "12-inch pizza";
        cost = 12.99;
    }
    else if (numberSize == 14) {
        size = "14-inch pizza";
        cost = 14.99;
    }
    else if (numberSize == 16) {
        size = "16-inch pizza";
        cost = 16.99;
    }
    else {
        size = "Size unavailable, you will get a 12 inch.";
        cost = 12.99;
    }

}

string pizzaCrust(string crust)
{
    char crustType;
    cout << endl << "What type of crust do you want?\n"
        << "(H) Hand-tossed, (T) Thin-crust, or (D) Deep-dish "
        << "(enter H, T, or D): ";
    cin >> crustType;

    switch (crustType)
    {
    case 'h':
    case 'H':
        crust = "Hand-tossed";
        break;

    case 'T':
    case 't':
        crust = "Thin-crust";
        break;

    case 'D':
    case 'd':
        crust = "Deep-dish";
        break;

    default:
        crust = "Crust unavailable, you will get hand-tossed.";
    }
    return crust;
}

void pizzaToppings(string& toppings, int& toppingCounter)
{
    char answer;
    cout << endl << "All pizzas come with cheese.\n"
        << "Additional toppings are $1.25 each, choose from:\n"
        << "Pepperoni, Sausage, Onion, Mushroom\n";

    cout << "Do you want Pepperoni?(Y/N): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        toppings = toppings + "Pepperoni ";
        toppingCounter++;
    }

    cout << "Do you want Sausage?(Y/N): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        toppings = toppings + "Sausage ";
        toppingCounter++;
    }

    cout << "Do you want Onion?(Y/N): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        toppings = toppings + "Onion ";
        toppingCounter++;
    }

    cout << "Do you want Mushroom?(Y/N): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        toppings = toppings + "Mushroom ";
        toppingCounter++;
    }
}

void totalCost(double& subtotal, double& cost, int toppingCounter, string name)
{
    if (checkName(name))
    {
        cout << endl << "You are eligible for a $2.00 discount!\n";
        cost -= 2.00;
    }

    cost += toppingCounter * 1.25;
    subtotal = cost;
    cost += cost * TAX_RATE;
}

void receipt(string& size, string& crust, string& toppings, double& subtotal, double& cost)
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << endl << "Your order is as follows:\n"
        << size << endl << crust << endl << toppings << endl
        << "The cost of your order is: " << subtotal << endl
        << "The tax is: $" << TAX_RATE << endl
        << "The total due is: $" << cost << endl
        << "Your order will be ready for pickup in 30 minutes." << endl;
}
