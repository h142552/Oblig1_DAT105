#ifndef ANSATTDATA_H
#define ANSATTDATA_H
#include "ansatt.h"
#include <vector>


class AnsattData : public Ansatt {
private:
    std::vector<Person*> paarorende;
    int banknummer;
    unsigned int lonn;
    char stillingstype; // super_mentor/ikke?
public:
    AnsattData(Ansatt&);
    AnsattData(std::string, unsigned int);
    void set_paarorende(Person*);
    void set_banknummer(int);
    void set_lonn(unsigned int);
    void set_stillingstype(char);

    std::string to_string();
};

#endif // ANSATTDATA_H
