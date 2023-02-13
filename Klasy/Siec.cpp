#include <iostream>
#include "Siec.h"
#include "MyDebugger.h"

Siec::Siec(Miasto* _miasto, string _nazwa)
    : ObiektHandlowy{_miasto, _nazwa} {
        MyDebugger::debug("Stworzono sieć \"" + nazwa + "\"");
    }

bool Siec::sprzedaj(Towar* towar) {
    for(auto &sklep : sklepy) {
        pair<int, double> p = sklep.first->sprawdźTowar(towar);
        if(p.first != 0) {
            sklep.first->sprzedaj(towar);
            return 1;
        }
    }
    return 0;
}

bool Siec::sprzedaj(Towar* towar, Sklep* sklep) {
    for(auto &it : sklepy) {
        if(it.first != sklep) continue;
        it.first->sprzedaj(towar);
        return 1;
    }
    return 0;
}

void Siec::przejmijSklep(ObiektHandlowy* sklep) {
    Sklep* S_sklep = dynamic_cast<Sklep*>(sklep);
    if(S_sklep == nullptr) {
        throw runtime_error("error: niepoprawne użycie przejmijSklep przez Sieć");
    }
    S_sklep->dołączDoSieci(this);
    sklepy[S_sklep] = 1;
}

void Siec::ustawMarże(double _marża) {
    marża = _marża;
}

void Siec::wyłączSklep(ObiektHandlowy* sklep) {
    Sklep* S_sklep = dynamic_cast<Sklep*>(sklep);
    if(S_sklep == nullptr) {
        throw runtime_error("Niepoprawne użycie wyłączSklep przez Sieć");
    }
    for(auto &sklep : sklepy) {
        if(sklep.first->dajNazwe() == S_sklep->dajNazwe()) {
            sklepy[sklep.first] = 0;
        }
    }

}

void Siec::przejmijSiec(ObiektHandlowy* siec) {
    Siec* S_siec = dynamic_cast<Siec*>(siec);
    if(S_siec == nullptr) {
        throw runtime_error("Niepoprawne użycie przejmijSiec przez siec");
        return;
    }
    for(auto &sklep : S_siec->sklepy) {
        sklep.first->dołączDoSieci(this);
        sklepy[sklep.first] = 1;
        S_siec->wyłączSklep(sklep.first);
    }
}


pair<int, double> Siec::sprawdźTowar(Towar* towar) {
    for(auto &it : sklepy) {
        pair<int, double> p = it.first->sprawdźTowar(towar);
        if(p.first != 0) return p;
    }
    return pair<int, double>(0, -1.0);
}

void Siec::dodajTowar(Towar*, int) {
    throw runtime_error("Próba dodania towaru do sieci");
}

void Siec::ustalCene(Towar*, double) {
    throw runtime_error("Próba ustalenia ceny towaru przez sieć");
}

double Siec::dajMarże() const {return marża;}

string Siec::dajNazwe() const {return nazwa;}

void Siec::wypisz() const {
    cout << "Sieć: " << nazwa << '\n';
    cout << "Marża: " << marża << '\n';
    cout << "(";
    for(auto& sklep : sklepy) {
        if(sklep.second)
            cout << sklep.first->dajNazwe() << ',';
    }
    cout << ")\n";
}