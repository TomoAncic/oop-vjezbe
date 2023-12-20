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
};
#endif


