#include "Maksymalista.h"

Maksymalista::Maksymalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Sklep* const _sklep)
    : UlubionySklep{_miasto, _imie, _budżet, _położenie, _sklep} {}

bool Maksymalista::kup() {return 0;} // todo