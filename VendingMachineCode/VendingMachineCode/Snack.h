#pragma once
#include <iostream>
#include <string>

class Snack
{
public:
	Snack(const string& name, short count, short size, double price, short calories); // size - размер, занимаемый снеком (реализован в качестве дополнительной опции, при не указанном значении(0) будет значение 1, count - количество батончиков, также если не указано(0), то будет 1
	Snack(const string& name, double price, short calories);
	Snack(const string& name);

	short getCalories() const;
	double getPrice() const;
	short getSnackSize() const; // выводит размер снека
	short getSnackCount() const; // выводит количество снеков
	string getSnackName() const; // выводит имя снека
	void setSnackCount(short value); // изменяет количество снеков
	void setSnackName(string value); // изменяет имя снека
	short getCountSizeProduct() const;
private:
	string name; // имя снека
	short count; // количество снеков
	short size; // размер снека
	short calories;
	double price;
};