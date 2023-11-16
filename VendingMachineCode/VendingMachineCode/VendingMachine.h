#pragma once
#include <iostream>
#include <string>
#include "SnackSlot.h"

class VendingMachine // ����� // ��� ����� ����������� ������
{
public:
	VendingMachine(short slots); // ���������� ������ � ������

	void addSlot(const SnackSlot& slot); // ��������� ���� � ������

	short getTotalSlots(); // ������� ���������� ������ � ������
	short getEmptySlotsCount(); // ������� ���������� ������ ������

private:
	short slot; // ����� ���������� ������
	short fill; // ����������� �����
};