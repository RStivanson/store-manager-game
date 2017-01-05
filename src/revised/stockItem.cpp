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

#include "stockItem.h"

// Parameterized Constructor
// int		id			The identification number of this item
// string	name		The ASCII name of this item
// int		quantity	The stack amount of this item
// int		price		The buying price of this item
// Initializes this object with the given values
StockItem::StockItem(int id, string name, int quantity, int price) {
	this->id = id;
	this->name = name;
	this->quantity = quantity;
	this->price = price;
	return;
}

// GetName
// Returns the name of this item
string StockItem::GetName() const {
	return name;
}

// GetQuantity
// Returns the stack amount of this item
int StockItem::GetQuantity() const {
	return quantity;
}

// AdjustQuantity
// int	adjustment	The amount to adjust our quantity by
// Adds the given amount to the stack amount
void StockItem::AdjustQuantity(int adjustment) {
	quantity += adjustment;
	return;
}

// GetPrice
// Returns the buying price of this item
int StockItem::GetPrice() const {
	return price;
}
