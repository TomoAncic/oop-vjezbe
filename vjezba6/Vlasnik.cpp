#include "VirtualPet.hpp"
#include "Owner.hpp"

VirtualPet::VirtualPet(const std::string& ime, const std::string& tip, int glad, int sreca, bool budnost)
{
    this->ime = ime;
    this->tip = tip;
    this->glad = glad;
    this->sreca = sreca;
    this->budnost = budnost;
}

void VirtualPet::jedi() {
    glad -= 2;
    sreca += 3;
}

void VirtualPet::spavaj() {
    if (glad < 5) 
    {
        sreca += 3;
        glad += 2;
        budnost = false;
    }
}

void VirtualPet::igraj_se() {
    sreca += 3;
    glad += 2;
}

std::string& VirtualPet::return_ime(){
    return ime;
}

std::string& VirtualPet::return_tip(){
    return tip;
}

int VirtualPet::return_glad(){
    return glad;
}

int VirtualPet::return_sreca(){
    return sreca;
}

bool VirtualPet::return_busnost(){
    return budnost;
}
