#ifndef ANSATTDATA_H
#define ANSATTDATA_H
#include "ansatt.h"
#include <vector>


class AnsattData : public Ansatt {
private:
    std::vector<Person*> paarorende;
    int banknummer;
    unsigned int lonn;
    char stillingstype;
public:
    AnsattData(std::string, unsigned int);
    AnsattData(Ansatt&&);
    void set_paarorende(Person*);
    void set_banknummer(int);
    void set_lonn(unsigned int);
    void set_stillingstype(char);

    // Gir oss en oversikt over objektet
    std::string to_string();
};

#endif // ANSATTDATA_H
