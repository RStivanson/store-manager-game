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

#ifndef STORE_H
#include "stockItem.h" // StockItem

// Store
// This class holds and handles all information regarding a store. 
class Store {
	private:
		// A static list of items owned by the store (Also defines the items in the game)
		// Ex. Apples
		static StockItem ITEMS[];
		
		// The amount of money a store currently has
		int money;
		
		// The Number of employees a store currently has
		int numberOfEmployees;
	public:
		// This is a count of how many items are in the ITEMS array
		static const int NUM_STOCK_ITEMS;
		
		Store();
		
		// AddProfits
		// Calculates profits based on the items  and adds the resulting number to the store's money
		void AddProfits();
		
		// GetItem
		// int	id	The ID of the item we would like to be retrieved.
		// Retrieves the item of the given ID from the ITEMS array
		StockItem GetItem(int id) const;
		
		// AdjustQuantity
		// int	itemId	The ID of the item we would like to be retrieved
		// int	adjustment	The integer amount we would like to adjust the quantity by
		// Adjusts the in-stock quantity by the adjustment for the item defined by the item ID
		void AdjustQuantity(int itemId, int adjustment);
		
		// GetMoney
		// Returns the amount of money the store currently has
		int GetMoney() const;
		
		// AdjustMoney
		// int	adjustment	The integer amount we would like to adjust the stpre's money by
		void AdjustMoney(int adjustment);
		
		// GetNumberOfEmployess
		// Returns the amount of employees the store currently has
		int GetNumberOfEmployees() const;
		
		// AddEmployess
		// int	amount	The amount of employees we would like to add
		// Adds the given amount to the store's amount of employees
		void AddEmployees(int amount);
};

#endif
