#pragma once
#include "Proizvod.h"
#include<vector>
#include<string>

class Inventar{
std::vector<Proizvod>proizvodi;
int NadjiIndeks(int sifra) const;
public:
void DodajProizvod(const Proizvod &p);
void Ispisi() const;
double UkupnaVrijednostZaliha() const;
void AzurirajKolicinu(int sifra, int nova_kolicina);
void PrikaziMaleZalihe() const;
const Proizvod& Pretrazi(int sifra) const;
void SpremiUDatoteku(const std::string &putanja) const;
void UcitajIzDatoteke(const std::string &putanja);

};