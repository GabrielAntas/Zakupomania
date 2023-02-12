#pragma once
#include <map>
#include "Siec.h"
#include "ObiektHandlowy.h"

using namespace std;

class Siec;

class Sklep : public ObiektHandlowy {
    Siec* siec;
    pair<double, double> położenie;
    map<Towar*, pair<int, double>> towary;
    public:
        Sklep(Miasto* _miasto, string _nazwa, pair<double, double> _położenie);
        bool sprzedaj(Towar*, Sklep*) override;
        void dodajTowar(Towar*, int n = 0);
        void ustalCene(Towar*, double) override;
        void dołączDoSieci(Siec*);
        //void odłączOdSieci();
        void przejmijSklep(ObiektHandlowy*) override;
        void przejmijSiec(ObiektHandlowy*) override;
        //pair<double, int> sprawdźTowar(Towar*) const override;
        Siec* dajSiec() const;
};