#include "Array.h"

Array::Array() {}

int Array::generate()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 100);

	return dist(gen);
}

void Array::sum(long long int& num, int num2)
{
	num += num2;
}

void Array::add(int num)
{
	arr.push_back(num);
}

long long int Array::run(int count)
{
	for (int i = 0; i < count; i++)
	{
		add(generate());
	}

	long long int _sum = 0;

	for (int value : arr)
	{
		sum(_sum, value);
	}

	cout << _sum << endl;

	return _sum;
}