#include <iostream>
#include "util_heltall.h"

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

int main()
{
    // Oppgave 1 eksempel:
    std::cout << "22! = " << oppgave1::fakultet(22) << std::endl;

    // Oppgave 2:
    util_heltall heltall {util_heltall()};
    // 2a)
    try {
        heltall.set_heltall(11);
        std::cout << heltall.bit_at(3) << std::endl; // n = 1011
    } catch(oppgave2::out_of_range_exception) { std::cout << "Out of range" << std::endl; }

    // 2b)
    heltall.set_heltall(61);
    std::cout << heltall.bit_count() << std::endl; // n = 0011 1101, count = 6
    heltall.set_heltall(16);
    std::cout << heltall.bit_count() << std::endl; // n = 0001 0000, count = 5

    // 2c)
    heltall.set_heltall(61);
    std::cout << heltall.bit1_count() << std::endl; // n = 0011 1101, count = 5
    heltall.set_heltall(64);
    std::cout << heltall.bit1_count() << std::endl; // n = 0100 0000, count = 1
    heltall.set_heltall(0);
    std::cout << heltall.bit1_count() << std::endl; // n = 0100 0000, count = 1

    // 2d)
    try {
        heltall.set_heltall(64);
        std::cout << heltall.bit1_highest() << std::endl; // n = 0100 0000, highest = 7
        heltall.set_heltall(0);
        std::cout << heltall.bit1_highest() << std::endl;
    } catch(oppgave2::number_is_zero_exception) { std::cout << "Number is zero" << std::endl; }

    // 2e)
    heltall.set_heltall(101);
    std::cout << heltall.mirror() << std::endl; // 1100101b -> 1010011b, 101d -> 83d
    heltall.set_heltall(16);
    std::cout << heltall.mirror() << std::endl; // 10000b -> 1b, 16d -> 1d
    heltall.set_heltall(113);
    std::cout << heltall.mirror() << std::endl; // 1110001b -> 1000111b, 113d -> 71d

    return 0;
}
