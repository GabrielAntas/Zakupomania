#pragma once
#include "UlubionySklep.h"

class Losowy : public UlubionySklep {
    int liczbaLosowań;
    public:
        Losowy(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep, int _liczbaLosowań);
        bool kup() override;
        void wypisz() const override;
        ~Losowy() = default;
        Losowy(const Losowy&) = default;
        Losowy& operator=(const Losowy&) = default;
};