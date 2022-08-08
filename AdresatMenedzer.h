#ifndef _ADRESATMENEDZER_H
#define _ADRESATMENEDZER_H

#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"


class AdresatMenedzer {

    PlikZAdresatami plikZAdresatami;

    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsuwanegoAdresataA;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);


public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami) {

        this -> idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;

        idOstatniegoAdresata  = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci,idZalogowanegoUzytkownika);

    }

    void wypiszWszystkichAdresatow();

    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();


};










#endif // _ADRESATMENEDZER_H
