#include "person.h"

Person::Person(std::string _navn, unsigned int _pnr) : navn(_navn), pnr(_pnr) { }

void Person::tilknytt(Person &tilknyttet) {
    this->tilknyttet = std::make_unique<Person>(std::move(tilknyttet));
}
