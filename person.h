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
    Person(Person&&);
    std::string get_navn();
    unsigned int get_pnr();
    void tilknytt(Person&);

    // Gir oss en oversikt over objektet
    std::string to_string();
};

#endif // PERSON_H
