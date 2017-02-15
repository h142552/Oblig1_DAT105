#include "ansattdata.h"

AnsattData::AnsattData(Ansatt& a)
    : Ansatt(a.get_navn(), a.get_pnr()) { }

AnsattData::AnsattData(std::string navn, unsigned int pnr)
    : Ansatt(navn, pnr) { }

std::string AnsattData::to_string() { // temp
    return (
                "Navn:\t\t" + this->get_navn() + "\n" +
                "Pnr:\t\t" + std::to_string(this->get_pnr()) + "\n" +
                "Lønn:\t\t" + std::to_string(this->lonn) + "\n" +
                "Banknummer:\t" + std::to_string(this->banknummer)
                );
}

void AnsattData::set_paarorende(Person *paarorende) { this->paarorende.push_back(paarorende); }
void AnsattData::set_banknummer(int bnr) { this->banknummer = bnr; }
void AnsattData::set_lonn(unsigned int lonn) { this->lonn = lonn; }
void AnsattData::set_stillingstype(char stillingstype) { this->stillingstype = stillingstype; }
