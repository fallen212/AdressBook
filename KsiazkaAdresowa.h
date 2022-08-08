#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"



using namespace std;


class KsiazkaAdresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    char wybor = {};


    char wybierzOpcjeZMenuGlownego();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wywolajOdpowiedniaFunkcjeMenuUzytkownika(char wybor);
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void wylogowanieUzytkownika();
    void wywolajOdpowiedniaFunkcjeMenuGlowne(char wybor);
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();

public:


    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {

        adresatMenedzer = NULL;

        wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
        wywolajOdpowiedniaFunkcjeMenuGlowne(wybor);

    }
    ~KsiazkaAdresowa() {

        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }


    void wypiszWszystkichUzytkownikow();


};

#endif // KSIAZKAADRESOWA_H
