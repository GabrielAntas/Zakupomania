#pragma once
#include <string>
#include <iostream>

using namespace std;

class Miasto;

class Kupujący {
    protected:
        Miasto* miasto;
        string imie;
        double budżet;
        pair<double, double> położenie;
        Kupujący(Miasto* _miasto, string _imie, double _budżet, pair<double, double> _położenie);
    public:
        virtual bool kup() = 0;
        friend ostream& operator<<(ostream& os, const Kupujący& dt);
};