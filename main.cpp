#include <iostream>
#include <vector>
#include <string>
#include "Klasy/Siec.h"
#include "Klasy/Sklep.h"
#include "Klasy/Kupujący.h"
#include "Klasy/MyDebugger.h"
#include "Klasy/Miasto.h"

using namespace std;

int main()
{
    MyDebugger debugger;
    debugger.setDebugMode(true);
    Miasto m{"Wadowice"};
    m.initTest();

    map<double, int> mp;
    mp[.5] = 3;
    cout << mp[.4];
}