#ifndef ANSATT_H
#define ANSATT_H
#include <vector>
#include <memory>
#include "person.h"

// antar at denne klassen skal arve fra person
class Ansatt : public Person {
private:
    bool super_mentor = false; // er den ansatte en super-mentor?
    //Person mentor = nullptr; // bruke smart-peker?
    std::unique_ptr<Person> mentor = nullptr;
    std::vector<Person> ansatte;
public:
    Ansatt(Person&);
    Ansatt(std::string, unsigned int);
    bool legg_til_ansatt(Person&); // tilknytter en person/legger de i ansatte
    bool har_mentor();
    void tilknytt_mentor(Person&);
    void set_super_mentor(bool);
};

#endif // ANSATT_H
