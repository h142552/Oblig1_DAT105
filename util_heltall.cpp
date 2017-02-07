#include "util_heltall.h"

util_heltall::util_heltall() {}
void util_heltall::set_heltall(unsigned int heltall) { this->heltall = heltall; }
unsigned int util_heltall::get_heltall() { return this->heltall; }


// a), Returnerer bitverdien i posisjon k
int util_heltall::bit_at(unsigned int k) {
    if((unsigned int) 1<<k > this->heltall) throw oppgave2::out_of_range_exception();
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

// e), Speilvender bitmønsteret til n
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
