#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <memory>

class Person {
private:
    std::unique_ptr<Person> tilknyttet = nullptr;
    std::string navn;
    unsigned int pnr;
public:
    Person(std::string, unsigned int);
    std::string get_navn();
    unsigned int get_pnr();
    void tilknytt(Person&);
};

#endif // PERSON_H
