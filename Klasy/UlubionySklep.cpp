#include "UlubionySklep.h"

UlubionySklep::UlubionySklep(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Sklep* const _sklep)
    : Kupujący{_miasto, _imie, _budżet, _położenie}, sklep{_sklep} {}