#include<iostream>
#include "Inventar.h"

int main(){
    Inventar inv;
    inv.Ispisi();

    inv.DodajProizvod(Proizvod(1, "Laptop", 3, 1200.0, 5));
    inv.DodajProizvod(Proizvod(2, "Miš", 50, 15.0, 10));
    inv.DodajProizvod(Proizvod(3, "Monitor", 8, 300.0, 4));

    inv.Ispisi();
    std::cout<<"Ukupna vrijednost zaliha: "
    <<inv.UkupnaVrijednostZaliha()<<std::endl;
    try{
      inv.DodajProizvod(Proizvod(1, "Tastatura", 5, 40.0, 2));
    }catch(const std::domain_error &e){
        std::cout<<"Greska: "<<e.what()<<std::endl;
    }
    try {
    inv.AzurirajKolicinu(1, 20);    
    inv.Ispisi();
    inv.AzurirajKolicinu(99, 5);    
} catch (const std::exception& e) {
    std::cout << "Greska: " << e.what() << std::endl;
}

try {
    inv.AzurirajKolicinu(1, -5);    
} catch (const std::exception& e) {
    std::cout << "Greska: " << e.what() << std::endl;
}
try {
    inv.Pretrazi(2).Ispisi(); 
    inv.Pretrazi(99).Ispisi();  
} catch (const std::exception& e) {
    std::cout << "Greska: " << e.what() << std::endl;
}
inv.SpremiUDatoteku("data/inventar.txt");
Inventar inv2;
inv2.UcitajIzDatoteke("data/inventar.txt");
inv2.Ispisi();
std::cout << "Ukupna vrijednost: " << inv2.UkupnaVrijednostZaliha() << std::endl;
    return 0;
}