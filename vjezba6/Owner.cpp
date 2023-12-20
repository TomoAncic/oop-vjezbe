#include "Owner.hpp"
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

Owner::Owner(const string& ime)
{
    this->ime = ime;
}

void Owner::dodaj_ljubimca(VirtualPet ljubimac) {
    ljubimci.push_back(ljubimac);
}

void Owner::radnja() {
   
    srand(static_cast<unsigned int>(time(0)));
    for (auto& ljubimac : ljubimci) {
        int a = rand() % 3;

        switch (a) {
        case 1:
            ljubimac.igraj_se();
            break;
        case 2:
            ljubimac.jedi();
            break;
        case 3:
            ljubimac.spavaj();
            break;
        }
    }
}

std::string& Owner::return_ime(){
    return ime;
}

std::vector<VirtualPet>& Owner::return_ljubimci(){
    return ljubimci;
}

VirtualPet Owner::najsretniji() {
    VirtualPet najsretniji = ljubimci[0];
    for (auto& ljubimac : ljubimci)
    {
        if (ljubimac.return_sreca() > najsretniji.return_sreca())
        {
            najsretniji = ljubimac;
        }
    }
    return najsretniji;
}

Owner::Owner(const Owner& drugi) :ime(drugi.ime) {
    for (auto& ljubimac : drugi.ljubimci) {
        ljubimci.push_back(VirtualPet(ljubimac));
    }
}
