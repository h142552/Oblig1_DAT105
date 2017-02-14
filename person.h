#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <memory>

class Person
{
private:
    std::unique_ptr<Person> tilknyttet = nullptr;
    std::string navn;
    unsigned int pnr;
public:
    Person(std::string _navn, unsigned int _pnr);
    void tilknytt(Person&); // smart-peker her? eller ref
};

#endif // PERSON_H
