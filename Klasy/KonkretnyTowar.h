#pragma once
#include "Kupujący.h"
#include "Towar.h"

class KonkretnyTowar : public Kupujący {
    protected:
        Towar* const towar;
        KonkretnyTowar(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Towar* const _towar);
        virtual ~KonkretnyTowar() = default;
        KonkretnyTowar(const KonkretnyTowar&) = default;
        KonkretnyTowar& operator=(const KonkretnyTowar&) = default;
};