#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Inventar.h"

const std::string DATOTEKA = "data/inventar.txt";

std::string CitajRed(const std::string& poruka) {
    std::cout << poruka;
    std::string red;
    if (!std::getline(std::cin, red)) {
        std::exit(0);   // kraj unosa (Ctrl+D)
    }
    return red;
}

int CitajInt(const std::string& poruka) {
    while (true) {
        std::string red = CitajRed(poruka);
        try {
            size_t pos;
            int v = std::stoi(red, &pos);
            if (pos == red.size()) return v;
        } catch (const std::exception&) {}
        std::cout << "Unesi cijeli broj.\n";
    }
}

double CitajDouble(const std::string& poruka) {
    while (true) {
        std::string red = CitajRed(poruka);
        try {
            size_t pos;
            double v = std::stod(red, &pos);
            if (pos == red.size()) return v;
        } catch (const std::exception&) {}
        std::cout << "Unesi broj.\n";
    }
}

void IspisiMeni() {
    std::cout << "\n===== INVENTAR =====\n"
              << "1. Dodaj proizvod\n"
              << "2. Azuriraj kolicinu\n"
              << "3. Pretrazi proizvod\n"
              << "4. Prikazi sve\n"
              << "5. Prikazi male zalihe\n"
              << "6. Ukupna vrijednost zaliha\n"
              << "7. Spremi u datoteku\n"
              << "8. Ucitaj iz datoteke\n"
              << "0. Izlaz\n";
}

void DodajProizvodMeni(Inventar& inv) {
    int sifra = CitajInt("Sifra: ");
    std::string naziv = CitajRed("Naziv: ");
    int kolicina = CitajInt("Kolicina: ");
    double cijena = CitajDouble("Cijena: ");
    int minZaliha = CitajInt("Minimalna zaliha: ");
    inv.DodajProizvod(Proizvod(sifra, naziv, kolicina, cijena, minZaliha));
    std::cout << "Proizvod dodan.\n";
}

void AzurirajKolicinuMeni(Inventar& inv) {
    int sifra = CitajInt("Sifra proizvoda: ");
    int kolicina = CitajInt("Nova kolicina: ");
    inv.AzurirajKolicinu(sifra, kolicina);
    std::cout << "Kolicina azurirana.\n";
}

void PretraziMeni(const Inventar& inv) {
    int sifra = CitajInt("Sifra proizvoda: ");
    inv.Pretrazi(sifra).Ispisi();
}

int main() {
    Inventar inv;

    try {
        inv.UcitajIzDatoteke(DATOTEKA);
    } catch (const std::exception&) {
        // datoteka jos ne postoji, krecemo s praznim inventarom
    }

    int izbor;
    do {
        IspisiMeni();
        izbor = CitajInt("Izbor: ");

        try {
            switch (izbor) {
                case 1: DodajProizvodMeni(inv); break;
                case 2: AzurirajKolicinuMeni(inv); break;
                case 3: PretraziMeni(inv); break;
                case 4: inv.Ispisi(); break;
                case 5: inv.PrikaziMaleZalihe(); break;
                case 6:
                    std::cout << "Ukupna vrijednost zaliha: "
                              << inv.UkupnaVrijednostZaliha() << std::endl;
                    break;
                case 7:
                    inv.SpremiUDatoteku(DATOTEKA);
                    std::cout << "Spremljeno.\n";
                    break;
                case 8:
                    inv.UcitajIzDatoteke(DATOTEKA);
                    std::cout << "Ucitano.\n";
                    break;
                case 0:
                    std::cout << "Dovidjenja!\n";
                    break;
                default:
                    std::cout << "Nepoznata opcija.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Greska: " << e.what() << std::endl;
        }
    } while (izbor != 0);

    return 0;
}