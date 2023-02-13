#include "Towar.h"
#include <iostream>
using namespace std;

Towar::Towar(string _nazwa)
    : nazwa{_nazwa} {}

string Towar::dajNazwe() const {return nazwa;}