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

void heltall_bilde::lagre_bilde(std::string filnavn, fil_format ff) {
    std::ofstream utfil;
    utfil.open(filnavn);

    if(ff == fil_format::Tekst) {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
            for(int j = 0; j < this->size; j++)
                ((this->heltall_vektor[i] & (unsigned long long)1<<j) > 0)
                    ? (utfil << 'W') : (utfil << '_');

            utfil << std::endl;
        }
    }
    else if(ff == fil_format::Tall) {
        //for(int i = 0; i < this->heltall_vektor.size(); i++)
        for(unsigned long long heltall : this->heltall_vektor)
            utfil << heltall << std::endl;
    }
    else if(ff == fil_format::Bin) {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
            for(int j = 0; j < heltall_bilde::size; j++) {
                utfil << ((this->heltall_vektor[i] & ((unsigned long long)1<<j)) > 0) ? 1 : 0;
            }
            utfil << std::endl; // trengs endl?
        }
    }
    else std::cout << "Feil filformat" << std::endl;

    utfil.close();
}

void heltall_bilde::les_bilde(std::string filnavn, fil_format ff) {
    this->init(); // trengs kanskje
    std::ifstream innfil;
    innfil.open(filnavn);

    switch (ff) {
    case fil_format::Tekst:
        char c;
        int k = 0, i = 0;
        while(innfil.get(c)) {
            if(c == 'W')
               this->heltall_vektor[i] = this->heltall_vektor[i] | (1<<k);

            k++;
            if(k == heltall_bilde::size) { k = 0; i++; }
        }
        break;
    default:
        std::cout << "Feil format" << std::endl;
        break;
    }

    innfil.close();
}
