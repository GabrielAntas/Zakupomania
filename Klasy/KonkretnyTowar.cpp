#include "KonkretnyTowar.h"

KonkretnyTowar::KonkretnyTowar(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Towar* const _towar)
    : Kupujący{_miasto, _imie, _budżet, _położenie}, towar{_towar} {}