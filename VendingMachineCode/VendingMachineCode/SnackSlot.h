#pragma once
#include <iostream>
#include <string>
#include "Snack.h"

class SnackSlot
{
public:
	SnackSlot(short quantity); // ����� ���������� ������
	void addSnack(const Snack& snack); // ��������� �������� � ����

	short getSlot() const; // ������� ���������� ���������� ������
	short getEmptySlot() const; // ������� ���������� �� ���������� ������
private:
	short quantity; // ����� ���������� ������
	short filled; // ����������� �����
};