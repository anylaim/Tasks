#pragma once
#include "IElectronics.h"
#include <string>

using namespace std;

class Device : virtual public IElectronics
{
public:
    Device(int batteryLife);
    void ShowSpec() override;
    virtual ~Device() = default;
    
protected:
    int _batteryLife;
};

class Player final : public Device
{
private:
    int _totalTracks;

public:
    Player(int batteryLife, int totalTracks);
    void ShowSpec();
};

class Smartphone final : public Device
{
public:
    Smartphone(int batteryLife, string color);
    void ShowSpec();
private:
    string _color;

};

class Headphones final : public Device
{
public:
    Headphones(int batteryLife, int minFrequency, int maxFrequency);
    void ShowSpec();
private:
    int _minFrequency;
    int _maxFrequency;

};