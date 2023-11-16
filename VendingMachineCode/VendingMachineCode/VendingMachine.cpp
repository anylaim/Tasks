#include "VendingMachine.h"
#include <iostream>
#include <string>
#include "SnackSlot.h"

using namespace std;


	VendingMachine::VendingMachine(short slot)
	{
		this->slot = slot;
	}

	void VendingMachine::addSlot(const SnackSlot& slot) // загружает слот в машину
	{
		if (fill + slot.getSlot() <= this->slot)
		{
			fill += slot.getSlot();
		}
	}

	short VendingMachine::getTotalSlots() // выводит общее количество слотов в машине
	{
		return slot;
	}

	short VendingMachine::getEmptySlotsCount() // выводит количество пустых слотов
	{
		return slot - fill;
	}