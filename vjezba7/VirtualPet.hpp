#ifndef VIRTUALPET_HPP
#define VIRTUALPET_HPP
#include <string>

class VirtualPet {
private:
    std::string ime;
    std::string tip;
    int glad;
    int sreca;
    bool budnost;

public:
    VirtualPet();
    VirtualPet(const std::string& ime, const std::string& tip, int glad, int sreca, bool budnost);

    void jedi();
    void spavaj();
    void igraj_se();

    std::string& return_ime();
    std::string& return_tip();
    int return_glad();
    int return_sreca();
    bool return_busnost();

    bool operator==(const VirtualPet& other) const;
    bool operator!=(const VirtualPet& other) const;
    VirtualPet& operator=(const VirtualPet& other);
    VirtualPet& operator++();      
    VirtualPet operator++(int);    
    bool operator<(const VirtualPet& other) const;
    bool operator>(const VirtualPet& other) const;
    bool operator<=(const VirtualPet& other) const;
    bool operator>=(const VirtualPet& other) const;
    friend std::ostream& operator<<(std::ostream& os, const VirtualPet& ljubimac);

};
#endif


