#include <iostream>
#include "Miasto.h"
#include "Maksymalista.h"
#include "Sklep.h"
#include "Siec.h"
#include "Towar.h"
#include "MyDebugger.h"
#include "ObiektHandlowy.h"

using namespace std;

Miasto::Miasto(string _nazwa)
    : obiektyHandlowe{}, towary{}, kupujący{}, nazwa{_nazwa} {}

void Miasto::dodajObiektHandlowy(ObiektHandlowy* obiektHandlowy) {
    obiektyHandlowe.push_back(obiektHandlowy);
}

void Miasto::dodajTowar(Towar* towar) {
    towary.push_back(towar);
}

void Miasto::initTest() {
    MyDebugger::debug("Miasto: " + nazwa);

    Sklep żabka1(this, "Żabka 1", pair<double, double>(.0, .0));
    Sklep żabka2(this, "Żabka 2", pair<double, double>(-30.0, -11.93));
    Sklep żabka3(this, "Żabka 3", pair<double, double>(15.6, -7.7));
    Sklep sklepKawiorowy(this, "Sklep Kawiorowy", pair<double, double>(3.14, 2.72));
    Sklep stonka(this, "Stonka", pair<double, double>(10.2, -5.6));
    Sklep biedronka1(this, "Biedronka 1", pair<double, double>(3.3, -19.58));
    Sklep biedronka2(this, "Biedronka 2", pair<double, double>(-2.5, 24.2));

    dodajObiektHandlowy(&żabka1);
    dodajObiektHandlowy(&żabka2);
    dodajObiektHandlowy(&żabka3);
    dodajObiektHandlowy(&sklepKawiorowy);
    dodajObiektHandlowy(&stonka);
    dodajObiektHandlowy(&biedronka1);
    dodajObiektHandlowy(&biedronka2);

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

    obiektyHandlowe[0]->dodajTowar(kremówka, 10);
    obiektyHandlowe[0]->ustalCene(kremówka, 15.0);
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
    
    ObiektHandlowy* żabka = new Siec(this, "Żabka");
    ObiektHandlowy* biedronka = new Siec(this, "Biedronka");

    dodajObiektHandlowy(żabka);
    dodajObiektHandlowy(biedronka);

    obiektyHandlowe[7]->przejmijSklep(obiektyHandlowe[0]);
    obiektyHandlowe[7]->przejmijSklep(obiektyHandlowe[1]);
    obiektyHandlowe[7]->przejmijSklep(obiektyHandlowe[2]);

    obiektyHandlowe[8]->przejmijSklep(obiektyHandlowe[5]);
    obiektyHandlowe[8]->przejmijSklep(obiektyHandlowe[6]);

    żabka->przejmijSiec(obiektyHandlowe[8]); // zdebugować gdy nullptr

    Maksymalista* jan = new Maksymalista(this, "Jan", 10.0, pair<double, double>(2.1, 3.7), &żabka1);
}