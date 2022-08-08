#ifndef _PLIKZADRESATAMI_H
#define _PLIKZADRESATAMI_H

#include <fstream>
#include <vector>

#include "MetodyPomocnicze.h"
#include "Adresat.h"


class PlikZAdresatami {


    string NAZWA_PLIKU_Z_ADRESATAMI;
    string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = NAZWA_PLIKU_Z_ADRESATAMI + "Tymczasowy.txt";

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);


public:

    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {}

    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

};



#endif // _PLIKZADRESATAMI_H
