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

#include <cstdlib>
#include "store.h"

const int Store::NUM_STOCK_ITEMS = 7;

StockItem Store::ITEMS[] = {
	StockItem(0, "Apples", 10, 4),
	StockItem(1, "Milk", 10, 10),
	StockItem(2, "Banana", 10, 3),
	StockItem(3, "Orange", 10, 5),
	StockItem(4, "Potato Chips", 10, 7),
	StockItem(5, "Potato Chip Dip", 10, 5),
	StockItem(6, "Canned Goods", 10, 8),
	
	// Add new stock items before this.
	// Remember to update NUM_STOCK_ITEMS
	StockItem(-1, "NULL", 0, 0)
};

Store::Store() {
	money = 0;
	numberOfEmployees = 0;
	return;
}

// AddProfits
// Calculates profits based on the items  and adds the resulting number to the store's money
void Store::AddProfits() {
	int i, totalProfit = 0, random;
	
	// For each item
	for (i = 0; i < NUM_STOCK_ITEMS; ++i) {
		// Get a random number within the amount of the items quantity
		random = rand() % (ITEMS[i].GetQuantity() + 1);
		
		// Remove this amount from the item's stack amount
		// Simulates the items actually being purchased
		ITEMS[i].AdjustQuantity(-random);
		
		// Add the amount of items purchased multipled by their price plus a profit buffer
		totalProfit += random * (ITEMS[i].GetPrice() + 1);
	}
	
	// Calculate and add the profits
	money += totalProfit * numberOfEmployees;
}

// GetItem
// int	id	The ID of the item we would like to be retrieved.
// Retrieves the item of the given ID from the ITEMS array
StockItem Store::GetItem(int itemId) const {
	if (itemId < 0 || itemId >= NUM_STOCK_ITEMS) {
		return ITEMS[NUM_STOCK_ITEMS];
	}
	
	return ITEMS[itemId];
}

// AdjustQuantity
// int	itemId	The ID of the item we would like to be retrieved
// int	adjustment	The integer amount we would like to adjust the quantity by
// Adjusts the in-stock quantity by the adjustment for the item defined by the item ID
void Store::AdjustQuantity(int itemId, int adjustment) {
	if (itemId < 0 || itemId >= NUM_STOCK_ITEMS) {
		return;
	}
	
	ITEMS[itemId].AdjustQuantity(adjustment);
}

// GetMoney
// Returns the amount of money the store currently has
int Store::GetMoney() const {
	return money;
}

// AdjustMoney
// int	adjustment	The integer amount we would like to adjust the stpre's money by
void Store::AdjustMoney(int adjustment) {
	money += adjustment;
	return;
}

// GetNumberOfEmployess
// Returns the amount of employees the store currently has
int Store::GetNumberOfEmployees() const {
	return numberOfEmployees;
}

// AddEmployess
// int	amount	The amount of employees we would like to add
// Adds the given amount to the store's amount of employees
void Store::AddEmployees(int amount) {
	numberOfEmployees += amount;
	
	if (numberOfEmployees < 0) {
		numberOfEmployees = 0;
	}

	return;
}
