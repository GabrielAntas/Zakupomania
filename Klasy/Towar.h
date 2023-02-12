#pragma once
#include <string>

using namespace std;

class Towar {
    string nazwa;
    
    public:
        Towar(string _nazwa);
        string dajNazwe() const;
};