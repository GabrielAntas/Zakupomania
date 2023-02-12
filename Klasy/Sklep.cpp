#include <iostream>
#include "Sklep.h"
#include "MyDebugger.h"

Sklep::Sklep(Miasto* _miasto, string _nazwa, pair<double, double> _położenie)
    : ObiektHandlowy{_miasto, _nazwa}, położenie{_położenie} {
        MyDebugger::debug("Stworzono sklep \"" + nazwa + "\"");
        siec = nullptr;
    }

bool Sklep::sprzedaj(Towar* towar, Sklep* sklep) {
    towary[towar].first--;
    return 1;
}

void Sklep::dodajTowar(Towar* towar, int n) {
    towary[towar].first += n;
}

void Sklep::ustalCene(Towar* towar, double cena) {
    towary[towar].second = cena;
}

Siec* Sklep::dajSiec() const {
    return siec;
}

void Sklep::dołączDoSieci(Siec* _siec) {
    siec = _siec;
}

void Sklep::wyłączSklep(ObiektHandlowy* sklep) {
    siec->wyłączSklep(this);
    siec = nullptr;
}

void Sklep::przejmijSklep(ObiektHandlowy*) {
    throw std::runtime_error("Próba przejęcia sklepu przez sklep");
}

void Sklep::przejmijSiec(ObiektHandlowy*) {
    throw std::runtime_error("Próba przejęcia sieci przez sklep");
}

pair<int, double> Sklep::sprawdźTowar(Towar* towar) {
    return towary[towar];
}


map<Towar*, pair<int, double>> Sklep::dajListeTowarów() const {return towary;}