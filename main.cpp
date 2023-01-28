#include <iostream>
#include <vector>

using namespace std;

class Sklep;

class Siec {
    vector<Sklep*> sklepy;
    public:
        Siec();
        Siec(Sklep&);
        void drukuj();
        void dodaj_sklep(Sklep&);
};
//test
class Sklep {
    Siec* siec;
    public:
        void drukuj();
};

Siec::Siec() {
    
}

void Siec::drukuj() {
    cout << "Siec\n";
    return;
}

Siec::Siec(Sklep& sklep)
{
    sklepy.push_back(&sklep);
}

void Sklep::drukuj() {
    cout << "Sklep\n";
    return;
}

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