#include <iostream>
#include "Device.h"
#include "Appliances.h"
#include "PortableBurner.h"
#include <string>

using namespace std;


int main()
{
	IElectronics* product[6];

	product[0] = new Teapot(2, 1000);
    product[1] = new WashingMachine(60, 15);
    product[2] = new PortableBurner(8, 6);
    product[3] = new Player(48, 10000);
    product[4] = new Smartphone(12, string("black"));
    product[5] = new Headphones(16, 20, 48000);

    bool open = true;
    while (open)
    {
        cout << endl << "Select a product category: 1 - appliances, 2 - devices, 0 - to exit: \n";
        int choiceOne;
        cin >> choiceOne;
        switch (choiceOne)
        {
        case 1:
            cout << endl << "Select a product: 1 - Teapot, 2 - WashingMachine, 3 - PortableBurner, 0 - to back: \n";
            int choiceTwo;
            cin >> choiceTwo;
            switch (choiceTwo)
            {
            case 1:
                product[0]->ShowSpec();
                break;

            case 2:
                product[1]->ShowSpec();
                break;

            case 3:
                product[2]->ShowSpec();
                break;

            case 0:
                break;
            
            }
            break;

        case 2:
            cout << endl << "Select a product: 1 - Player, 2 - Smartphone, 3 - Headphones, 0 - to back: \n";
            int choiceThree;
            cin >> choiceThree;
            switch (choiceThree)
            {
            case 1:
                product[3]->ShowSpec();
                break;

            case 2:
                product[4]->ShowSpec();
                break;

            case 3:
                product[5]->ShowSpec();
                break;

            case 0:
                break;

            }
            break;

        case 0:
            open = false;
            break;

        default:
            cout << endl << "Select a product category from 1 to 2, 0 - to exit\n";
            break;
        }
    }


    delete product[0];
    delete product[1];
    delete product[2];
    delete product[3];
    delete product[4];
    delete product[5];

	return 0;
}