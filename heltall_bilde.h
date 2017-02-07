#ifndef HELTALL_BILDE_H
#define HELTALL_BILDE_H
#include <vector>

class heltall_bilde
{
private:
    std::vector<unsigned long long> heltall_vektor;
public:
    heltall_bilde();
    void init(); // alle elementene settes til 0
    void lag_bilde(char B); // TODO: switch-case på B
};

#endif // HELTALL_BILDE_H
