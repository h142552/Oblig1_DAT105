#ifndef HELTALL_BILDE_H
#define HELTALL_BILDE_H
#include <vector>
#include <iostream>

class heltall_bilde
{
private:
    std::vector<unsigned long long> heltall_vektor;
    static int size;
public:
    heltall_bilde();
    void init(); // alle elementene settes til 0
    void lag_bilde(char B, int k);
    void skriv_ut();
    bool operator==(const heltall_bilde&);
    heltall_bilde& operator+(const heltall_bilde&);
    heltall_bilde& operator~();

    struct size_mismatch_exception {};
};

#endif // HELTALL_BILDE_H
