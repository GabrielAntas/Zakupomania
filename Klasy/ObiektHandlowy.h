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
        virtual bool sprzedaj(Towar*) = 0;
        virtual void przejmijSklep(ObiektHandlowy*) = 0;
        virtual void przejmijSiec(ObiektHandlowy*) = 0;
        virtual void dodajTowar(Towar*, int) = 0;
        virtual void ustalCene(Towar*, double) = 0;
        virtual void wyłączSklep(ObiektHandlowy*) = 0;
        virtual pair<int, double> sprawdźTowar(Towar*) = 0;
        virtual string dajNazwe() const = 0;
        virtual void wypisz() const = 0;
        virtual void ustawMarże(double) = 0;
        virtual ~ObiektHandlowy() = default;
        ObiektHandlowy(const ObiektHandlowy&) = default;
        ObiektHandlowy& operator=(const ObiektHandlowy&) = default;
};
