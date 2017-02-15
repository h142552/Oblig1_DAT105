#include "person.h"

Person::Person(std::string navn, unsigned int pnr) : navn(navn), pnr(pnr) { }

void Person::tilknytt(Person &tilknyttet) {
    this->tilknyttet = std::make_unique<Person>(std::move(tilknyttet));
}

std::string Person::get_navn() { return this->navn; }

unsigned int Person::get_pnr() { return this->pnr; }
