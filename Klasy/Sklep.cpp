#include <iostream>
#include "Sklep.h"
#include "MyDebugger.h"

Sklep::Sklep(Miasto* _miasto, string _nazwa, pair<double, double> _położenie)
    : ObiektHandlowy{_miasto, _nazwa}, położenie{_położenie} {
        MyDebugger::debug("Stworzono sklep \"" + nazwa + "\"");
    }

bool Sklep::sprzedaj(Towar* towar, Sklep* sklep) {
    return 0; // todo
}

void Sklep::dodajTowar(Towar* towar, int n) {
    towary[towar].first += n;
}

void Sklep::ustalCene(Towar* towar, double cena) {
    towary[towar].second = cena;
}