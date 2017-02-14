#ifndef ANSATTDATA_H
#define ANSATTDATA_H
#include "ansatt.h"
#include <vector>


class AnsattData : public Ansatt
{
private:
    std::vector<Person> paarorende;
    int banknummer;
    unsigned int lonn;
    char stillingstype; // super_mentor/ikke?
public:
    AnsattData();
    void set_paarorende();
    void set_banknummer();
    void set_lonn();
    void set_stillingstype();
};

#endif // ANSATTDATA_H
