/*
Name: Store Manager Game
Author: Robert Stivanson
Created: 2012
Repo: https://github.com/RobertStivanson/Store-Manager-Game

This is the revised code for the Store Manager Game. This code was written
during my second programming class in college. Compared to the original code,
this really shows how I have grown as a developer. My approach to the problems
posed by the intended product changed dramatically.

*/

#include <iostream> // cout, cin
#include <iomanip> // setw, setfill
#include <string> // string
#include <cstdlib> // srand, rand
#include <time.h> // time
#include "store.h"

using namespace std;

const int WIN_MONEY_AMOUNT = 10000000;
const int EMPLOYEE_HIRE_COST = 250;

int GetAction(string message, int min, int max);
void DisplayMainMenu();
void DisplayInstructions();
void DisplayHeader(Store & store);
void PlayGame();
void PurchaseStock(Store & store);
void ViewStock(Store & store);
void HireEmployees(Store & store);

// main
// Entrance point into the program
int main() {
	srand(time(NULL));
	
	cout << "Welcome to the Store Manager Game" << endl;
	cout << "Main Menu" << endl;
	cout << "\t1. New Game" << endl;
	cout << "\t2. Instructions" << endl;
	
	switch (GetAction("Please select a menu option.", 1, 3)) {
		case 1:
			PlayGame();
			break;
		case 2:
			DisplayInstructions();
			cout << endl;
			main();
			break;
	}
	
	// Pause so the user can read whatever is on the screen
	cin.get();
	
	return 0;
}

// GetAction
// string	message	The message to be displayed to the user.
// int		min		The minimum valid value that the user can give
// int		max		The maximum valid value that the user can give
int GetAction(string message, int min, int max) {
	int action;
	
	// Swap min and max if min is greater than max
	if (min > max) {
		int tmp = max;
		max = min;
		min = tmp;
	}
	
	// Prompt for an input, repeat while input is invalid.
	do {
		cout << message << endl;
		cout << " >>:  ";
		
		cin >> action;
	} while (action < min || action > max);
	
	// Buffer between this and the next print out
	cout << endl;
	
	return action;
}

// DisplayInstructions
// Print out the objecttive of the game for the user.
void DisplayInstructions() {
	cout << "The objective of this game is to raise $" << WIN_MONEY_AMOUNT << " in as few days as possible." << endl;
	cout << "Press any key to retun to the main menu." << endl;
	cin.get();
	
	return;
}

// DisplayHeader
// Store	store	The instance of the player's store
// int		day		The number of days it has been
void DisplayHeader(Store & store, int & day) {
	cout << "Day: " << day << endl;
	cout << "$" << store.GetMoney();
	cout << "\tEmployees: " << store.GetNumberOfEmployees();
	cout << endl;
}

// PlayGame
// Play the game, this function will NOT exist until the player wins
void PlayGame() {
	// Intialize the player
	Store store;
	int day = 1;
	
	store.AdjustMoney(10);
	store.AddEmployees(1);
	
	// Display the header for the player
	DisplayHeader(store, day);
	
	// While the player has not reached the target win amount
	while (store.GetMoney() < WIN_MONEY_AMOUNT) {
		// Display game menu and handle the Player's input
		cout << endl;
		cout << "What would you like to do?" << endl;
		cout << "\t1. View Stock" << endl;
		cout << "\t2. Purchase Stock" << endl;
		cout << "\t3. Hire Employees" << endl;
		cout << "\t4. Next Day" << endl;
		
		switch (GetAction("Please select a menu option.", 1, 4)) {
			case 1:
				ViewStock(store);
				break;
			case 2:
				PurchaseStock(store);
				break;
			case 3:
				HireEmployees(store);
				break;
			case 4:
				store.AddProfits();
				++day;
				break;
		}
		
		// Display the header for the next day
		DisplayHeader(store, day);
	}
	
	
	// Display win message
	cout << endl;
	cout << "You win! It took you " << day << " days!" << endl;
	cout << "Press any key to exit." << endl;
}


// PurchasseStock
// Store	store	The instance of the player's store
// Allows the player to purchase some of each item if they have the money
void PurchaseStock(Store & store) {
	cout << "Welcome to Jake's Market Restocker Services" << endl;
	cout << "Please select which items you would like to buy:" << endl;
	
	// For each item
	for (int id = 0; id < Store::NUM_STOCK_ITEMS; ++id) {
		StockItem item = store.GetItem(id);
		int toBuy, totalCost;
		
		// Print the item's information
		cout << setw(25) << setfill('-') << left << item.GetName() + ' ' << " You Own: " << item.GetQuantity() << endl;
		cout << setw(25) << left << item.GetName() + ' ' << " Cost: $" << item.GetPrice() << endl;
		
		// Prompt for purchase amount, repeat while invalid
		do {
			cout << "How many would you like to buy? ";
			cin >> toBuy;
			totalCost = toBuy * item.GetPrice();
			
			// If the store does not have enough money, print error
			if (store.GetMoney() < totalCost) {
				cout << "You do not have enough money for this transaction." << endl;
			}
			
			// If the totalCost is negative, print error
			if (totalCost < 0) {
				cout << "We have a strict no refund policy. You may purchase but not return items." << endl;
			}
		} while (totalCost < 0 && store.GetMoney() < totalCost);
		
		
		// Adjust the store's and item's values
		item.AdjustQuantity(toBuy);
		store.AdjustMoney(-totalCost);
		store.AdjustQuantity(id, toBuy);
		
		// Print success message for item purchase
		cout << "Transaction successful! You now have $" << store.GetMoney() << endl;
		
		cout << endl;
	}
}

// ViewStock
// Store	store	The instance of the player's store
// Displays the items in the store and their quantity
void ViewStock(Store & store) {
	cout << "Bob's General Market's Warehouse Inventory" << endl;
	
	// For each item print its information
	for (int id = 0; id < Store::NUM_STOCK_ITEMS; ++id) {
		StockItem item = store.GetItem(id);
		
		cout << setw(25) << setfill('-') << left << item.GetName() + ' ' << " Quantity: " << item.GetQuantity() << endl;
	}
	
	cout << endl;
	return;
}

// HireEmployees
// Store	store	The instance of the player's store
// Hire an amount of employees that is given by the player
void HireEmployees(Store & store) {
	// Display hiring information
	cout << "Hiring employees increasing the amount of your daily income." << endl;
	cout << "An employee costs $" << EMPLOYEE_HIRE_COST << " to hire." << endl;
	cout << "You currently have " << store.GetNumberOfEmployees() << endl;
	cout << "Would you like to hire another employee?" << endl;
	cout << "\t1. Yes" << endl;
	cout << "\t2. No" << endl;
	
	switch (GetAction("Please select a menu option.", 1, 3)) {
		case 1: // Yes
			int toHire, totalCost;
			
			// Get the amount of employees the Player wishes to hire, repeat while invalid.
			do {
				cout << "How many employees would you like to hire? ";
				cin >> toHire;
				totalCost = toHire * EMPLOYEE_HIRE_COST;
				
				// If the player does not have enough money display error
				if (store.GetMoney() < totalCost) {
					cout << "You do not have enough money for this transaction" << endl;
				}
				
				// IF the amount given is less than zero
				if (toHire < 0) {
					cout << "You cannot fire employees!" << endl;
				}
			} while (toHire < 0 || store.GetMoney() < totalCost);
			
			// Adjust the store's money and employees
			store.AddEmployees(toHire);
			store.AdjustMoney(-totalCost);
			
			break;
	}
}
