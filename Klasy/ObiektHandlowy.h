#pragma once
#include <string>

using namespace std;

class Sklep;
class Miasto;
class Siec;
class Towar;

class ObiektHandlowy {
    protected:
        string nazwa;
        Miasto* miasto;
        ObiektHandlowy(Miasto*, string);
    public:
        virtual bool sprzedaj(Towar*, Sklep*) = 0;
        virtual void przejmijSklep(ObiektHandlowy*) = 0;
        virtual void przejmijSiec(ObiektHandlowy*) = 0;
        virtual void dodajTowar(Towar*, int) = 0;
        virtual void ustalCene(Towar*, double) = 0;
        //virtual pair<double, int> sprawdźTowar(Towar*) const = 0;
};
