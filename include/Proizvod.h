#pragma once
#include<string>

class Proizvod{
    int sifra;
    std::string naziv;
    int kolicina;
    double cijena;
    int minimalna_zaliha;
    public:
    Proizvod( int sifra, const std::string &naziv, int kolicina,
    double cijena,
    int minimalna_zaliha);
    int DajSifru() const;
    std::string DajNaziv() const;
    int DajKolicinu() const;
    double DajCijenu() const;
    int DajMinimalnuZalihu() const;
    void PostaviKolicinu(int novaKolicina);
    void PostaviCijenu(double novaCijena);

    double UkupnaVrijednost() const;
    bool JeMalaZaliha() const;
    void Ispisi() const;

};
