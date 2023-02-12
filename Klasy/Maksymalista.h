#pragma once
#include "UlubionySklep.h"

class Maksymalista : public UlubionySklep {
    public:
        Maksymalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep);
        bool kup() override;
};