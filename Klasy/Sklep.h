#pragma once
#include <map>
#include "Siec.h"
#include "ObiektHandlowy.h"

using namespace std;

class Siec;

class Sklep : ObiektHandlowy {
    Siec* siec;
    pair<double, double> położenie;
    map<Towar*, pair<int, double>> towary;
    public:
        
};