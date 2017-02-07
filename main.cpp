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
// a)
int bitverdi_posisjon(unsigned int n, int k) { // skal returnere bitverdi at posisjon k i tallet n
    return 0;
}

// b)
int antall_bit(unsigned int n) { // returnerer antall bit i n
    return 0;
}

// c)
int antall_bit1(unsigned int n) { // returnerer antall bits som er satt til 1
    return 0;
}

// d)
int hoyeste_bit1(unsigned int n) { // returnerer høyeste bit som er satt til 1
    return 0;
}

// e)
int speilvend(unsigned int n) { // speilvender bitmønsteret til n
    return 0;
}

// f)
bool symmetrisk(unsigned int n) { // returnerer true dersom bitmønsteret er symmetrisk
    return 0;
}

// g)
int antall_bit1_mindre(unsigned int n, int k) { // returnerer antall bits satt til 1, til høyre for k
    return 0;
}

// h)
int antall_bit1_storre(unsigned int n, int k) { // returnerer antall bits satt til 1, til venstre for k
    return 0;
}
}



int main(int argc, char *argv[])
{
    // Oppgave 1 eksempel:
    std::cout << "22! = " << oppgave1::fakultet(22) << std::endl;

    return 0;
}
