#include <iostream>
#include "Miasto.h"
#include "Maksymalista.h"
#include "Minimalista.h"
#include "Oszczędny.h"
#include "Tradycjonalista.h"
#include "Sklep.h"
#include "Siec.h"
#include "Towar.h"
#include "MyDebugger.h"
#include "ObiektHandlowy.h"
#include "Losowy.h"

using namespace std;

Miasto::Miasto(string _nazwa)
    : obiektyHandlowe{}, towary{}, kupujący{}, nazwa{_nazwa} {}

void Miasto::dodajObiektHandlowy(ObiektHandlowy* obiektHandlowy) {
    obiektyHandlowe.push_back(obiektHandlowy);
}

void Miasto::dodajTowar(Towar* towar) {
    towary.push_back(towar);
}

void Miasto::dodajKupujący(Kupujący* kupujący1) {
    kupujący.push_back(kupujący1);
}

Towar* Miasto::dajLosowyTowar() {
    int map_size = towary.size();
    int foo = rand() % map_size;
    for(Towar* towar : towary) {
        if(foo == 0) return towar;
        foo--;
    }
    return nullptr;
}

vector<ObiektHandlowy*> Miasto::dajSklepy() const {return obiektyHandlowe;}

void Miasto::wypisz() const {
    cout << "Miasto: " << nazwa << '\n' << '\n';
    cout << "Obiekty Handlowe: \n";
    for(ObiektHandlowy* obiektHandlowy : obiektyHandlowe) {
        obiektHandlowy->wypisz();
    }
    cout << '\n';
    cout << '\n';
    cout << "Kupujący:\n";
    for(Kupujący* kupujący1 : kupujący) {
        kupujący1->wypisz();
        cout << '\n';
    }
}

void Miasto::initTest() {
    MyDebugger::debug("Miasto: " + nazwa);

    Sklep* żabka1 = new Sklep(this, "Żabka 1", pair<double, double>(.0, .0));
    Sklep* żabka2 = new Sklep(this, "Żabka 2", pair<double, double>(-30.0, -11.93));
    Sklep* żabka3 = new Sklep(this, "Żabka 3", pair<double, double>(15.6, -7.7));
    Sklep* sklepKawiorowy = new Sklep(this, "Sklep Kawiorowy", pair<double, double>(3.14, 2.72));
    Sklep* stonka = new Sklep(this, "Stonka", pair<double, double>(10.2, -5.6));
    Sklep* biedronka1 = new Sklep(this, "Biedronka 1", pair<double, double>(3.3, -19.58));
    Sklep* biedronka2 = new Sklep(this, "Biedronka 2", pair<double, double>(-2.5, 24.2));

    dodajObiektHandlowy(żabka1);
    dodajObiektHandlowy(żabka2);
    dodajObiektHandlowy(żabka3);
    dodajObiektHandlowy(sklepKawiorowy);
    dodajObiektHandlowy(stonka);
    dodajObiektHandlowy(biedronka1);
    dodajObiektHandlowy(biedronka2);

    Towar* kremówka = new Towar("kremówka");
    Towar* monsterEnergyMangoLoco = new Towar("Monster Energy Mango Loco");
    Towar* monsterEnergyKhaotic = new Towar("Monster Energy Khaotic");
    Towar* perłaExport = new Towar("Perła Export");
    Towar* kawiorPremium = new Towar("Kawior Premium");
    Towar* kawior = new Towar("Kawior");
    Towar* pierogi = new Towar("Pierogi z żabki");

    dodajTowar(kremówka);
    dodajTowar(monsterEnergyMangoLoco);
    dodajTowar(monsterEnergyKhaotic);
    dodajTowar(perłaExport);
    dodajTowar(kawiorPremium);
    dodajTowar(kawior);
    dodajTowar(pierogi);

    obiektyHandlowe[0]->dodajTowar(towary[0], 10);
    obiektyHandlowe[0]->ustalCene(towary[0], 15.0);
    obiektyHandlowe[0]->dodajTowar(monsterEnergyMangoLoco, 5);
    obiektyHandlowe[0]->ustalCene(monsterEnergyMangoLoco, 5.50);
    obiektyHandlowe[0]->dodajTowar(pierogi, 3);
    obiektyHandlowe[0]->ustalCene(pierogi, 10.00);
    obiektyHandlowe[1]->dodajTowar(kremówka, 20);
    obiektyHandlowe[1]->ustalCene(kremówka, 13.0);
    obiektyHandlowe[1]->dodajTowar(monsterEnergyKhaotic, 1);
    obiektyHandlowe[1]->ustalCene(monsterEnergyKhaotic, 4.50);
    obiektyHandlowe[2]->dodajTowar(kremówka, 100);
    obiektyHandlowe[2]->ustalCene(kremówka, 20);
    obiektyHandlowe[2]->dodajTowar(perłaExport, 1000);
    obiektyHandlowe[2]->ustalCene(perłaExport, 1.00);
    obiektyHandlowe[3]->dodajTowar(kawiorPremium, 100);
    obiektyHandlowe[3]->ustalCene(kawiorPremium, 1000.00);
    obiektyHandlowe[3]->dodajTowar(kawior, 1000);
    obiektyHandlowe[3]->ustalCene(kawior, 100.00);
    obiektyHandlowe[4]->dodajTowar(kremówka, 5);
    obiektyHandlowe[4]->ustalCene(kremówka, 2.0);
    obiektyHandlowe[4]->dodajTowar(monsterEnergyMangoLoco, 5);
    obiektyHandlowe[4]->ustalCene(monsterEnergyMangoLoco, 6.50);
    obiektyHandlowe[5]->dodajTowar(kremówka, 5);
    obiektyHandlowe[5]->ustalCene(kremówka, 2.0);
    obiektyHandlowe[5]->dodajTowar(monsterEnergyMangoLoco, 5);
    obiektyHandlowe[5]->ustalCene(monsterEnergyMangoLoco, 6.50);
    obiektyHandlowe[6]->dodajTowar(kremówka, 5);
    obiektyHandlowe[6]->ustalCene(kremówka, 2.0);
    obiektyHandlowe[6]->dodajTowar(monsterEnergyMangoLoco, 5);
    obiektyHandlowe[6]->ustalCene(monsterEnergyMangoLoco, 6.50);
    
    ObiektHandlowy* żabka = new Siec(this, "Żabka");
    ObiektHandlowy* biedronka = new Siec(this, "Biedronka");

    dodajObiektHandlowy(żabka);
    dodajObiektHandlowy(biedronka);

    obiektyHandlowe[7]->ustawMarże(.2);
    obiektyHandlowe[8]->ustawMarże(.3);

    obiektyHandlowe[7]->przejmijSklep(obiektyHandlowe[0]);
    obiektyHandlowe[7]->przejmijSklep(obiektyHandlowe[1]);
    obiektyHandlowe[7]->przejmijSklep(obiektyHandlowe[2]);

    obiektyHandlowe[8]->przejmijSklep(obiektyHandlowe[5]);
    obiektyHandlowe[8]->przejmijSklep(obiektyHandlowe[6]);

    obiektyHandlowe[7]->przejmijSiec(obiektyHandlowe[8]); // żabka przejmuje biedronkę

    Kupujący* jan = new Maksymalista(this, "Jan", 10.0, pair<double, double>(2.1, 3.7), obiektyHandlowe[0]);
    Kupujący* john = new Minimalista(this, "John", 101.0, pair<double, double>(-15.0, 3.0), obiektyHandlowe[3]);
    Kupujący* basia = new Losowy(this, "Basia", 5.0, pair<double, double>(-4.0, 7.5), obiektyHandlowe[4], 100);
    Kupujący* jacek = new Oszczędny(this, "Jacek", 200.0, pair<double, double>(-9.0, 9.0), towary[5]);
    Kupujący* jeremiasz = new Tradycjonalista(this, "Jeremiasz", 39.0, pair<double, double>(90.90, -7.77), towary[6]);

    dodajKupujący(jan);
    dodajKupujący(john);
    dodajKupujący(basia);
    dodajKupujący(jacek);
    dodajKupujący(jeremiasz);

    wypisz();

    for(Kupujący* kupujący1 : kupujący) {
        kupujący1->kup();
    }

    wypisz();
}

Miasto::~Miasto() {
    for(ObiektHandlowy* obiektHandlowy : obiektyHandlowe) {
        delete obiektHandlowy;
    }
    for(Towar* towar : towary) {
        delete towar;
    }
    for(Kupujący* kupujący1 : kupujący) {
        delete kupujący1;
    }
}