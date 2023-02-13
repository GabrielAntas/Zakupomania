#include "Oszczędny.h"
#include "ObiektHandlowy.h"
#include "Miasto.h"
#include "Sklep.h"
#include "Siec.h"
#include <stdio.h>
#include <float.h> 
#include <math.h>

Oszczędny::Oszczędny(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Towar* const _towar)
    : KonkretnyTowar{_miasto, _imie, _budżet, _położenie, _towar} {}

bool Oszczędny::kup() {
    vector<ObiektHandlowy*> sklepy = miasto->dajSklepy();
    ObiektHandlowy* najtańszyObiekt = nullptr;
    double najtańszaCena = DBL_MAX;
    for(ObiektHandlowy* obiekt : sklepy) {
        Sklep* S_sklep = dynamic_cast<Sklep*>(obiekt);
        Siec* S_siec = dynamic_cast<Siec*>(obiekt);
        if(S_sklep != nullptr) {
            if(!S_sklep->czyWSieci()) {
                pair<int, double> daneTowaru = S_sklep->sprawdźTowar(towar);
                if(najtańszaCena > daneTowaru.second && daneTowaru.first >= 1 && budżet >= daneTowaru.second) {
                    najtańszaCena = daneTowaru.second;
                    najtańszyObiekt = S_sklep;
                }
            }
        }
        else {
            pair<int, double> daneTowaru = S_siec->sprawdźTowar(towar);
            double marża = S_siec->dajMarże();
            if(najtańszaCena > daneTowaru.second * (marża + 1.0) && daneTowaru.first >= 1 && budżet >= daneTowaru.second) {
                najtańszaCena = daneTowaru.second * (marża + 1.0);
                najtańszyObiekt = S_siec;
            }
        }
    }
    if(najtańszyObiekt == nullptr) return 0;
    najtańszyObiekt->sprzedaj(towar);
    budżet -= najtańszaCena;
    return 1;
}

void Oszczędny::wypisz() const {
    cout << imie << ", " << budżet;
}