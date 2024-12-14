#pragma once
#include <iostream>
#include <mutex>
#include <thread>
#include <random>
#include <vector>

using namespace std;

class Array
{
public:

	Array();

	int generate();

	void sum(long long int& num, int num2);

	void add(int num);

	long long int run(int count);

private:
	int count;
	vector<int> arr;
};