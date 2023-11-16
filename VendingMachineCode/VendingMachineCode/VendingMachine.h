#pragma once
#include <iostream>
#include <string>
#include "SnackSlot.h"

class VendingMachine // КЛАСС // для самой вендинговой машины
{
public:
	VendingMachine(short slots); // количество слотов в машине

	void addSlot(const SnackSlot& slot); // добавляет слот в машину

	short getTotalSlots(); // выводит количество слотов в машине
	short getEmptySlotsCount(); // выводит количество пустых слотов

private:
	short slot; // общее количество слотов
	short fill; // заполненные слоты
};