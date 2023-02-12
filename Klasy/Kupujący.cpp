#include <iostream>
#include "Kupujący.h"

Kupujący::Kupujący(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie)
    : miasto{_miasto}, imie{_imie}, budżet{_budżet}, położenie{_położenie} {}

ostream& operator<<(ostream& os, const Kupujący& dt);