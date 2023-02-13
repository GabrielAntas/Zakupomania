#pragma once
#include "Kupujący.h"
#include "Sklep.h"

class UlubionySklep : public Kupujący {
    protected:
        ObiektHandlowy* const sklep;
        UlubionySklep(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, ObiektHandlowy* const _sklep);
        virtual ~UlubionySklep() = default;
        UlubionySklep(const UlubionySklep&) = default;
        UlubionySklep& operator=(const UlubionySklep&) = default;
};