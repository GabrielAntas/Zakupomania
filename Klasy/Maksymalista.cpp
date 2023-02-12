#include "Maksymalista.h"

Maksymalista::Maksymalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep)
    : UlubionySklep{_miasto, _imie, _budżet, _położenie, _sklep} {}

bool Maksymalista::kup() {
    Sklep* S_sklep = dynamic_cast<Sklep*>(sklep);
    map<Towar*, pair<int, double>> mp = S_sklep->dajListeTowarów();
    pair<Towar*, pair<int, double>> najdroższy;
    najdroższy.second.second = -1.0;
    for(auto const& towar : mp) {
        if(towar.second.second > najdroższy.second.second && budżet >= najdroższy.second.second) {
            najdroższy.first = towar.first;
            najdroższy.second = towar.second;
        }
    }
    if(najdroższy.second.second < 0) return 0;
    S_sklep->sprzedaj(najdroższy.first, S_sklep);
    budżet -= najdroższy.second.second;
    return 1;
}