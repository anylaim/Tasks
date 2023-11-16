#include "VendingMachine.h"
#include <iostream>
#include <string>
#include "SnackSlot.h"

using namespace std;


	VendingMachine::VendingMachine(short slot)
	{
		this->slot = slot;
	}

	void VendingMachine::addSlot(const SnackSlot& slot) // ��������� ���� � ������
	{
		if (fill + slot.getSlot() <= this->slot)
		{
			fill += slot.getSlot();
		}
	}

	short VendingMachine::getTotalSlots() // ������� ����� ���������� ������ � ������
	{
		return slot;
	}

	short VendingMachine::getEmptySlotsCount() // ������� ���������� ������ ������
	{
		return slot - fill;
	}