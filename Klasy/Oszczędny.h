#pragma once
#include "KonkretnyTowar.h"

class Oszczędny : public KonkretnyTowar {
    public:
        bool kup() override;
        Oszczędny(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Towar* const _towar);
        void wypisz() const override;
        ~Oszczędny() = default;
        Oszczędny(const Oszczędny&) = default;
        Oszczędny& operator=(const Oszczędny&) = default;
};