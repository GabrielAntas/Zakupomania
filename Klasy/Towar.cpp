#include "Towar.h"

Towar::Towar(string _nazwa)
    : nazwa{_nazwa} {}

string Towar::dajNazwe() const {return nazwa;}