#include "ansatt.h"

Ansatt::Ansatt(Person &p)
    : Person(p.get_navn(), p.get_pnr()) { }

Ansatt::Ansatt(std::string navn, unsigned int pnr)
    : Person(navn, pnr) { }

bool Ansatt::legg_til_ansatt(Person &ansatt) {
    if(ansatte.size() <	10) {
        // sjekk 4-nivå opp + legg til

        return true;
    }
    else return false;
}

bool Ansatt::har_mentor() { // Sjekker om en ansatt har en mentor
    if(this->mentor == nullptr) return false;
    else return true;
}

void Ansatt::tilknytt_mentor(Person& mentor) {
    if(!super_mentor)
        this->mentor = std::make_unique<Person>(std::move(mentor));
}

void Ansatt::set_super_mentor(bool super_mentor) {
    this->super_mentor = super_mentor;
}

// Kan ha en metode leggTilAnsatt, som sjekker kriteriene for ansatte
// må kanskje ha en tilknyttet mentor i Ansatt
/*
 * en ansatt er tilknyttet en eller ingen mentor
 * en ansatt kan være mentor til opptil 10 ansatte (og ikke seg selv)
 * kan være 4 nivåer ansatt-mentor
 * en super-mentor har ingen mentor (bruke bool supermentor i Ansatt?)
 *
 *
 */
