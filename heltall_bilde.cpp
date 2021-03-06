#include "heltall_bilde.h"

int heltall_bilde::size = sizeof(unsigned long long) * 8;

std::vector<unsigned long long> heltall_bilde::get_heltall_vektor() { return this->heltall_vektor; }

// Reserverer nok plasser, og initialiserer alle tall i vektor
heltall_bilde::heltall_bilde() {
    this->heltall_vektor.reserve(this->size);
    this->init();
}

// Setter alle tallene i vektor til 0
void heltall_bilde::init() {
    if(this->heltall_vektor.size() == 0)
        for(int i = 0; i < heltall_bilde::size; i++)
            this->heltall_vektor.push_back(0);
    else
        for(int i = 0; i < heltall_bilde::size; i++)
            this->heltall_vektor[i] = 0;
}

// Skriver ut alle tallene i vektoren, W for 1 og _ for 0
void heltall_bilde::skriv_ut() {
    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++) {
        for(int j = 0; j < this->size; j++)
            ((this->heltall_vektor[i] & (unsigned long long)1<<j) > 0)
                ? (std::cout << 'W') : (std::cout << '_');

        std::cout << std::endl;
    }
}

// Sjekker om alle elementene i vektoren er like
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

// Legger sammen to bilder
heltall_bilde& heltall_bilde::operator+(const heltall_bilde& rhs) {
    if(this->heltall_vektor.size() != rhs.heltall_vektor.size())
        throw heltall_bilde::size_mismatch_exception();

    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
        this->heltall_vektor[i] |= rhs.heltall_vektor[i];

    return *this;
}

// Bytter 0 til 1 og 1 til 0 for alle bits for tallene i vektoren
heltall_bilde& heltall_bilde::operator~() {
    for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
        this->heltall_vektor[i] = ~this->heltall_vektor[i];

    return *this;
}

// Genererer bilde basert på char-parameter
void heltall_bilde::lag_bilde(char B, int k = 0) {
    switch (B) {
    case '0': {
        this->init();

        break;
    }
    case '1': {
        this->heltall_vektor[0] = 1;

        break;
    }
    case '\\': {
        int i = 0;
        while(k < this->size) {
            // setter k-te bit i element nr. i til 1
            this->heltall_vektor[i] |= (unsigned long long)1<<k;

            ++i;
            ++k;
        }

        break;
    }
    case '/': {
        int i = 0;
        while(k > 0) {
            this->heltall_vektor[i] |= (unsigned long long)1<<(k-1);

            ++i;
            --k;
        }

        break;
    }
    case '|': {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            this->heltall_vektor[i] |= (unsigned long long)1<<k;

        break;
    }
    case '-': {
        for(unsigned int i = 0; i < this->heltall_vektor.size(); i++)
            this->heltall_vektor[k] |= (unsigned long long)1<<i;

        break;
    }
    default: {
        std::cout << "Ukjent parameter" << std::endl;

        break;
    }
    } // switch
}

// Lagrer bilde til fil
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

// Leser bilde fra fil
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
                    this->heltall_vektor[i] |= (unsigned long long)1<<j;
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
                    this->heltall_vektor[i] |= (unsigned long long)1<<j;

        break;
    }
    default: { // umulig å komme til denne casen?
        std::cout << "Feil format" << std::endl;
        break;
    }
    } // switch

    innfil.close();
}

// Bruker Midpoint circle algorithm
// Kilde: https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
void heltall_bilde::lag_sirkler(int origo, int radius) {
    // Må sjekke om sirkelen holder seg innen grensene:
    if(origo + radius > (heltall_bilde::size - 1) || origo - radius < 0)
        throw heltall_bilde::size_mismatch_exception();


    // Kunne laget en egen versjon av metoden som tar inn x0 og y0
    int x0 = origo, y0 = origo; // Antar at origo = 32 -> pos (32, 32)
    int x = radius, y = 0, err = 0;

    while(x >= y) {
        // (x0 + x, y0 + y)
        // (x0 + y, y0 + x)
        // (x0 - y, y0 + x)
        // (x0 - x, y0 + y)
        // (x0 - x, y0 - y)
        // (x0 - y, y0 - x)
        // (x0 + y, y0 - x)
        // (x0 + x, y0 - y)
        this->heltall_vektor[(y0 + y)] |= (unsigned long long)1<<(x0 + x);
        this->heltall_vektor[(y0 + x)] |= (unsigned long long)1<<(x0 + y);
        this->heltall_vektor[(y0 + x)] |= (unsigned long long)1<<(x0 - y);
        this->heltall_vektor[(y0 + y)] |= (unsigned long long)1<<(x0 - x);
        this->heltall_vektor[(y0 - y)] |= (unsigned long long)1<<(x0 - x);
        this->heltall_vektor[(y0 - x)] |= (unsigned long long)1<<(x0 - y);
        this->heltall_vektor[(y0 - x)] |= (unsigned long long)1<<(x0 + y);
        this->heltall_vektor[(y0 - y)] |= (unsigned long long)1<<(x0 + x);

        if(err <= 0) {
            y++;
            err += 2*y + 1;
        }
        if(err > 0) {
            x--;
            err -= 2*x + 1;
        }
    }
}
