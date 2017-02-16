#include "person.h"

Person::Person(std::string navn, unsigned int pnr) : navn(navn), pnr(pnr) { }

Person::Person(Person&& person) {
    this->navn = person.navn;
    this->pnr = person.pnr;
    this->tilknyttet = (std::move(person.tilknyttet));
}

void Person::tilknytt(Person &tilknyttet) {
    this->tilknyttet = std::make_unique<Person>(std::move(tilknyttet));
}

std::string Person::to_string() {
    return (
        "Navn:\t\t" + this->navn + "\n" +
        "Pnr:\t\t" + std::to_string(this->pnr) + "\n" +
        "Tilknyttet:\t" + ((this->tilknyttet != nullptr)
            ? (this->tilknyttet->get_navn()) : "NULL") + "\n"
    );
}

std::string Person::get_navn() { return this->navn; }

unsigned int Person::get_pnr() { return this->pnr; }
