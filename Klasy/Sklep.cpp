#include <iostream>
#include "Sklep.h"
#include "MyDebugger.h"
#include "Towar.h"

Sklep::Sklep(Miasto* _miasto, string _nazwa, pair<double, double> _położenie)
    : ObiektHandlowy{_miasto, _nazwa}, położenie{_położenie} {
        MyDebugger::debug("Stworzono sklep \"" + nazwa + "\"");
        siec = nullptr;
    }

bool Sklep::sprzedaj(Towar* towar) {
    towary[towar].first -= 1;
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

bool Sklep::czyWSieci() {
    if(siec == nullptr) return 0;
    return 1;
}

pair<double, double> Sklep::dajPołożenie() const {return położenie;}

string Sklep::dajNazwe() const {return nazwa;}

void Sklep::wypisz() const {
    cout << "Sklep: " << nazwa << '\n';
    cout << '(';
    for(auto &towar : towary) {
        if(towar.second.first == 0) continue;
        cout << '[';
        cout << towar.first->dajNazwe() << ',' << towar.second.first << ',' << towar.second.second;
        cout << "],";
    }
    cout << ')';
    cout << '\n';
}

void Sklep::ustawMarże(double) {
    throw runtime_error("Próba ustawienia marży dla sklepu");
}