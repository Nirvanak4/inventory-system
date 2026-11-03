#include "Inventar.h"
#include<iostream>
#include<stdexcept>


void Inventar::DodajProizvod(const Proizvod &p){
    if(NadjiIndeks(p.DajSifru())!=-1) {
        throw std::domain_error("Proizvod s tom sifrom vec postoji.");
    return;
}
proizvodi.push_back(p);
}
void Inventar::Ispisi() const{
    if(proizvodi.empty()){
        std::cout<<"Inventar je prazan."<<std::endl;
        return;
    }
    for(const auto &p:proizvodi){
     p.Ispisi();
}
}
double Inventar::UkupnaVrijednostZaliha() const{
    double ukupno=0;
    for(const auto &p:proizvodi){
        ukupno+=p.UkupnaVrijednost();
    }
    return ukupno;
}
int Inventar::NadjiIndeks(int sifra) const {
    for (size_t i = 0; i < proizvodi.size(); i++) {
        if (proizvodi[i].DajSifru() == sifra) {
            return static_cast<int>(i);
        }
    }
    return -1;
}