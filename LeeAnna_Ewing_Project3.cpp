/* Created by LeeAnna Ewing 
This program is for a local Tea shop. Via a menu it allows a user to process
single orders or multiple random orders. It displays menus for type of tea as 
well as size. It accepts user input for type of order or action, number of 
orders, selections, and customer name. It calculates the cost of each order and 
displays that information. This program also has input validation and allows 
the user an infinite number of times to enter the correct menu selections and 
order number. The program has been modularized using functions.*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// declare function prototypes
void displayStartMenu(); 
double determineCostPerOz(int), 
	   determineNumberOunces(int),
	   calcPriceTea(double, double),
       calcSalesTax(double),
       calcCostBill(double, double);

// global constants
const double PLAIN_TEA = 0.43,
			 BLACK_TEA = 0.53,
			 GREEN_TEA = 0.65,
			 WHITE_TEA = 0.78,
			 SALES_TAX = 0.045,
			 SMALL_TEA = 8.0,				
			 MEDIUM_TEA = 16.0,
			 LARGE_TEA = 24.0; 

int main()
{
	// seed random time
	srand(time(0));
	
	// variables
	int menuChoice, 
		teaType, 
		size, 
		orders;
		
	double costPerOunce,
		   numberOunces,
		   priceOfTea, 
		   salesTax, 
		   totalOwed;
	
	string name;
	
	do
	{
		displayStartMenu();
		cin >> menuChoice;	
		
		if(menuChoice == 1)
		{
			// process a single order and display tea type menu
			cout << "\n\n1 - Plain Tea \n";
			cout << "2 - Black Tea \n";
			cout << "3 - Green Tea \n";
			cout << "4 - White Tea \n\n";
			cout << "Enter the choice of Tea: ";
			
			// get input of the type of tea
			cin >> teaType;
			
			// validate the input of the tea type; display an error and allow user to retry
			while(teaType < 1 or teaType > 4)
			{
				cout << "\nERROR: INVALID MENU CHOICE. PLEASE TRY AGAIN: ";
				cin >> teaType;
			}
			
			// get cost per ounce value based on user tea type selection
			costPerOunce = determineCostPerOz(teaType);
			
			// display the size menu
			cout << endl << endl;
			cout << "1 - Small (8 oz) \n";
			cout << "2 - Medium (16 oz) \n";
			cout << "3 - Large (24 oz) \n\n";
			cout << "Enter the choice of size: ";
			cin >> size;
			
			// validate the input of the size; display an error and allow user to retry
			while(size < 1 or size > 3)
			{
				cout << "\nERROR: INVALID MENU CHOICE. PLEASE TRY AGAIN: ";
				cin >> size;
			}
			
			// get number of ounces of tea based on user size selection
			numberOunces = determineNumberOunces(size);
			
			// clear the buffer for getline
			cin.ignore();
			
			// get the input of the name of the customer
			cout << "\nEnter the name of the customer: ";
			getline(cin, name);
			
			// get the price of the tea
			priceOfTea = calcPriceTea(costPerOunce, numberOunces);
			
			// get the sales tax based on the price of the tea
			salesTax = calcSalesTax(priceOfTea);
			
			// get the customers total
			totalOwed = calcCostBill(priceOfTea, salesTax);
			
			// use setprecision to format dollar amounts to 2 decimal places
			cout << setprecision(2) << showpoint << fixed;
			cout << endl << name << endl;
			cout << "Price of Tea: $" << priceOfTea << endl;
			cout << "Sales Tax: $" << salesTax << endl;
			cout << "Total Amount Owed: $" << totalOwed << endl << endl;
			
		}
		else if(menuChoice == 2)
		{
			// process multiple orders
			cout << "\nEnter the number of orders (Min: 1 - Max: 10): ";
			cin >> orders;
			
			// validate the number of orders; display an error and get another input
			while(orders < 1 or orders > 10)
			{
				cout << "\nERROR: MUST ENTER BETWEEN 1 AND 10 ORDERS. TRY AGAIN.\n";
				cout << "\nEnter the number of orders (Min: 1 - Max: 10): ";
				cin >> orders;
			}
			
			// for-loop creates, calculates, and displays all of the bills in the order
			for(int orderNumber = 1; orderNumber <= orders; orderNumber++)
			{
				// generate a tea type for the order
				teaType = 1 + rand() % 4;
				
				// generate a size for the order
				size = 1 + rand() % 3;
				
				// get cost per ounce value based on random tea type selection
				costPerOunce = determineCostPerOz(teaType);
				
				// get number of ounces of tea based on random size selection
				numberOunces = determineNumberOunces(size);
				
				// get the price of the tea
				priceOfTea = calcPriceTea(costPerOunce, numberOunces);
			
				// get the sales tax based on the price of the tea
				salesTax = calcSalesTax(priceOfTea);
			
				// get the random orders' total
				totalOwed = calcCostBill(priceOfTea, salesTax);
				
				// use setprecision to format dollar amounts to 2 decimal places
				cout << setprecision(2) << showpoint << fixed;

				// display the tea type 
				switch(teaType)
				{
					case 1:
						cout << "Tea Type: Plain Tea \n";
						break;
					case 2:
						cout << "Tea Type: Black Tea \n";
						break;
					case 3:
						cout << "Tea Type: Green Tea \n";
						break;
					default:
						cout << "Tea Type: White Tea \n";
						break;
				}
				
				// display the the size
				switch(size)
				{
					case 1:
						cout << "Size: 8 oz \n";
						break;
					case 2:
						cout << "Size: 16 oz \n";
						break;
					default:
						cout << "Size: 24 oz \n";
						break;
				}
				
				cout << "Price of Tea: $" << priceOfTea << endl;
				cout << "Sales Tax: $" << salesTax << endl;
				cout << "Total Amount Owed: $" << totalOwed << endl << endl;
			}// for-loop
		}// else if menu choice 2
		else if(menuChoice == 3)
		{
			// choose to quit
			cout << "\nThank you for using our program. \n";
		}
		else
		{
			// validate the menu choice; display an error, then re-display the menu
			cout << "\nERROR: INVALID MENU CHOICE. TRY AGAIN \n\n";
		}
		
	}while(menuChoice != 3);
	
}//fine

//Functions

// A void function that just displays the first menu. 
void displayStartMenu()
{
	// display the processing menu
	cout << "Welcome to the World's Best Tea Shop\n\n";
	cout << "1 - Process Single Order \n";
	cout << "2 - Process Multiple Orders \n";
	cout << "3 - Quit \n\n";
	cout << "Enter choice of action: ";	
}

// A function that accepts the user�s menu choice for type of tea and returns the price per ounce.
double determineCostPerOz(int teaType)
{	
	double costPerOunce;
	
	if (teaType == 1)
		costPerOunce = PLAIN_TEA;
	else if (teaType == 2)
		costPerOunce = BLACK_TEA;
	else if (teaType == 3)
		costPerOunce = GREEN_TEA;
	else if (teaType == 4)
		costPerOunce = WHITE_TEA;
				
	return costPerOunce;
}

// A function that accepts the user�s menu choice for size of tea and returns the number of ounces.
double determineNumberOunces(int size)
{
	double numberOunces;

	if (size == 1)
	numberOunces = SMALL_TEA;
	else if (size == 2)
	numberOunces = MEDIUM_TEA;
	else if (size == 3)
	numberOunces = LARGE_TEA;
				
	return numberOunces;
}

// A function that accepts the price per ounce and the number of ounces purchased and returns the price of the tea.
double calcPriceTea(double costPerOunce, double numberOunces)
{
	double priceOfTea;
	
	priceOfTea = costPerOunce * numberOunces;
	
	return priceOfTea;
}

// A function that accepts the price of the tea and returns the sales tax owed.
double calcSalesTax(double priceOfTea)
{
	double salesTax;
	
	salesTax = priceOfTea * SALES_TAX;
	
	return salesTax;
}

// A function that accepts the price of the tea and the sales tax and returns the total amount owed.
double calcCostBill(double priceOfTea, double salesTax)
{
	double totalOwed;
	
	totalOwed = priceOfTea + salesTax;
	
	return totalOwed;
}



