#pragma once
#include "Proizvod.h"
#include<vector>

class Inventar{
std::vector<Proizvod>proizvodi;
public:
void DodajProizvod(const Proizvod &p);
void Ispisi() const;
double UkupnaVrijednostZaliha() const;

};