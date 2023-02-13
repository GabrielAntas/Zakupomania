#include "ObiektHandlowy.h"
#include "Miasto.h"
#include "Sklep.h"
#include "Siec.h"
#include "Tradycjonalista.h"
#include <stdio.h>
#include <float.h> 
#include <math.h>

double odległość(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

Tradycjonalista::Tradycjonalista(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie, Towar* const _towar)
    : KonkretnyTowar{_miasto, _imie, _budżet, _położenie, _towar} {}

bool Tradycjonalista::kup() {
    vector<ObiektHandlowy*> sklepy = miasto->dajSklepy();
    ObiektHandlowy* najbliższySklep = nullptr;
    double najbliższaCena = -1.0;
    double najbliższaOdległość = DBL_MAX;
    for(ObiektHandlowy* obiekt : sklepy) {
        Sklep* S_sklep = dynamic_cast<Sklep*>(obiekt);
        if(S_sklep == nullptr) continue;
        if(!S_sklep->czyWSieci()) {
            pair<int, double> daneTowaru = S_sklep->sprawdźTowar(towar);
            if(daneTowaru.first >= 1 && odległość(położenie, S_sklep->dajPołożenie()) < najbliższaOdległość) {
                najbliższaOdległość = odległość(położenie, S_sklep->dajPołożenie());
                najbliższySklep = S_sklep;
                najbliższaCena = daneTowaru.second;
            }
        }
        else {
            pair<int, double> daneTowaru = S_sklep->sprawdźTowar(towar);
            double marża = S_sklep->dajSiec()->dajMarże();
            if(daneTowaru.first >= 1 && odległość(położenie, S_sklep->dajPołożenie()) < najbliższaOdległość) {
                najbliższaOdległość = odległość(położenie, S_sklep->dajPołożenie());
                najbliższySklep = S_sklep;
                najbliższaCena = daneTowaru.second * (1.0 + marża);
            }
        }
    }
    if(najbliższySklep == nullptr || najbliższaCena > budżet) return 0;
    Sklep* S_sklep = dynamic_cast<Sklep*>(najbliższySklep);
    budżet -= najbliższaCena;
    if(!S_sklep->czyWSieci()) {
        S_sklep->sprzedaj(towar);
    }
    else {
        S_sklep->dajSiec()->sprzedaj(towar, S_sklep);
    }
    return 1;
}

void Tradycjonalista::wypisz() const {
    cout << imie << ", " << budżet;
}