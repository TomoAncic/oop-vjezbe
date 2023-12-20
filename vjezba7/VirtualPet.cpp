#include "VirtualPet.hpp"
#include "Owner.hpp"
#include <iostream>
using namespace std;

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

std::string& VirtualPet::return_ime() {
    return ime;
}

std::string& VirtualPet::return_tip() {
    return tip;
}

int VirtualPet::return_glad() {
    return glad;
}

int VirtualPet::return_sreca() {
    return sreca;
}

bool VirtualPet::return_busnost() {
    return budnost;
}

bool VirtualPet::operator==(const VirtualPet& other) const {
    return ime == other.ime && tip == other.tip && glad == other.glad && sreca == other.sreca && budnost == other.budnost;
}

bool VirtualPet::operator!=(const VirtualPet& other) const {
    return !(*this == other);
}

VirtualPet& VirtualPet::operator=(const VirtualPet& other) {
    if (this != &other) {
        ime = other.ime;
        tip = other.tip;
        glad = other.glad;
        sreca = other.sreca;
        budnost = other.budnost;
    }
    return *this;
}

VirtualPet& VirtualPet::operator++() {
    return *this;
}

VirtualPet VirtualPet::operator++(int) {
    VirtualPet temp = *this;
    ++(*this); 
    return temp;
}

bool VirtualPet::operator<(const VirtualPet& other) const {
    return sreca < other.sreca;
}

bool VirtualPet::operator>(const VirtualPet& other) const {
    return sreca > other.sreca;
}

bool VirtualPet::operator<=(const VirtualPet& other) const {
    return sreca <= other.sreca;
}

bool VirtualPet::operator>=(const VirtualPet& other) const {
    return sreca >= other.sreca;
}

std::ostream& operator<<(std::ostream& os, const VirtualPet& ljubimac) {
    os << "Ime: " << ljubimac.ime << ", " << "Vrsta: " << ljubimac.tip << ", " << "Glad: " << ljubimac.glad << ", " << "Sreca: " << ljubimac.sreca << ", " << "Budnost: " << ljubimac.budnost;
    return os;
}
