#include <iostream>
#include <fstream>
#include <vector>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"


using namespace std;


class PlikZUzytkownikami {

    string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;


    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:

    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami):  NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {}
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik>  wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);


};
