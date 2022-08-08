#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include "PlikZUzytkownikami.h"


#include <iostream>
#include <vector>

using namespace std;


class UzytkownikMenedzer{

    PlikZUzytkownikami plikZUzytkownikami;
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;


    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


    public:

     int pobierzIdZalogowanegouzytkownika();

     UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {

       uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
          idZalogowanegoUzytkownika = 0;

        }

     void rejestracjaUzytkownika();
     void wypiszWszystkichUzytkownikow();
     void logowanieUzytkownika();
     void zmianaHaslaZalogowanegoUzytkownika();
     void wylogowanieUzytkownika();


};






#endif // KSIAZKAADRESOWA_H
