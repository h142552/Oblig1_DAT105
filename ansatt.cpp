#include "ansatt.h"
#include <iostream>

Ansatt::Ansatt(std::string navn, unsigned int pnr)
    : Person(navn, pnr) { ansatte.reserve(10); }

Ansatt::Ansatt(Person &&p)
    : Person(std::move(p)) { ansatte.reserve(10); }

bool Ansatt::legg_til_ansatt(Ansatt *ansatt) {
    // OBS! sjekker ikke 4 nivå opp etter mentor

    if(ansatte.size() <	10) {
        // Ville gjerne sette *this som mentor, men da flyttes denne klassen, og kan ikke brukes
        ansatte.push_back(ansatt);
        return true;
    }
    else return false;
}

bool Ansatt::har_mentor() { // Sjekker om en ansatt har en mentor
    if(this->mentor == nullptr) return false;
    else return true;
}

void Ansatt::tilknytt_mentor(Ansatt& mentor) {
    if(!super_mentor)
        this->mentor = std::make_unique<Ansatt>(std::move(mentor));
}

void Ansatt::set_super_mentor(bool super_mentor) {
    this->super_mentor = super_mentor;
    this->mentor = nullptr;
}

std::string Ansatt::to_string() {
    return (
        Person::to_string() +
        "Antall ansatte:\t" + std::to_string(this->ansatte.size()) + "\n" +
        "Er super-mentor:" + std::to_string(this->super_mentor) + "\n" +
        "Mentor:\t\t" + (har_mentor()
            ? (this->mentor->get_navn()) : ("NULL")) + "\n"
    );
}

std::string Ansatt::list_ansatte() {
    std::string ansatte_string = "Ansatte:\n";
    for(auto a : ansatte) {
        ansatte_string += a->to_string();
    }
    return ansatte_string;
}
