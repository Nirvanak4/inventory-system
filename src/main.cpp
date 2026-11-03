#include "Proizvod.h"

int main(){
    Proizvod p(1, "Laptop", 3, 1200.0, 5);
    p.Ispisi();
    p.PostaviKolicinu(10);
    p.Ispisi();
    return 0;
}