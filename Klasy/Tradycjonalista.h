#pragma once
#include "KonkretnyTowar.h"

class Tradycjonalista : public KonkretnyTowar {
    public:
        bool kup() override;
        Tradycjonalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Towar* const _towar);
        void wypisz() const override;
        ~Tradycjonalista() = default;
        Tradycjonalista(const Tradycjonalista&) = default;
        Tradycjonalista& operator=(const Tradycjonalista&) = default;
};