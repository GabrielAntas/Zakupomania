#pragma once
#include <vector>
#include "Sklep.h"
#include "ObiektHandlowy.h"

using namespace std;

class Sklep;
class ObiektHandlowy;

class Siec : public ObiektHandlowy {
    vector<Sklep*> sklepy;
    double marża;
    public:
        Siec(Miasto* _miasto, string _nazwa);
        void przejmijSklep(Sklep&);
        void przejmijSieć(Siec&);
        bool sprzedaj(Towar*, Sklep*) override;
};