/*
*	Raina Wan
*	Purpose: Calculate the highest, lowest, average, and median sneaker prices.
*	Objective: Demonstrate my understanding of call-by-value and call-by-reference
*		   functions, traversing and sorting through an array, and nested loops.
*/

#include <iostream>
using namespace std;

const int SIZE = 20;

void fillArray(double a[], int size, int& newSize);
	//Allows user to input sneaker prices
void displayArray(double a[], int newSize);
	//Displays highest, lowest, average, and median prices
double highestPrice(double a[], int newSize);
	//Calculates highest price from array items[SIZE]
double lowestPrice(double a[], int newSize, double maxNum);
	//Calculates lowest price from array items[SIZE]
double averagePrice(double a[], int newSize);
	//Calculates average price from array items[SIZE]
double medianPrice(double a[], int newSize);
	//Calculates median price from array items[SIZE]


int main()
{
	double items[SIZE];
	int newSize;

	fillArray(items, SIZE, newSize);
	displayArray(items, newSize);

	return 0;
}

void fillArray(double a[], int size, int& newSize)
{
	double price;
	int i = 0;
	newSize = 0;
	cout << "Welcome to Raina's Bitmoji Sneaker Store!\n"
		<< "Allow me to help you layout the highest, lowest, average, and median\n"
		<< "prices of your sneaker options.\n"
		<< "\nPlease enter up to " << size << " prices in dollars and\n"
		<< "cents separated by white space.\n"
		<< "Enter a zero after the last price if less than " << size << " items: ";
	cin >> price;

	while (i < size && price != 0) //user interface
	{
		a[i] = price;
		i++;
		cin >> price;
	}

	newSize = i;
}

void displayArray(double a[], int newSize)
{
	double maxNum = highestPrice(a, newSize);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "\nThere are " << newSize << " items\n"
		<< "Highest price is $" << highestPrice(a, newSize)
		<< "\nLowest price is $" << lowestPrice(a, newSize, maxNum)
		<< "\nAverage price is $" << averagePrice(a, newSize)
		<< "\nMedian price is $" << medianPrice(a, newSize);
}


double highestPrice(double a[], int newSize)
{
	double maxNum = 0.0;

	for (int i = 0; i < newSize; i++)
	{
		if (a[i] > maxNum)
		{
			maxNum = a[i];
		}
	}
	return maxNum;
}

double lowestPrice(double a[], int newSize, double maxNum)
{
	double minNum = maxNum;

	for (int i = 0; i < newSize; i++)
	{
		if (a[i] < minNum)
		{
			minNum = a[i];
		}
	}
	return minNum;
}

double averagePrice(double a[], int newSize)
{
	double sum = 0.0;
	for (int i = 0; i < newSize; i++)
	{
		sum += a[i];
	}
	return (sum / newSize);
}

double medianPrice(double a[], int newSize)
{
	//rearrange array
	for (int i = 0; i < newSize; i++)
	{
		for (int j = 0; j < newSize; j++)
		{
			if (a[j] == 0) {
				break;
			}
			if (a[j] < a[i + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	//return median price
	if (newSize % 2 != 0) {
		return a[newSize / 2];
	}
	if (newSize % 2 == 0) {
		return (a[newSize / 2] + a[newSize / 2 - 1]) / 2;
	}
}
