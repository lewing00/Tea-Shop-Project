// Program created by LeeAnna Ewing 
/* This program is for a local Tea shop. Via a menu it allows a user to process
single orders or multiple random orders. It displays menus for type of tea as 
well as size. It accepts user input for type of order or action, number of 
orders, selections, and customer name. It calculates the cost of each order and 
displays that information. This program also has input validation and allows 
the user an infinite number of times to enter the correct menu selections and 
order number.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	string customerName;						// To store customer name
	
	const double PLAIN_TEA = 0.43,				// Cost per ounce based on type of tea
				 BLACK_TEA = 0.53,
				 GREEN_TEA = 0.65,
				 WHITE_TEA = 0.78,
				 SALES_TAX = 0.045,				// Current sales tax in decimal form
				 SMALL_TEA = 8.0,				// Ounces of tea based on size 
				 MEDIUM_TEA = 16.0,
				 LARGE_TEA = 24.0; 
				 
				 
	const int TEA_MIN_VALUE = 1,				// Range Control for random orders
			  TEA_MAX_VALUE = 4,
			  SIZE_MIN_VALUE = 1,
			  SIZE_MAX_VALUE = 3;
			  
	int actionChoice,							// To store user input for Action Menu
		numberOfOrders,							// To store user input for random orders to create
		teaChoice,								// To store user input for Tea Menu
	    sizeChoice,								// To store user input for Size Menu
		randTeaType,							// To store randomly generated tea type
		randSize;								// To store randomly generated tea size
	    
	double	teaPrice,							// To store the product of Cost per ounce(Tea type) and ounces(size) 
			teaTax,								// To store the product of teaprice and sales tax
			teaTotalCost;						// To store the sum of teaprice and teatax
			
	unsigned seed = time(0);					// Get system time
	
	srand(seed);								// Seed random number generator;

	// Display Action menu and collect user input	
	do
	{

		cout << "\n\nWelcome to the World's Best Tea Shop\n"
		 << "\n1-Process a Single Order\n"
		 << "\n2-Process Multiple Orders\n"
		 << "\n3-Quit\n";
		cout << "\n\nEnter choice of action: ";
		cin >> actionChoice;
	
		while (actionChoice < 1 || actionChoice > 3)
		{
			cout << "\n\nERROR: INVALID MENU CHOICE. PLEASE TRY AGAIN: ";
			cin >> actionChoice;
		}

		// Single order process
		if (actionChoice == 1)
		{
			cout << "\n\n1-Plain Tea\n"
				 << "\n2-Black Tea\n"
				 << "\n3-Green Tea\n"
				 << "\n4-White Tea\n";
 			cout << "\n\nEnter choice of Tea: ";
 			cin >> teaChoice;
 	
 			// Validate user input
 			while (teaChoice < 1 || teaChoice > 4)
 			{	
 				cout << "\n\nERROR: INVALID MENU CHOICE. PLEASE TRY AGAIN: ";
 				cin >> teaChoice;		
 			}
 
 			// Display tea size menu and collect user input
 			cout << "\n\n\n1-Small(8oz)\n"
	 	 		 << "\n2-Medium(16oz)\n"
 	  	 		 << "\n3-Large(24oz)\n";
 			cout << "\n\nEnter choice of size: ";
 			cin >> sizeChoice;
 			cin.ignore();							// Skip newline character for getline
 	
			// Validate user input	
 			while (sizeChoice < 1 || sizeChoice > 3)
 			{		
 				cout << "\n\nERROR: INVALID MENU CHOICE. PLEASE TRY AGAIN: ";
 				cin >> sizeChoice;
 				cin.ignore();
			}
	
			// Collect customer name
			cout << "\n\nEnter the name of the customer: ";
			getline(cin, customerName); 

			// Set teaPrice to appropriate cost per ounce charge based on user input	
			if (teaChoice == 1)
				teaPrice = PLAIN_TEA;
			else if (teaChoice == 2)
				teaPrice = BLACK_TEA;
			else if (teaChoice == 3)
				teaPrice = GREEN_TEA;
			else if (teaChoice == 4)
				teaPrice = WHITE_TEA;
	
			// Calculate the new value of teaprice when it's value is multiplied by the ounces of the size selected by the user
			if (sizeChoice == 1)
				teaPrice *= SMALL_TEA;
			else if (sizeChoice == 2)
				teaPrice *= MEDIUM_TEA;
			else if (sizeChoice == 3)
				teaPrice *= LARGE_TEA;
		
			// Calculate the tax on the tea and then add it to the teaPrice to get a final cost
			teaTax = teaPrice * SALES_TAX;
			teaTotalCost = teaPrice + teaTax;
	
			// Format output
			cout << setprecision(2) << fixed << showpoint;	// This compiler seems to show trailing zeros without showpoint, but just in case
	
			// Display all results
			cout << "\n\n" << customerName << endl;
			cout << "\nPrice of tea: $" << teaPrice << endl;
			cout << "\nSales Tax: $" << teaTax << endl;
			cout << "\nTotal Amount Owed: $" << teaTotalCost << endl;
		} //if actionChoice1
		
		
		// multiple random order process
		if (actionChoice == 2)
		{
			cout << "\nEnter the number of orders(Min: 1-Max: 10): ";
			cin >> numberOfOrders;
			
			// Validate user input
			while (numberOfOrders < 1 || numberOfOrders > 10)
			{
				cout << "\n\nERROR: INVALID NUMBER CHOICE. PLEASE TRY AGAIN: ";
				cin >> numberOfOrders;
			}
		
			// Run for loop for user defined number of orders.			
			for (int count = 1; count <= numberOfOrders; count++)
			{
				// Assign random but controled values to Tea Type and Size.
				randTeaType = (rand() % (TEA_MAX_VALUE - TEA_MIN_VALUE +1)) + TEA_MIN_VALUE;
				randSize = (rand() % (SIZE_MAX_VALUE - SIZE_MIN_VALUE +1)) + SIZE_MIN_VALUE;
				
				// Display randomly selected tea type and assign price.
				if (randTeaType == 1)
					{
						cout << "\n\nTea Type: Plain Tea\n";
						teaPrice = PLAIN_TEA;
					}
				else if (randTeaType == 2)
					{
						cout << "\n\nTea Type: Black Tea\n";
						teaPrice = BLACK_TEA;
					}
				else if (randTeaType == 3)
					{
						cout << "\n\nTea Type: Green Tea\n";
						teaPrice = GREEN_TEA;
					}
				else if (randTeaType == 4)
					{
						cout << "\n\nTea Type: White Tea\n";
						teaPrice = WHITE_TEA;
					}
				
				// Display randomly selected size and update tea price.	
				if (randSize == 1)
					{
						cout << "\nSize: 8 oz\n";
						teaPrice *= SMALL_TEA;
					}
				else if (randSize == 2)
					{
						cout << "\nSize: 16 oz\n";
						teaPrice *= MEDIUM_TEA;
					}
				else if (randSize == 3)
					{
						cout << "\nSize: 24 oz\n";
						teaPrice *= LARGE_TEA;
					}
				
				// Calculate tax and final cost.	
				teaTax = teaPrice * SALES_TAX;
				teaTotalCost = teaPrice + teaTax;
				
				// Format output
				cout << setprecision(2) << fixed << showpoint;	
				
				cout << "\nPrice of tea: $" << teaPrice << endl;
				cout << "\nSales Tax: $" << teaTax << endl;
				cout << "\nTotal Amount Owed: $" << teaTotalCost << endl;
		
			}//for loop
		}//if actionchoice2
	} /*do while loop*/ while (actionChoice != 3);
		cout << "\n\nThank you for using our program.\n";
		return 0;
}// fine

