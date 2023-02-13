#include "Minimalista.h"
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "Sklep.h"
#include "Towar.h"

Minimalista::Minimalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep)
    : UlubionySklep{_miasto, _imie, _budżet, _położenie, _sklep} {}

bool Minimalista::kup() {
    Sklep* S_sklep = dynamic_cast<Sklep*>(sklep);
    map<Towar*, pair<int, double>> mp = S_sklep->dajListeTowarów();
    pair<Towar*, pair<int, double>> najtańszy;
    najtańszy.second.second = DBL_MAX;
    for(auto const& towar : mp) {
        if(towar.second.second < najtańszy.second.second && budżet >= towar.second.second) {
            najtańszy.first = towar.first;
            najtańszy.second = towar.second;
        }
    }
    if(najtańszy.second.second == DBL_MAX) return 0;
    S_sklep->sprzedaj(najtańszy.first);
    budżet -= najtańszy.second.second;
    return 1;
}

void Minimalista::wypisz() const {
    cout << imie << ", " << budżet;
}