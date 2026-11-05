# Inventory Management System

Program u C++-u za evidenciju proizvoda na zalihi. Radi u terminalu, a podaci se čuvaju u tekstualnoj datoteci.

## Funkcionalnosti

- Dodavanje proizvoda (šifra, naziv, količina, cijena, minimalna zaliha)
- Ažuriranje količine proizvoda
- Pretraga proizvoda po šifri
- Prikaz svih proizvoda
- Upozorenje na malu zalihu (količina je manja ili jednaka minimalnoj)
- Izračun ukupne vrijednosti zaliha
- Spremanje i učitavanje podataka iz datoteke

## Korišteni koncepti

- Objektno orijentirano programiranje (klase `Proizvod` i `Inventar`, enkapsulacija)
- `std::vector` za čuvanje proizvoda
- Izuzeci (`throw`, `try/catch`) za greške poput duplikata šifre ili nepostojećeg proizvoda
- Rad s datotekama (`ifstream`, `ofstream`)
- Podjela koda na header (`.h`) i implementacijske (`.cpp`) fajlove

## Kompajliranje i pokretanje

Potreban je `g++` s podrškom za C++17. Iz glavnog foldera projekta:

```
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o inventory
./inventory
```

## Primjer upotrebe

```
===== INVENTAR =====
1. Dodaj proizvod
2. Azuriraj kolicinu
3. Pretrazi proizvod
4. Prikazi sve
5. Prikazi male zalihe
6. Ukupna vrijednost zaliha
7. Spremi u datoteku
8. Ucitaj iz datoteke
0. Izlaz
```

Primjer ispisa svih proizvoda:

```
[1] Laptop | kol: 3 | cijena: 1200 | vrijednost: 3600 (MALA ZALIHA!)
[2] Mis | kol: 50 | cijena: 15 | vrijednost: 750
```

## Struktura projekta

```
inventory-system/
├── include/    zaglavlja (Proizvod.h, Inventar.h)
├── src/        izvorni kod (main.cpp, Proizvod.cpp, Inventar.cpp)
├── data/       datoteka s podacima (inventar.txt)
└── README.md
```

## Format datoteke

Svaki red u `data/inventar.txt` je jedan proizvod, a polja su odvojena znakom `;`:

```
sifra;naziv;kolicina;cijena;minimalna_zaliha
1;Laptop;3;1200;5
```

## Moguća poboljšanja

- Brisanje proizvoda
- Pretraga po nazivu
- Čuvanje podataka u SQLite bazi umjesto u tekstualnoj datoteci
- Unit testovi
