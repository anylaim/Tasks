#include "Snack.h"
#include <iostream>
#include <string>

using namespace std;

Snack::Snack(const string& name, short count, short size, double price, short calories)
{
	this->name = name;
	this->count = count;
	this->size = size;
	this->price = price;
	this->calories = calories;
}
Snack::Snack(const string& name, double price, short calories)
{
	this->name = name;
	this->count = 1;
	this->size = 1;
	this->price = price;
	this->calories = calories;
}

Snack::Snack(const string& name)
{
	this->name = name;
	this->count = 1;
	this->size = 1;
	this->price = 1;
	this->calories = 1;
}
short Snack::getSnackSize() const
{
	return size;
}
short Snack::getSnackCount() const
{
	return count;
}
string Snack::getSnackName() const
{
	return name;
}
short Snack::getCalories() const
{
	return calories;
}
double Snack::getPrice() const
{
	return price;
}
void Snack::setSnackCount(short value)
{
	if (value >= 0)
	{
		count = value;
	}
}
void Snack::setSnackName(string value)
{
	name = value;
}
short Snack::getCountSizeProduct() const 
{
	return count * size;
}