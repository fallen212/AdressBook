#include "AdresatMenedzer.h"


void AdresatMenedzer::wypiszWszystkichAdresatow() {

    int iloscAdresatow = adresaci.size();

    for ( int i = 0; i < iloscAdresatow; ++i ) {

        cout << adresaci[i].pobierzId() << endl;
        cout << adresaci[i].pobierzIdUzytkownika() << endl;
        cout << adresaci[i].pobierzImie() << endl;
        cout << adresaci[i].pobierzNazwisko() << endl;
        cout << adresaci[i].pobierzNumerTelefonu() << endl;
        cout << adresaci[i].pobierzEmail() << endl;
        cout << adresaci[i].pobierzAdres() << endl;
    }
    system("pause");

}


void AdresatMenedzer::dodajAdresata() {

    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    ++idOstatniegoAdresata;
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata) {
    Adresat adresat;
    string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "";

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    cin >> imie;
    adresat.ustawImie(imie);
    adresat.ustawImie( MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale( adresat.pobierzImie() ) );

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNazwisko( MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale( adresat.pobierzNazwisko() ) );

    cout << "Podaj numer telefonu: ";
    cin >> nrTelefonu;
    adresat.ustawNumerTelefonu(nrTelefonu);

    cout << "Podaj email: ";
    cin >> email;
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    cin >> adres;
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;
    int iloscAdresatowVector = adresaci.size();

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (int j = 0; j < iloscAdresatowVector; ++j) {
            if (adresaci[j].pobierzImie()  == imiePoszukiwanegoAdresata) {
                MetodyPomocnicze::wyswietlDaneAdresata(adresaci[j]);
                iloscAdresatow++;
            }
        }
        MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;
    int iloscAdresatowVector = adresaci.size();

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (int k = 0; k < iloscAdresatowVector; ++k) {
            if (adresaci[k].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                MetodyPomocnicze::wyswietlDaneAdresata(adresaci[k]);
                iloscAdresatow++;
            }
        }
        MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::usunAdresata() {
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;
    int iloscAdresatow = adresaci.size();

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    vector <Adresat>::iterator itr = adresaci.begin();

    for (int i = 0; i < iloscAdresatow; ++i) {
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                numerLiniiUsuwanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                plikZAdresatami.usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                this -> idUsuwanegoAdresataA = idUsuwanegoAdresata;
                //return idUsuwanegoAdresata;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
        itr++;
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
}

void AdresatMenedzer::edytujAdresata() {
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
   // int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    int iloscAdresatow  = adresaci.size();

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = MetodyPomocnicze::podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < iloscAdresatow; i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie( MetodyPomocnicze::wczytajLinie() );
                adresaci[i].ustawImie( MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale( adresaci[i].pobierzImie() ) );
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko( MetodyPomocnicze::wczytajLinie() );
                adresaci[i].ustawNazwisko( MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale( adresaci[i].pobierzNazwisko() ) );
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu( MetodyPomocnicze::wczytajLinie() );
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail( MetodyPomocnicze::wczytajLinie() );
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres( MetodyPomocnicze::wczytajLinie() );
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata) {
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    plikZAdresatami.edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
