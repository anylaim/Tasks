#include "SnackSlot.h"
#include <iostream>
#include <string>
#include "Snack.h"

using namespace std;

SnackSlot::SnackSlot(short quantity)
{
	this->quantity = quantity;
	this->filled = 0;
}

void SnackSlot::addSnack(const Snack& snack)
{
	short countSizeProduct = snack.getCountSizeProduct();
	if (filled + countSizeProduct <= quantity)
	{
		filled += countSizeProduct;
	}
}

short SnackSlot::getSlot() const
{
	return filled;
}

short SnackSlot::getEmptySlot() const
{
	return quantity - filled;
}