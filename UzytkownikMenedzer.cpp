#include "UzytkownikMenedzer.h"


int UzytkownikMenedzer::pobierzIdZalogowanegouzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}


Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    string login = "";
    string haslo = "";

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()));

    cout << "Podaj haslo: ";
    cin >> haslo;
    cin.get();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    int iloscUzytkownikow = uzytkownicy.size();

    for(int i = 0; i < iloscUzytkownikow; ++i) {

        if(uzytkownicy[i].pobierzLogin() == login) {

            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }

    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {

    int iloscUzytkownikow = uzytkownicy.size();

    for (int j = 0; j < iloscUzytkownikow; ++j) {
        cout << uzytkownicy[j].pobierzId() <<endl;
        cout << uzytkownicy[j].pobierzLogin() <<endl;
        cout << uzytkownicy[j].pobierzHaslo() <<endl;
    }

}


void UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    int iloscUzytkownikow = uzytkownicy.size();

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();


    for (int i = 0; i < iloscUzytkownikow; ++i) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo) {
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();

                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    int iloscUzytkownikow = uzytkownicy.size();

    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int j = 0; j < iloscUzytkownikow; ++j) {
        if (uzytkownicy[j].pobierzId() == idZalogowanegoUzytkownika) {
            uzytkownicy[j].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogowanieUzytkownika() {

    idZalogowanegoUzytkownika = 0;
}

