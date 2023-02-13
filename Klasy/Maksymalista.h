#pragma once
#include "UlubionySklep.h"

class Maksymalista : public UlubionySklep {
    public:
        Maksymalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep);
        bool kup() override;
        void wypisz() const override;
        ~Maksymalista() = default;
        Maksymalista(const Maksymalista&) = default;
        Maksymalista& operator=(const Maksymalista&) = default;
};