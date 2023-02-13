#pragma once
#include <set>
#include "Sklep.h"
#include "ObiektHandlowy.h"

using namespace std;

class ObiektHandlowy;
class Sklep;

class Siec : public ObiektHandlowy {
    map<Sklep*, bool> sklepy;
    double marża;
    public:
        Siec(Miasto* _miasto, string _nazwa);
        void przejmijSklep(ObiektHandlowy*) override;
        void przejmijSiec(ObiektHandlowy*) override;
        void ustawMarże(double _marża) override;
        double dajMarże() const;
        void wyłączSklep(ObiektHandlowy*) override;
        bool sprzedaj(Towar*) override;
        bool sprzedaj(Towar*, Sklep*);
        void dodajTowar(Towar*, int) override;
        void ustalCene(Towar*, double) override;
        pair<int, double> sprawdźTowar(Towar*) override;
        string dajNazwe() const override;
        void wypisz() const override;
        virtual ~Siec() = default;
        Siec(const Siec&) = default;
        Siec& operator=(const Siec&) = default;
};