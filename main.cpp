#include <iostream>
#include <vector>
#include "Klasy/Siec.h"
#include "Klasy/Sklep.h"

using namespace std;

int main()
{
    Sklep sklep;
    Siec siec(sklep);
    siec.drukuj();
    sklep.drukuj();
    //siec.sklepy.push_back(sklep);
    cout << "b\n";
    return 0;
}