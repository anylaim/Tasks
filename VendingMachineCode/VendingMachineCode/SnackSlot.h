#pragma once
#include <iostream>
#include <string>
#include "Snack.h"

class SnackSlot
{
public:
	SnackSlot(short quantity); // общее количество слотов
	void addSnack(const Snack& snack); // добавляет батончик в слот

	short getSlot() const; // выводит количество заполненых слотов
	short getEmptySlot() const; // выводит количество не заполненых слотов
private:
	short quantity; // общее количество слотов
	short filled; // заполненные слоты
};