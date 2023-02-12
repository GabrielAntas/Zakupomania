#include <iostream>
#include <vector>
#include <string>
#include "Klasy/Siec.h"
#include "Klasy/Sklep.h"
#include "Klasy/Kupujący.h"
#include "Klasy/MyDebugger.h"

using namespace std;

int main()
{
    MyDebugger debugger;
    debugger.setDebugMode(true);
    Miasto m{"Wadowice"};
    m.initTest();
}