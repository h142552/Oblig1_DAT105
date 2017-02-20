#include "util_heltall.h"

util_heltall::util_heltall() { }
void util_heltall::set_heltall(unsigned long long heltall) { this->heltall = heltall; }
unsigned long long util_heltall::get_heltall() { return this->heltall; }


// a), Returnerer bitverdien i posisjon k
int util_heltall::bit_at(unsigned int k) {
    if((unsigned long long) 1<<k > this->heltall) throw oppgave2::out_of_range_exception();
    return ((this->heltall & 1<<k) > 0) ? 1 : 0; // return 1 if pos k == 1, return 0 if pos k == 0
}

// b), Returnerer antall bits
int util_heltall::bit_count() {
    unsigned int k = 1;
    while((unsigned int) 1<<k <= this->heltall) k++; // while pos k < n

    return k;
}

// c), Returnerer antall bit satt til 1
int util_heltall::bit1_count() {
    unsigned int k = 1;
    unsigned int count = 0;
    while((unsigned int) 1<<k <= this->heltall) { // while pos k < n
        if((this->heltall & 1<<k) > 0) count++;   // if pos k > 0
        k++;
    }

    return count;
}

// d), Returnerer høyeste bit satt til 1
int util_heltall::bit1_highest() {
    if(this->heltall == 0) throw oppgave2::number_is_zero_exception();

    unsigned int k = 1;
    unsigned int highest = 0;
    while((unsigned int) 1<<k <= this->heltall) {
        if((this->heltall & 1<<k) > 0) highest = k+1;
        k++;
    }

    return highest;
}

// e), Speilvender bitmønsteret til heltall
int util_heltall::mirror() {
    unsigned int mirrored = 0;
    unsigned int k = util_heltall::bit_count();
    unsigned int i = 0;

    while(k > 0) {
        if((this->heltall & 1<<(k-1)) > 0)
            mirrored = mirrored | 1<<i; // if plass k>0, ++plass i
        ++i;
        --k;
    }

    return mirrored;
}

// f), Sjekker om heltall er symmetrisk
bool util_heltall::symmetric() { // 101101 -> true, 110010 -> false
    return (this->heltall == this->mirror());
}

// g), Finner antall bit satt til 1 mindre enn (eller lik) k
int util_heltall::bit1_less_than(unsigned int k) { // k = 3, 0100 1110 0101 -> 2
    int count = 0;
    while(k+1 > 0) {
        if((this->heltall & ((unsigned long long)1<<k)) > 0)
            count++;
        k--;
    }

    return count;
}

// h), Finner antall bit satt til 1 større enn k
int util_heltall::bit1_greater_than(unsigned int k) { // k = 3, 0100 1110 0101 -> 4
    unsigned long long shift = 1;
    int count = 0;
    while(((unsigned long long)1<<k) < this->heltall) {
        if((this->heltall & ((unsigned long long)1<<k)) > 0)
            count++;
        k++;
    }

    return count;
}
