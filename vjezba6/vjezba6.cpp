#include "Owner.hpp"
#include "VirtualPet.hpp"
#include <iostream>
using namespace std;

int main() {

    int br_a = 5;

    Owner vlasnik1("Ante");
    Owner vlasnik2(vlasnik1);

    VirtualPet ljub1("Rex", "Pas", 14, 8, true);
    VirtualPet ljub2("Kiki", "Macka", 9, 12, true);
    VirtualPet ljub3("Niko", "Hrcak", 7, 15, true);

    vlasnik1.dodaj_ljubimca(ljub1);
    vlasnik1.dodaj_ljubimca(ljub2);
    vlasnik1.dodaj_ljubimca(ljub3);

    vlasnik2.dodaj_ljubimca(VirtualPet("Karla", "Papiga", 8, 6, true));
    vlasnik2.dodaj_ljubimca(VirtualPet("Pero", "Riba", 5, 9, true));
    vlasnik2.dodaj_ljubimca(VirtualPet("Dugi", "Zmija", 7, 7, true));

    for (int i = 0; i < br_a; i++)
    {
        vlasnik1.radnja();
        vlasnik2.radnja();
    }

    cout << "ljubimci vlasnika1: " << endl;
    for (auto& ljubimac : vlasnik1.return_ljubimci()) {
        cout << "Ljubimac ime: " << ljubimac.return_ime() << ", " << "Glad: " << ljubimac.return_glad() << ", " << "Sreca: " << ljubimac.return_sreca() << endl;
    }

    cout << "\n";

    cout << "ljubimci vlasnika2: " << endl;
    for (auto& ljubimac : vlasnik2.return_ljubimci()) {
        cout << "Ljubimac ime: " << ljubimac.return_ime() << ", " << "Glad: " << ljubimac.return_glad() << ", " << "Sreca: " << ljubimac.return_sreca() << endl;
    }

    cout << "\n";

    Owner najsretniji = vlasnik1;
    if (vlasnik2.najsretniji().return_sreca() > najsretniji.najsretniji().return_sreca())
    {
        najsretniji = vlasnik2;
    }
    cout << "Najsretniji vlasnik: " << najsretniji.return_ime() << endl;
}
