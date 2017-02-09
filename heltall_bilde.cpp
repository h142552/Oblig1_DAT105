#include "heltall_bilde.h"

int heltall_bilde::size = sizeof(unsigned long long) * 8;

heltall_bilde::heltall_bilde() {
    this->heltall_vektor.reserve(this->size);
    this->init();
}

void heltall_bilde::init() {
    if(this->heltall_vektor.size() == 0)
        for(int i = 0; i < heltall_bilde::size; i++)
            this->heltall_vektor.push_back(0);
    else
        for(int i = 0; i < heltall_bilde::size; i++)
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

    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
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

void heltall_bilde::lag_bilde(char B, int k = 0) { // bruke switch?
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

void heltall_bilde::lagre_bilde(std::string filnavn, fil_format ff) {
    std::ofstream utfil;
    utfil.open(filnavn);

    switch (ff) {
    case fil_format::Tekst: {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
            for(int j = 0; j < heltall_bilde::size; j++)
                ((this->heltall_vektor[i] & (unsigned long long)1<<j) > 0)
                    ? (utfil << 'W') : (utfil << '_');

            utfil << std::endl;
        }

        break;
    }
    case fil_format::Tall: {
        for(unsigned long long heltall : this->heltall_vektor)
            utfil << heltall << std::endl;

        break;
    }
    case fil_format::Bin: {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            for(int j = 0; j < heltall_bilde::size; j++)
                utfil << ((this->heltall_vektor[i] & ((unsigned long long)1<<j)) > 0) ? 1 : 0;

        break;
    }
    default: {
        std::cout << "Feil filformat" << std::endl;
        break;
    }
    } // switch

    utfil.close();
}

void heltall_bilde::les_bilde(std::string filnavn, fil_format ff) {
    this->init(); // Lettest å nullstille bildet før lesing
    std::ifstream innfil;
    innfil.open(filnavn);

    switch (ff) {
    case fil_format::Tekst: {
        char c;
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
            for(int j = 0; j < heltall_bilde::size; j++) {
                innfil >> c; // må bruke >> for å hoppe over whitespace
                if(c == 'W') // if plass j = W -> vect[i] plass j = 1
                    this->heltall_vektor[i] = this->heltall_vektor[i] | (unsigned long long)1<<j;
            }
        }
    }
    case fil_format::Tall: {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            innfil >> this->heltall_vektor[i];

        break;
    }
    case fil_format::Bin: {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            for(int j = 0; j < heltall_bilde::size; j++)
                if(innfil.get() == '1') // if plass j = 1 -> vect[i] plass j = 1
                    this->heltall_vektor[i] = this->heltall_vektor[i] | (unsigned long long)1<<j;

        break;
    }
    default: { // umulig å komme til denne casen?
        std::cout << "Feil format" << std::endl;
        break;
    }
    } // switch

    innfil.close();
}
