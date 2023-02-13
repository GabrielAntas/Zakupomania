#include "Losowy.h"
#include "Miasto.h"
#include "Sklep.h"

Losowy::Losowy(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep, int _liczbaLosowań) 
    : UlubionySklep{_miasto, _imie, _budżet, _położenie, _sklep}, liczbaLosowań{_liczbaLosowań} {}

bool Losowy::kup() {
    Sklep* S_sklep = dynamic_cast<Sklep*>(sklep);
    map<Towar*, pair<int, double>> mp = S_sklep->dajListeTowarów();
    
    for(int i = 0; i < liczbaLosowań; i++) {
        Towar* towar = miasto->dajLosowyTowar();
        if(mp[towar].second <= budżet && mp[towar].first >= 1) {
            S_sklep->sprzedaj(towar);
            budżet -= mp[towar].second;
            return 1;
        }
    }
    return 0;
}

void Losowy::wypisz() const {
    cout << imie << ", " << budżet;
}