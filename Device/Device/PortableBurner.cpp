#include "PortableBurner.h"
#include <iostream>


PortableBurner::PortableBurner(int batteryLife, int weight) : Device(batteryLife), Appliances(weight)
{
}

void PortableBurner::ShowSpec()
{
	cout << endl << "Type: Portable burner.\n" << "Battery Life: " << _batteryLife << "h.\n" << "Weight: " << _weight << "kg.\n" << " \n";
}
