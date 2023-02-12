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

void Siec::przejmijSklep(ObiektHandlowy* sklep) {
    Sklep* S_sklep = dynamic_cast<Sklep*>(sklep);
    if(S_sklep == nullptr) {
        throw runtime_error("error: niepoprawne użycie przejmijSklep przez Sieć");
    }
    S_sklep->dołączDoSieci(this);
    sklepy.insert(S_sklep);
}

void Siec::ustawMarże(double _marża) {
    marża = _marża;
}

void Siec::przejmijSiec(ObiektHandlowy* siec) {
    Siec* S_siec = dynamic_cast<Siec*>(siec);
    if(S_siec == nullptr) {
        throw runtime_error("Niepoprawne użycie przejmijSiec przez siec");
    }
    for(Sklep* sklep : S_siec->sklepy) {
        sklep->dołączDoSieci(this);
    }
}

void Siec::wyłączSklep(Sklep* sklep) {
    sklepy.erase(sklepy.find(sklep));
}

// pair<double, int> Siec::sprawdźTowar(Towar* towar) const {
//     //for(auto &it : sklepy) {
//     //    cout << "eh\n";//pair<double, int> 
//     //}
//     return pair<double, int>(.0, 0);
// }

void Siec::dodajTowar(Towar*, int) {
    throw runtime_error("Próba dodania towaru do sieci");
}

void Siec::ustalCene(Towar*, double) {
    throw runtime_error("Próba ustalenia ceny towaru przez sieć");
}