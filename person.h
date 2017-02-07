#ifndef PERSON_H
#define PERSON_H
#include <string>

namespace oppgave5 {
class Person
{
private:
    Person tilknyttet;
    std::string navn;
    unsigned int pnr;
public:
    Person(); // trengs denne?
    Person(std::string _navn, unsigned int _pnr);
};
}

#endif // PERSON_H
