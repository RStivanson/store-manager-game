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

#ifndef STOCK_ITEM_H

#include <string> // string

using namespace std;

// StockItem
// This class represent all items in the game that can be held in stock by a store
class StockItem {
	private:
		// The identification number of the item
		int id;
		
		// The ASCII name of item that is displayed to the player
		string name;
		
		// The stack size of this item
		int quantity;
		
		// The buying price of this item
		int price;
		
	public:
		// Parameterized Constructor
		// int		id			The identification number of this item
		// string	name		The ASCII name of this item
		// int		quantity	The stack amount of this item
		// int		price		The buying price of this item
		// Initializes this object with the given values
		StockItem(int id, string name, int quantity, int price);
		
		// GetName
		// Returns the name of this item
		string GetName() const;
		
		// GetQuantity
		// Returns the stack amount of this item
		int GetQuantity() const;
		
	// AdjustQuantity
	// int	adjustment	The amount to adjust our quantity by
	// Adds the given amount to the stack amount
		void AdjustQuantity(int adjustment);
		
		// GetPrice
		// Returns the buying price of this item
		int GetPrice() const;
};

#endif
