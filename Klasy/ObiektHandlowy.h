#pragma once
#include <string>
#include "Miasto.h"
#include "Towar.h"

using namespace std;

class Sklep;

class ObiektHandlowy {
    protected:
        string nazwa;
        Miasto* miasto;
        ObiektHandlowy(Miasto*, string);
    public:
        virtual bool sprzedaj(Towar*, Sklep*) = 0;
};
