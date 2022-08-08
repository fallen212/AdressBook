#include "KsiazkaAdresowa.h"



void KsiazkaAdresowa::rejestracjaUzytkownika() {

    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {

    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {

    adresatMenedzer -> wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();

    if ( MetodyPomocnicze::czyZalogowany( uzytkownikMenedzer.pobierzIdZalogowanegouzytkownika() ) ) {

        adresatMenedzer = new AdresatMenedzer( NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegouzytkownika() );
    }


}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

    if ( uzytkownikMenedzer.pobierzIdZalogowanegouzytkownika() > 0 )
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
    else
        cout << "Logowanie niemozliwe. Niezalogowany uzytkownik! \n\n";
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {

    if ( uzytkownikMenedzer.pobierzIdZalogowanegouzytkownika() > 0 ) {
        uzytkownikMenedzer.wylogowanieUzytkownika();
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }

    else
        cout << "Niezalogowany uzytkownik \n\n";

}

void KsiazkaAdresowa::dodajAdresata() {

    adresatMenedzer -> dodajAdresata();

}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {

    adresatMenedzer -> wyszukajAdresatowPoImieniu();

}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {

    adresatMenedzer -> wyszukajAdresatowPoNazwisku();

}

void KsiazkaAdresowa::usunAdresata() {

    adresatMenedzer -> usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata() {

    adresatMenedzer -> edytujAdresata();
}



void KsiazkaAdresowa::wywolajOdpowiedniaFunkcjeMenuGlowne(char wybor) {

    while(true) {

        switch(wybor) {

        case '1':
            rejestracjaUzytkownika();
            goto label;
            break;
        case '2':
label:
            logowanieUzytkownika();
            if ( uzytkownikMenedzer.pobierzIdZalogowanegouzytkownika() > 0 ) {
                wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
                wywolajOdpowiedniaFunkcjeMenuUzytkownika(wybor);
            }

            break;
        case '9':
            exit(0);
            break;
        default:
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
            break;
        }

    }


}

void KsiazkaAdresowa::wywolajOdpowiedniaFunkcjeMenuUzytkownika(char wybor) {

    while(true) {


        switch(wybor) {

        case '1':
            dodajAdresata();
            break;
        case '2':
            wyszukajAdresatowPoImieniu();
            break;
        case '3':
            wyszukajAdresatowPoNazwisku();
            break;
        case '4':
            wypiszWszystkichAdresatow();
            break;
        case '5':
            usunAdresata();
            break;
        case '6':
            edytujAdresata();
            break;
        case '7':
            zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            wylogowanieUzytkownika();
            wywolajOdpowiedniaFunkcjeMenuGlowne('0');
            break;
        case '9':
            wywolajOdpowiedniaFunkcjeMenuGlowne('0');
            break;
        default:
            cout << "Nie ma takiego wyboru! \n\n";
            system("pause");
            break;
        }

        wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

    }



}











