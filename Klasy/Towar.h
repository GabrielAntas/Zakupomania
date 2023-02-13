#pragma once
#include <string>

using namespace std;

class Towar {
    string nazwa;
    
    public:
        Towar(string _nazwa);
        string dajNazwe() const;
        ~Towar() = default;
        Towar(const Towar&) = default;
        Towar& operator=(const Towar&) = default;
};