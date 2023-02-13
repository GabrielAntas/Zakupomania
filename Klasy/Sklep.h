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
        bool sprzedaj(Towar*) override;
        void dodajTowar(Towar*, int n = 0);
        void ustalCene(Towar*, double) override;
        void dołączDoSieci(Siec*);
        void wyłączSklep(ObiektHandlowy* sklep) override; // używaj this
        void przejmijSklep(ObiektHandlowy*) override;
        void przejmijSiec(ObiektHandlowy*) override;
        pair<int, double> sprawdźTowar(Towar*) override;
        Siec* dajSiec() const;
        map<Towar*, pair<int, double>> dajListeTowarów() const;
        pair<double, double> dajPołożenie() const;
        bool czyWSieci();
        string dajNazwe() const override;
        void wypisz() const override;
        void ustawMarże(double) override;
        virtual ~Sklep() = default;
        Sklep(const Sklep&) = default;
        Sklep& operator=(const Sklep&) = default;
};