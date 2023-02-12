#pragma once
#include "Kupujący.h"
#include "Sklep.h"

class UlubionySklep : public Kupujący {
    protected:
        Sklep* const sklep;
        UlubionySklep(string imie, Miasto* miasto, double budżet, Sklep* const sklep);
};