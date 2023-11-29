#include "Appliances.h"
#include <iostream>

Appliances::Appliances(int weight) : _weight(weight)
{
}

void Appliances::ShowSpec()
{
	cout << endl << "Type: Appliances.\n" << "Weight: " << _weight << "kg.\n" << " \n";
}

Teapot::Teapot(int weight, int power) : Appliances(weight), _power(power)
{
}

void Teapot::ShowSpec()
{
	cout << endl << "Type: Teapot.\n" << "Weight: " << _weight << "kg.\n" << "Power: " << _power << "W." << " \n";
}

WashingMachine::WashingMachine(int weight, int capacity) : Appliances(weight), _capacity(capacity)
{
}

void WashingMachine::ShowSpec()
{
	cout << endl << "Type: Washing machine.\n" << "Weight: " << _weight << "kg.\n" << "Capacity: " << _capacity << " \n";
}