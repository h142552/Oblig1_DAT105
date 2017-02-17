#ifndef MATRISE_SKRIVER_H
#define MATRISE_SKRIVER_H
#include <vector>
#include <string>
#include "util_heltall.h"


class matrise_skriver
{

public:
    matrise_skriver(std::vector<unsigned long long> heltall_vektor);
    void skriv_ut_simulering();
    std::string get_kommando_streng();

private:
    std::vector<std::vector<char>> matrise_simulering;// (N, vector<char>(N));
    std::string utskrift_kommando_streng;
    void lag_kommando_streng(std::vector<unsigned long long> heltall_vektor);

    char finn_neste(util_heltall&, int);
};

#endif // MATRISE_SKRIVER_H
