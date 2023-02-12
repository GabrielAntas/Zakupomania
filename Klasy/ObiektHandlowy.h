#pragma once
#include <string>
#include "Miasto.h"

using namespace std;

class Towar;
class Sklep;

class ObiektHandlowy {
    protected:
        string nazwa;
        Miasto* miasto;
        ObiektHandlowy(Miasto*, string);
    public:
        virtual bool sprzedaj(Towar, Sklep*) = 0;
};
