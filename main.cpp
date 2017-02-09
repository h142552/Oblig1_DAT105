#include <iostream>
#include "util_heltall.h"
#include "heltall_bilde.h"

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

// Tester metodene i util_heltall
void test_metoder() {
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
}

int main()
{
    // Oppgave 1 eksempel:
    //std::cout << "22! = " << oppgave1::fakultet(22) << std::endl;

    // Oppgave 2, Del 1 og 2:
    //test_metoder();

    // Oppgave 2, Del 3:
    heltall_bilde bmp { heltall_bilde() };
    bmp.lag_bilde('/', 64);
    bmp.lag_bilde('\\', 0);
    bmp.lag_bilde('|', 0);
    bmp.lag_bilde('|', 63);
    bmp.lag_bilde('-', 0);
    bmp.lag_bilde('-', 63);
    bmp.skriv_ut();

    // Oppgave 2, Del 4 a):
    heltall_bilde b1 { heltall_bilde() };
    std::cout << (bmp == b1) << std::endl;
    heltall_bilde b2 { heltall_bilde() };
    std::cout << (b1 == b2) << std::endl;

    // Oppgave 2, Del 4 b):
    b1.lag_bilde('/', 64);
    b2.lag_bilde('\\', 0);
    b1 = b1 + b2;
    b1.skriv_ut();

    // Oppgave 2, Del 4 c):
    b1 = ~b1;
    b1.skriv_ut();

    // Oppgave 3: // TODO: test slik som står i oppgaveteksten.
    b1.lagre_bilde("test.txt", heltall_bilde::fil_format::Tekst);
    b2.les_bilde("test.txt", heltall_bilde::fil_format::Tekst);
    b2.skriv_ut();

    // Oppgave 4, Del 1:
    heltall_bilde b3 { heltall_bilde() };
    b3.lag_sirkler(32, 15);
    b3.lag_sirkler(32, 23);
    b3.lag_sirkler(32, 31);
    b3.skriv_ut();

    return 0;
}
