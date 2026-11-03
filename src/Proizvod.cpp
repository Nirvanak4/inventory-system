#include "Proizvod.h"
#include<iostream>
#include<stdexcept>

Proizvod::Proizvod(int sifra, const std::string &naziv, int kolicina,
    double cijena,
    int minimalna_zaliha):sifra(sifra), naziv(naziv), kolicina(kolicina),
    cijena(cijena), minimalna_zaliha(minimalna_zaliha){}
    int Proizvod::DajSifru() const{
        return sifra;
    }
    std::string Proizvod::DajNaziv() const{
        return naziv;
    }
    int Proizvod::DajKolicinu() const{
        return kolicina;
    }
    double Proizvod::DajCijenu() const{
        return cijena;
    }
    int Proizvod::DajMinimalnuZalihu() const{
        return minimalna_zaliha;
    }

    void Proizvod::PostaviKolicinu(int nova_kolicina){
        if(nova_kolicina<0)
        throw std::domain_error("Kolicina ne smije biti negativna. ");
        kolicina=nova_kolicina;
    }
    void Proizvod::PostaviCijenu(double nova_cijena){
        if(cijena<0) throw std::domain_error("Cijena ne smije biti negativna. ");
        cijena=nova_cijena;
    }
    
    double Proizvod::UkupnaVrijednost() const{
        return kolicina*cijena;
    }
    bool Proizvod::JeMalaZaliha() const{
        return kolicina<=minimalna_zaliha;
    }
    void Proizvod::Ispisi() const{
        std::cout<<"["<<sifra<<"] "<<naziv<<" | kol: "<<kolicina<<
        " | cijena: "<<cijena<<" | vrijednost: "<<UkupnaVrijednost();
        if(JeMalaZaliha())
        std::cout<<" (MALA ZALIHA!)";
    std::cout<<std::endl;
    }