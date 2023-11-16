#pragma once
#include <iostream>
#include <string>

class Snack
{
public:
	Snack(const string& name, short count, short size, double price, short calories); // size - ������, ���������� ������ (���������� � �������� �������������� �����, ��� �� ��������� ��������(0) ����� �������� 1, count - ���������� ����������, ����� ���� �� �������(0), �� ����� 1
	Snack(const string& name, double price, short calories);
	Snack(const string& name);

	short getCalories() const;
	double getPrice() const;
	short getSnackSize() const; // ������� ������ �����
	short getSnackCount() const; // ������� ���������� ������
	string getSnackName() const; // ������� ��� �����
	void setSnackCount(short value); // �������� ���������� ������
	void setSnackName(string value); // �������� ��� �����
	short getCountSizeProduct() const;
private:
	string name; // ��� �����
	short count; // ���������� ������
	short size; // ������ �����
	short calories;
	double price;
};