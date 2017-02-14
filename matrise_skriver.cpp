#include "matrise_skriver.h"

matrise_skriver::matrise_skriver()
{
    int sz = sizeof(unsigned long long);
    this->matrise_simulering = std::vector<std::vector<char>>(sz, std::vector<char>(sz)); // er dette rett?
}

void matrise_skriver::lag_kommando_streng(std::vector<unsigned long long> heltall_vektor) {
    /*
     * leser heltall_vektor.
     * dersom heltall_vektor[i] == 0 -> 1V (beveg ark opp)
     * dersom punkt under skrivehodet == 1 -> '.'
     * 	ellers -> ' ' // (eller ingenting?)
     *
     * dersom feks 10 nuller på rad -> 10 (mv 10)
     * 	har en egen var som teller moves
     *
     * dersom kommando er lik forrige -> ([kommando])2
     * 		antall gjentakelser lagres i var
     *
     * når skrivehodet kommer til enden av linjen -> 1V
     *
     * skrivehodet starter oppe i høgre hjørne
     * => implementere slik at første linjen skrives/genereres speilvendt
     * 		osv. annenhver nedover
     *
     * ---------------------------------
     * nullstiller utskrift_kommando_streng
     * temp: streng som holder kommandoen inni løkken
     * forrige: forrige kommando
     * gjentatte: antall like kommandoer
     *
     * ----------------------------------
     * ALG:
     * 	gå igjennom alle tallene
     * 	dersom tall = 0 -> bare sett temp V
     *
     */
    this->utskrift_kommando_streng = "";
    std::string forrige = "";
    std::string temp = ""; // temp-streng
    int gjentatte = 1; // teller gjentakelser av kommandoer

    util_heltall heltall = { util_heltall() };
    int xPos = 63; // 0 = minst signifikante bit, 63 = helt til høgre // (?)

    // posisjonen til skrivehodet er (j, i)
    for(unsigned int i = 0; i < heltall_vektor.size(); i++) { // foreach tall
        heltall.set_heltall(heltall_vektor[i]); // Setter heltallet hver gang vi henter en "linje"

        if(heltall_vektor[i] == 0) { // dersom linjen er tom, går vi ned
            temp += "V"; // og antall linjer
        }
        else {
            /*
             * '/' gir (.-1V1)64 +64 (synkende pow2), dvs at helt til høgre er 2^63
             * må finne ut hvor mangen som er til høgre/venstre
             * finne kortest vei?
             * bruke private metoder
             *
             * ///
             * while linje > 0
             * 	finn_nærmeste/neste
             * 	sett plassen lik 0 (oppdaterer heltall)
             * 	skriv i temp-string
             *
             */





            ///////////
            for(int j = 0; j < sizeof(unsigned long long); j++) { /* foreach bit*/ }
        } // else

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
int matrise_skriver::finn_neste(util_heltall heltall, int pos) { // returnerer neste plass skrivehodet skal gå til
    int count = 0;

    if(heltall.bit1_greater_than(pos) > 0) { // dersom det finnes tall til venstre
        while(heltall.bit1_greater_than(pos) > 0) { //dobbelt
            if(heltall.bit_at(pos) > 0) {
                // sett denne bit-en til 0
            }
            pos++; // går videre mot venstre i tallet / høgre i bilde
            count--;
        }
    }
    else if(heltall.bit1_greater_than(pos) > 0) {
        while(heltall.bit1_greater_than(pos) > 0) { //dobbelt
            if(heltall.bit_at(pos) > 0) {
                // sett denne bit-en til 0
            }
            pos--; // går videre mot høgre i tallet / venstre i bilde
            count++;
        }

    }
    else return 0; // fant ingen, ikke beveg

    return count;
}
