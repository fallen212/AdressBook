#ifndef _METODYPOMOCNICZE_H
#define _METODYPOMOCNICZE_H

#include "Adresat.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>



using namespace std;


class MetodyPomocnicze {


public:

    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static bool czyZalogowany(int idZalogowanwgoUzytkownika);
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static char wczytajZnak();
    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();
    static void wyswietlDaneAdresata(Adresat adresat);
    static void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    static int podajIdWybranegoAdresata();
    static int wczytajLiczbeCalkowita();
    static char wybierzOpcjeZMenuEdycja();
};



#endif // _METODYPOMOCNICZE_H
