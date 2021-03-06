#include <iostream>
#include "util_heltall.h"
#include "heltall_bilde.h"
#include "matrise_skriver.h"
#include "person.h"
#include "ansatt.h"
#include "ansattdata.h"

// Oppgave 1
unsigned long long fakultet(unsigned long long int n);

// Oppgave 2
void test_oppgave2();

// Oppgave 2 (Del 3 & 4), 3 og 4 (Del 1)
void test_bilder();

// Oppgave 5
void test_oppgave5();

int main()
{
    // Oppgave 1 eksempel:
    std::cout << "22! = " << fakultet(22) << std::endl;

    // Oppgave 2, Del 1 og 2:
    test_oppgave2();

    // Oppgave 2, 3 & 4
    test_bilder();

    // Oppgave 4, Del 2:
    /// Matriseskriver osv:
    /* Matriseskriver:
     * 	 brukte mye tid på denne oppgaven, men satt meg fast.
     * 	 skulle gjerne ha gjort den ferdig, men med tanke på arbeidsmengden
     * 	 i denne obligen måtte jeg gi opp. Slik klassen er nå så setter
     * 	 den seg fast når den leter etter bits for å generere kommandostreng.
     * 	 jeg prøvde å bruke klassene som ble lagt i util_heltall.
     *
     */
    //matrise_skriver ms(b1.get_heltall_vektor());
    //std::cout << "Kommandostreng: " << ms.get_kommando_streng() << std::endl;


    // Oppgave 5
    test_oppgave5();

    return 0;
}

// Oppgave 1:
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

// Oppgave 2
// Tester metodene i util_heltall
void test_oppgave2() {
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

    // 2f)
    std::cout << heltall.get_heltall() << " symmetrisk? "
              << heltall.symmetric() << std::endl;
    heltall.set_heltall(3); // symmetrisk tall
    std::cout << heltall.get_heltall() << " symmetrisk? "
              << heltall.symmetric() << std::endl;

    // 2g)
    heltall.set_heltall(113);
    std::cout << heltall.bit1_less_than(3) << std::endl;

    // 2h)
    std::cout << heltall.bit1_greater_than(3) << std::endl;
}

// Oppgave 2, 3 & 4
void test_bilder() {
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

    // Oppgave 3:
    b2.lagre_bilde("test.txt", heltall_bilde::fil_format::Tall);
    b1.les_bilde("test.txt", heltall_bilde::fil_format::Tall);
    b1.skriv_ut();

    // Oppgave 4, Del 1:
    heltall_bilde b3 { heltall_bilde() };
    b3.lag_sirkler(32, 15);
    b3.lag_sirkler(32, 23);
    b3.lag_sirkler(32, 31);
    b3.skriv_ut();
}

// Oppgave 5
void test_oppgave5() {
    /// Viser tilknyttning
    Person p1("Ola Nordmann", 170565);
    Person p2("Kari Nordmann", 230971);
    std::cout << p1.to_string() << std::endl;
    p1.tilknytt(p2);
    std::cout << p1.to_string() << std::endl;

    /// Oppretter ansatte
    std::vector<Ansatt*> ansatte {
                new Ansatt("Jan Johansen", 171178),
                new Ansatt("Peder Aas", 40389),
                new Ansatt("Kari Holm", 110145),
                new Ansatt("Hans Tastad", 121053),
                new Ansatt("Marte Kirkerud", 230490),
                new Ansatt("John Doe", 140759),
                new Ansatt("Jane Doe", 241282),
                new Ansatt("Bob Richards", 110557),
                new Ansatt("Rick Ronald", 20671),
                new Ansatt("Donald Dump", 190862),
                new Ansatt("Henry Brown", 221043)
    };

    /// Person p1 er en ansatt
    Ansatt a1(std::move(p1));
    a1.tilknytt_mentor(*ansatte[1]);
    std::cout << a1.to_string() << std::endl;
    a1.set_super_mentor(true); // dersom en ansatt settes til super_mentor, fjernes gamle mentorer
    a1.tilknytt_mentor(*ansatte[1]);

    /// Prøver å legge til for mange ansatte
    bool for_mange = false;
    for(int i = 0; i < 12 && !for_mange; i++)
        if(!a1.legg_til_ansatt(ansatte[i]))
              for_mange = true;

    std::cout << a1.to_string() << std::endl;
    std::cout << a1.list_ansatte() << std::endl;

    /// Tester AnsattData-klassen
    AnsattData ad1 = std::move(a1);
    ad1.set_banknummer(11324762);
    ad1.set_lonn(30000);
    ad1.set_stillingstype('d');
    ad1.set_paarorende(new Person("Svein Nordmann", 311278));
    ad1.set_paarorende(new Person("Marit Nordmann", 40592));
    std::cout << ad1.to_string() << std::endl;
}
