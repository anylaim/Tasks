#include "Device.h"
#include <iostream>
#include <string>

Device::Device(int batteryLife) : _batteryLife(batteryLife)
{
}

void Device::ShowSpec()
{
    cout << "Battery Life: " << _batteryLife << "h.\n" << " \n";
}

Player::Player(int batteryLife, int totalTracks) : Device(batteryLife), _totalTracks(totalTracks)
{
}

void Player::ShowSpec()
{
	cout << endl << "Type: Player.\n" << "Battery Life: " << _batteryLife << "h.\n" << "Total tracks: " << _totalTracks << endl << " \n";
}

Smartphone::Smartphone(int batteryLife, string color) : Device(batteryLife), _color(color)
{
}

void Smartphone::ShowSpec()
{
	cout << endl << "Type: Smartphone.\n" << "Battery Life: " << _batteryLife << "h.\n" << "Color: " << _color << endl << " \n";
}

Headphones::Headphones(int batteryLife, int minFrequency, int maxFrequency) : Device(batteryLife), _minFrequency(minFrequency), _maxFrequency(maxFrequency)
{
}

void Headphones::ShowSpec()
{
	cout << endl << "Type: Headphones.\n" << "Battery Life: " << _batteryLife << "h.\n" << "Frequency: " << _minFrequency << "-" << _maxFrequency << "hz.\n" << " \n";
}