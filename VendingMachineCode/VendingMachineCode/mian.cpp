#include "VendingMachine.h"
#include "Snack.h"
#include "SnackSlot.h"
#include <iostream>
#include <string>

using namespace std;


int main() {
    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    SnackSlot* slot = new SnackSlot(10);

    slot->addSnack(*bounty);
    slot->addSnack(*snickers);

    VendingMachine* machine = new VendingMachine(5);
    machine->addSlot(*slot);

    cout << machine->getEmptySlotsCount();

    delete machine;
    delete slot;
    delete snickers;
    delete bounty;

    return 0;
}