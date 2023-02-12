#pragma once
#include <vector>

using namespace std;

class ObiektHandlowy;
class Towar;
class Kupujący;

class Miasto {

    vector<ObiektHandlowy*> obiektyHandlowe;
    vector<Towar*> towary;
    vector<Kupujący*> kupujący;

    public:
        Miasto();
        void dodajObiektHandlowy(ObiektHandlowy*);
        void dodajTowar(Towar*);
        void dodajKupujący(Kupujący*);
};