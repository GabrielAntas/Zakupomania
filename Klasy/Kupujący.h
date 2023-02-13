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
        virtual void wypisz() const = 0;
        virtual ~Kupujący() = default;
        Kupujący(const Kupujący&) = default;
        Kupujący& operator=(const Kupujący&) = default;
};