#include "Inventar.h"
#include<iostream>
#include<stdexcept>
#include<fstream>
#include<sstream>


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
void Inventar::AzurirajKolicinu(int sifra, int nova_kolicina){
    int index=NadjiIndeks(sifra);
    if(index==-1){
        throw std::domain_error("Proizvod s tom sifrom ne postoji. ");
    }
    proizvodi[index].PostaviKolicinu(nova_kolicina);
}
void Inventar::PrikaziMaleZalihe() const{
    bool nadjen=false;
    for(const auto &p:proizvodi){
    if(p.JeMalaZaliha()){
        p.Ispisi();
        nadjen=true;
    }
}
if(!nadjen){
    std::cout<<"Nema proizvoda s niskom zalihom."<<std::endl;
}

}
const Proizvod &Inventar::Pretrazi(int sifra) const{
    int index=NadjiIndeks(sifra);
    if(index==-1){
        throw std::domain_error("Greska");

    }
    return proizvodi[index];

}
void Inventar::SpremiUDatoteku(const std::string &putanja) const{
    std::ofstream izlaz(putanja);
    if(!izlaz){
        throw std::runtime_error("Datoteka se ne moze otvoriti. ");
    }
    for(const auto &p:proizvodi){
       izlaz<<p.DajSifru()<<";"
       <<p.DajNaziv()<<";"
       <<p.DajKolicinu()<<";"
       <<p.DajCijenu()<<";"
       <<p.DajMinimalnuZalihu()<<"\n"; 
    }
}
void Inventar::UcitajIzDatoteke(const std::string& putanja) {
    std::ifstream ulaz(putanja);
    if (!ulaz) {
        throw std::runtime_error("Datoteka se ne moze otvoriti.");
    }

    proizvodi.clear();   

    std::string red;
    while (std::getline(ulaz, red)) {
        if (red.empty()) continue;   

        std::stringstream ss(red);
        std::string sifra, naziv, kolicina, cijena, minZaliha;

        std::getline(ss, sifra, ';');
        std::getline(ss, naziv, ';');
        std::getline(ss, kolicina, ';');
        std::getline(ss, cijena, ';');
        std::getline(ss, minZaliha, ';');

        DodajProizvod(Proizvod(std::stoi(sifra), naziv, std::stoi(kolicina),
                               std::stod(cijena), std::stoi(minZaliha)));
    }
}