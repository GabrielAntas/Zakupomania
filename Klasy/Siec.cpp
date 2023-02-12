#include <iostream>
#include "Siec.h"
#include "MyDebugger.h"

Siec::Siec(Miasto* _miasto, string _nazwa)
    : ObiektHandlowy{_miasto, _nazwa} {
        MyDebugger::debug("Stworzono sieć \"" + nazwa + "\"");
    }

bool Siec::sprzedaj(Towar*, Sklep*) {
    return 0; // todo
}