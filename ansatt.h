#ifndef ANSATT_H
#define ANSATT_H
#include <vector>
#include <memory>
#include "person.h"

// Antar at denne klassen skal arve fra person
class Ansatt : public Person {
private:
    bool super_mentor = false; // er den ansatte en super-mentor?
    std::unique_ptr<Ansatt> mentor = nullptr; // Bruker Ansatt-objekt i stedet for Person-objekt
    std::vector<Ansatt*> ansatte;
    //int mentor_nivå = 0;// Teller mentor nivå
public:
    Ansatt(std::string, unsigned int);
    Ansatt(Person&&);
    bool legg_til_ansatt(Ansatt*); // tilknytter en person/legger de i ansatte
    bool har_mentor();
    void tilknytt_mentor(Ansatt&);
    void set_super_mentor(bool);
    Ansatt* get_mentor();

    // Gir oss en oversikt over objektet
    std::string to_string();
    std::string list_ansatte();
};

#endif // ANSATT_H
