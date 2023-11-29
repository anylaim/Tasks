#pragma once
#include "Appliances.h"
#include "Device.h"

using namespace std;

class PortableBurner final : public Device, Appliances
{
public:
	PortableBurner(int batteryLife, int weight);
	void ShowSpec() override;
};