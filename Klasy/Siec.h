#pragma once
#include <vector>
#include "Sklep.h"

class Sklep;

class Siec {
    std::vector<Sklep*> sklepy;
    public:
        Siec();
        Siec(Sklep&);
        void drukuj();
        void dodaj_sklep(Sklep&);
};