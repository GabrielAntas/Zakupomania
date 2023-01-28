#include <iostream>
#include "Siec.h"

Siec::Siec() {
    
}

void Siec::drukuj() {
    std::cout << "Siec\n";
    return;
}

Siec::Siec(Sklep& sklep)
{
    sklepy.push_back(&sklep);
}