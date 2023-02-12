#pragma once
#include <vector>
#include <string>

using namespace std;

class ObiektHandlowy;
class Towar;
class Kupujący;

class Miasto {

    string nazwa;
    vector<ObiektHandlowy*> obiektyHandlowe;
    vector<Towar*> towary;
    vector<Kupujący*> kupujący;

    public:
        Miasto(string _nazwa);
        void dodajObiektHandlowy(ObiektHandlowy*);
        void dodajTowar(Towar*);
        void dodajKupujący(Kupujący*);

        void initTest();
};