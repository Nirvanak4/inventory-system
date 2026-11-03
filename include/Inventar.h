#pragma once
#include "Proizvod.h"
#include<vector>

class Inventar{
std::vector<Proizvod>proizvodi;
int NadjiIndeks(int sifra) const;
public:
void DodajProizvod(const Proizvod &p);
void Ispisi() const;
double UkupnaVrijednostZaliha() const;
void AzurirajKolicinu(int sifra, int nova_kolicina);
};