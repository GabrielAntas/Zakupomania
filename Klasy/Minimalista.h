#pragma once
#include "UlubionySklep.h"

class Minimalista : public UlubionySklep {
    public:
        Minimalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep);
        bool kup() override;
        void wypisz() const override;
        ~Minimalista() = default;
        Minimalista(const Minimalista&) = default;
        Minimalista& operator=(const Minimalista&) = default;
};