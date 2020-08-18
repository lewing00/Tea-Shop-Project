// Program created by LeeAnna Ewing 6/9/2019 
/* This program is for a local Tea shop. It shows menus for type
of tea as well as size. It accepts user input for selections and
customer name. It calculates the cost of each order and displays
that information. This program also has input validation.*/

#include <iostream>
#include <iomanip>
#include <string>
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
				 
	int teaChoice,								// To store user input for Tea Menu
	    sizeChoice;								// To store user input for Size Menu
	    
	double	teaPrice,							// To store the product of Cost per ounce(Tea type) and ounces(size) 
			teaTax,								// To store the product of teaprice and sales tax
			teaTotalCost;						// To store the sum of teaprice and teatax

	// Display Tea menu and collect user input	
	cout << "Welcome to the World's Best Tea Shop\n\n"
		 << "\n1-Plain Tea\n"
		 << "\n2-Black Tea\n"
		 << "\n3-Green Tea\n"
		 << "\n4-White Tea\n";
 	cout << "\n\nEnter choice of Tea: ";
 	cin >> teaChoice;
 	
 	// Validate user input
 	if(teaChoice < 1 || teaChoice > 4)
 	{
 		cout << "\n\nERROR: INVALID MENU CHOICE. PROGRAM WILL TERMINATE.\n\n";
 		return 0;		
 	}
 
 	// Display tea size menu and collect user input
 	cout << "\n\n\n1-Small(8oz)\n"
	 	 << "\n2-Medium(16oz)\n"
 	  	 << "\n3-Large(24oz)\n";
 	cout << "\n\nEnter choice of size: ";
 	cin >> sizeChoice;
 	cin.ignore();							// Skip newline character for getline
 	
	// Validate user input	
 	if (sizeChoice < 1 || sizeChoice > 3)
 	{
 		cout << "\n\nERROR: INVALID MENU CHOICE. PROGRAM WILL TERMINATE.\n\n";
 		return 0;
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
	
	
	return 0;
}// fine

