#pragma once
#include <set>
#include "Sklep.h"
#include "ObiektHandlowy.h"

using namespace std;

class ObiektHandlowy;
class Sklep;

class Siec : public ObiektHandlowy {
    set<Sklep*> sklepy;
    double marża;
    public:
        Siec(Miasto* _miasto, string _nazwa);
        void przejmijSklep(ObiektHandlowy*) override;
        void przejmijSiec(ObiektHandlowy*) override;
        void ustawMarże(double _marża);
        void wyłączSklep(ObiektHandlowy*) override;
        bool sprzedaj(Towar*, Sklep*) override;
        void dodajTowar(Towar*, int) override;
        void ustalCene(Towar*, double) override;
        pair<int, double> sprawdźTowar(Towar*) override;
};