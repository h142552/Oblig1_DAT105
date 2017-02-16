#include "ansattdata.h"

AnsattData::AnsattData(std::string navn, unsigned int pnr)
    : Ansatt(navn, pnr) { }

AnsattData::AnsattData(Ansatt&& a)
    : Ansatt(std::move(a)) { }

std::string AnsattData::to_string() {
    return (
        Ansatt::to_string() +
        "Lønn:\t\t" + std::to_string(this->lonn) + "\n" +
        "Banknummer:\t" + std::to_string(this->banknummer) + "\n" +
        "Stillingstype:\t" + this->stillingstype + "\n" +
        "Pårørende:\t" + ((paarorende.size() > 0)
            ? this->paarorende[0]->get_navn() : "NULL") + "\n"
    );
}

void AnsattData::set_paarorende(Person *paarorende) { this->paarorende.push_back(paarorende); }
void AnsattData::set_banknummer(int bnr) { this->banknummer = bnr; }
void AnsattData::set_lonn(unsigned int lonn) { this->lonn = lonn; }
void AnsattData::set_stillingstype(char stillingstype) { this->stillingstype = stillingstype; }
