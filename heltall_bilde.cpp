#include "heltall_bilde.h"

int heltall_bilde::size = sizeof(unsigned long long) * 8;

heltall_bilde::heltall_bilde() {
    this->heltall_vektor.reserve(this->size);
    this->init();
}

void heltall_bilde::init() {
    if(this->heltall_vektor.size() == 0)
        for(unsigned int i = 0; i < this->size; i++)
            this->heltall_vektor.push_back(0);
    else
        for(unsigned int i = 0; i < this->size; i++)
            this->heltall_vektor[i] = 0;
}

void heltall_bilde::skriv_ut() {
    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
        for(int j = 0; j < this->size; j++)
            ((this->heltall_vektor[i] & (unsigned long long)1<<j) > 0)
                ? (std::cout << 'W') : (std::cout << '_');

        std::cout << std::endl;
    }
}

bool heltall_bilde::operator==(const heltall_bilde& rhs) {
    if(this->heltall_vektor.size() != rhs.heltall_vektor.size())
        return false;

    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
        for(int j = 0; j < heltall_bilde::size; j++)
            if((this->heltall_vektor[i] & (unsigned long long)1<<j)
                    != (rhs.heltall_vektor[i] & (unsigned long long)1<<j))
                return false;

    return true;
}

heltall_bilde& heltall_bilde::operator+(const heltall_bilde& rhs) {
    if(this->heltall_vektor.size() != rhs.heltall_vektor.size())
        throw heltall_bilde::size_mismatch_exception();

    for(int i = 0; i < this->heltall_vektor.size(); i++) {
        this->heltall_vektor[i] = this->heltall_vektor[i] | rhs.heltall_vektor[i];
    }

    return *this;
}

heltall_bilde& heltall_bilde::operator~() {
    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
        this->heltall_vektor[i] = ~this->heltall_vektor[i];
    }

    return *this;
}

void heltall_bilde::lag_bilde(char B, int k = 0) {
    if(B == '0') {
        this->init();
    }
    else if(B == '1') {
        this->heltall_vektor[0] = 1;
    }
    else if(B == '\\') {
        int i = 0;
        while(k < this->size) {
            this->heltall_vektor[i] = this->heltall_vektor[i]
                    | (unsigned long long)1<<k; // setter k-te bit i element nr. i til 1

            ++i;
            ++k;
        }
    }
    else if(B == '/') {
        int i = 0;
        while(k > 0) {
            this->heltall_vektor[i] = this->heltall_vektor[i]
                    | (unsigned long long)1<<(k-1);

            ++i;
            --k;
        }
    }
    else if(B == '|') {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            this->heltall_vektor[i] = this->heltall_vektor[i]
                    | (unsigned long long)1<<k;
    }
    else if(B == '-') {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            this->heltall_vektor[k] = this->heltall_vektor[k]
                | (unsigned long long)1<<i;
    }
    else
        std::cout << "Feil parameter." << std::endl;
}
