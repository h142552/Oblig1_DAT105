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

    // posisjonen til skrivehodet er (j, i)
    for(unsigned int i = 0; i < heltall_vektor.size(); i++) { // foreach tall

        if(heltall_vektor[i] == 0) {
            temp += "V"; // og antall linjer
        }
        else {
            for(int j = 0; j < sizeof(unsigned long long); j++) { // foreach bit



            }
        } // else

        if(temp == forrige) { // denne kommandoen er lik den forrige.
            gjentatte++;
        }
        else if(forrige != ""){ // skriver temp, med mindre forrige=""(first case)
            this->utskrift_kommando_streng += "(";
            this->utskrift_kommando_streng += temp;
            this->utskrift_kommando_streng += ")";
            this->utskrift_kommando_streng += gjentatte;
            // resetter gjentatte
            gjentatte = 1;
        }
        else { ; }
        forrige = temp;
        temp = ""; // nulstiller


    } // for
}
