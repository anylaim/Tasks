#pragma once
#include "IElectronics.h"

using namespace std;

class Appliances : virtual public IElectronics
{
protected:
	int _weight;

public:
	Appliances(int weight);
	void ShowSpec() override;
	virtual ~Appliances() = default;
};

class Teapot final : public Appliances
{
public:
	Teapot(int weight, int power);
	void ShowSpec() override;

private:
	int _power;
};

class WashingMachine final : public Appliances
{
public:
	WashingMachine(int weight, int capacity);
	void ShowSpec() override;

private:
	int _capacity;
};