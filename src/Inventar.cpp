#include "Inventar.h"
#include<iostream>


void Inventar::DodajProizvod(const Proizvod &p){
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