#include "matrise_skriver.h"

matrise_skriver::matrise_skriver(std::vector<unsigned long long> heltall_vektor)
{
    int sz = sizeof(unsigned long long);
    this->matrise_simulering = std::vector<std::vector<char>>(sz, std::vector<char>(sz)); // er dette rett?

    // temp under
    this->lag_kommando_streng(heltall_vektor);
}

std::string matrise_skriver::get_kommando_streng() { return this->utskrift_kommando_streng; }

void matrise_skriver::lag_kommando_streng(std::vector<unsigned long long> heltall_vektor) {
    this->utskrift_kommando_streng = "";
    std::string forrige = "";
    std::string temp = ""; // temp-streng
    int gjentatte = 1; // teller gjentakelser av kommandoer

    util_heltall heltall = { util_heltall() };
    int xPos = 63; // 0 = minst signifikante bit, 63 = helt til høgre // (?)
    std::string forrige_linje = "";
    std::string temp_linje = "";
    int teller_linje = 0;

    // posisjonen til skrivehodet er (j, i)
    for(unsigned int i = 0; i < heltall_vektor.size(); i++) { // foreach tall
        heltall.set_heltall(heltall_vektor[i]); // Setter heltallet hver gang vi henter en "linje"

        if(heltall_vektor[i] == 0) { // dersom linjen er tom, går vi ned
            temp += "V";
        }
        else {
            teller_linje = 0; // nullstiller før linjen starter
            temp_linje = "";
            char c;
            while(heltall.get_heltall() > 0) {
                c = finn_neste(heltall, xPos); // får en char som bestemmer bevegelse
                switch (c) {
                case '0': // ikke beveg

                    break;
                case '<': // beveg venstre
                    xPos--;
                    teller_linje--;
                    break;
                case '>': // beveg høgre
                    xPos++;
                    teller_linje++;
                    break;
                case '.': // skriv
                    (teller_linje != 0)
                            ? temp_linje += std::to_string(teller_linje) + "."
                            : temp_linje += ".";

                    break;
                default:

                    break;
                }
            }
            // skriv linjeskift til slutt
            temp_linje += "V";

        } // else
        temp = temp_linje;

        if(temp == forrige) { // denne kommandoen er lik den forrige.
            gjentatte++;
        }
        else if(forrige != ""){ // skriver temp, med mindre forrige=""(first case)
            // sjekk om det er nødvendig å skrive ()
                // med len(temp) > 1 -> skriv ()
            this->utskrift_kommando_streng += "(";
            this->utskrift_kommando_streng += temp;
            this->utskrift_kommando_streng += ")";
            this->utskrift_kommando_streng += gjentatte;
            // resetter gjentatte
            gjentatte = 1;
        } else { ; } // ender alltid opp her første gang

        forrige = temp;
        temp = ""; // nulstiller

    } // for
}

// trenger kanskje referanse til heltall
char matrise_skriver::finn_neste(util_heltall &heltall, int pos) { // returnerer neste plass skrivehodet skal gå til
    int count = 0;

    if(heltall.bit1_greater_than(pos) > 0) { // dersom det finnes tall til
        //while(heltall.bit1_greater_than(pos) > 0) { //dobbelt
        if(heltall.bit_at(pos) > 0) {
            // sett denne bit-en til 0// + ret?
            heltall.set_heltall(heltall.get_heltall() & (unsigned long long)0<<pos); // denne skal sett til 0
            return '.';
        }
        else {
            return '>'; // Beveg mot høgre (mest signifikant bit) ('>')
        }
        //pos++; // går videre mot venstre i tallet / høgre i bilde
        //count--;
        //}
    }
    else if(heltall.bit1_less_than(pos) > 0) { // denne blir lik som if-en over, men motsatt retn
        if(heltall.bit_at(pos) > 0) {
            heltall.set_heltall(heltall.get_heltall() & (unsigned long long)0<<pos); // denne skal sett til 0
            return '.';
        }
        else {
            return '<'; // beveg mot venstre (mot minst signifikant bit) ('<')
        }
    }
    else return '0'; // fant ingen, ikke beveg

    return count;
}
