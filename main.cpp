#include <iostream>

//using namespace std;

// Oppgave 1:
namespace oppgave1 {
unsigned long long fakultet(unsigned long long int n) {
    if(n == 0) return 1;
    else return fakultet(n - 1) * n;

    /* short:
        16 bits, -32,767 -> 32,767
        høyeste n: 7 = 5,040
     * unsigned short:
        16 bits, 0 -> 65,535
        høyeste n: 8 = 40,320
     * int:
        32 bits, -2,147,483,647 -> 2,147,483,647
        høyeste n: 12 = 479,001,600
     * unsigned int:
        32 bits, 0 -> 4,294,967,295
        høyeste n: 12 = 479,001,600
     * long int:
        32 bits, -2,147,483,647 -> 2,147,483,647
        høyeste n: 12 = 479,001,600
     * long long int:
        64 bits, -9,223,372,036,854,775,807 -> 9,223,372,036,854,775,807
        høyeste n: 20 = 2,432,902,008,176,640,000
     * unsigned long long int:
        64 bits, 0 -> 18,446,744,073,709,551,615
        høyeste n: 20 = 2,432,902,008,176,640,000
     */
}
}

// Oppgave 2:
namespace oppgave2 {
struct out_of_range_exception {};
struct number_is_zero_exception {};
// a), Returnerer bitverdien i posisjon k
int bit_at(unsigned int n, unsigned int k) {
    if((unsigned int) 1<<k > n) throw oppgave2::out_of_range_exception();
    return ((n & 1<<k) > 0) ? 1 : 0;
}

// b), Returnerer antall bits
int bit_count(unsigned int n) {
    unsigned int k = 1;
    while((unsigned int) 1<<k < n) k++;

    return k;
}

// c), Returnerer antall bit satt til 1
int bit1_count(unsigned int n) {
    unsigned int k = 1;
    unsigned int count = 1;
    while((unsigned int) 1<<k < n) {
        if((n & 1<<k) > 0) count++;
        k++;
    }

    return count;
}

// d), Returnerer høyeste bit satt til 1
int bit1_highest(unsigned int n) {
    if(n == 0) throw oppgave2::number_is_zero_exception();

    unsigned int k = 1;
    unsigned int highest = 0;
    while((unsigned int) 1<<k <= n) {
        if((n & 1<<k) > 0) highest = k+1;
        k++;
    }

    return highest;
}

// e), Speilvender bitmønsteret til n
int mirror(unsigned int n) {
    // 1100101 -> 1010011, 101d -> 83d
    unsigned int mirrored = 0;
    unsigned int k = oppgave2::bit_count(n);

    while(k > 0) {
        mirrored += (n & 1<<k);
        k--;
    }

    return mirrored;
}
}



int main(int argc, char *argv[])
{
    // Oppgave 1 eksempel:
    std::cout << "22! = " << oppgave1::fakultet(22) << std::endl;

    // 2a)
    try {
        std::cout << oppgave2::bit_at(11, 3) << std::endl; // n = 1011
    } catch(oppgave2::out_of_range_exception) { std::cout << "Out of range" << std::endl; }

    // 2b)
    std::cout << oppgave2::bit_count(61) << std::endl; // n = 0011 1101, count = 6

    // 2c)
    std::cout << oppgave2::bit1_count(61) << std::endl; // n = 0011 1101, count = 5
    std::cout << oppgave2::bit1_count(64) << std::endl; // n = 0100 0000, count = 1

    // 2d)
    try {
        std::cout << oppgave2::bit1_highest(64) << std::endl; // n = 0100 0000, highest = 7
        std::cout << oppgave2::bit1_highest(0) << std::endl;
    } catch(oppgave2::number_is_zero_exception) { std::cout << "Number is zero" << std::endl; }

    // 2e)
    std::cout << oppgave2::mirror(101) << std::endl;
    return 0;
}
