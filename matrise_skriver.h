#ifndef MATRISE_SKRIVER_H
#define MATRISE_SKRIVER_H
#include <vector>
#include <string>


class matrise_skriver
{

public:
    matrise_skriver();
    void skriv_ut_simulering();

private:
    std::vector<std::vector<char>> matrise_simulering;// (N, vector<char>(N));
    std::string utskrift_kommando_streng;
    void lag_kommando_streng(std::vector<unsigned long long> heltall_vektor);
};

#endif // MATRISE_SKRIVER_H
