#ifndef OWNER_HPP
#define OWNER_HPP
#include <vector>
#include "VirtualPet.hpp"

class Owner {
private:
    std::string ime;
    std::vector<VirtualPet> ljubimci;

public:
    Owner(const std::string& ime);

    void dodaj_ljubimca(VirtualPet ljubimac);
    void radnja();

    std::string& return_ime();
    std::vector<VirtualPet>& return_ljubimci();
    VirtualPet najsretniji();
};
#endif
