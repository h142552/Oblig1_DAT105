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
             * ////////////////////////7
             * tenk '/' bildet:
             * 		xPos begynner på 63
             * 		finner bit, += '.'
             * 		beveger ned
             * 		beveger -1
             * 		repeat
             */
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

            ///////////
            //for(int j = 0; j < sizeof(unsigned long long); j++) { /* foreach bit*/ }
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
//        while(heltall.bit1_greater_than(pos) > 0) { //dobbelt
//            if(heltall.bit_at(pos) > 0) {
//                // sett denne bit-en til 0
//            }
//            pos--; // går videre mot høgre i tallet / venstre i bilde
//            count++;
//        }

    }
    else return '0'; // fant ingen, ikke beveg

    return count;
}
