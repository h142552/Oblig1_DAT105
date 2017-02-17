#ifndef HELTALL_BILDE_H
#define HELTALL_BILDE_H
#include <vector>
#include <iostream>
#include <fstream>

class heltall_bilde
{
public:
    enum class fil_format { Tall, Tekst, Bin };
    struct size_mismatch_exception {};
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
    void lagre_bilde(std::string, fil_format);
    void les_bilde(std::string, fil_format);
    void lag_sirkler(int, int);

    std::vector<unsigned long long> get_heltall_vektor();

};

#endif // HELTALL_BILDE_H
