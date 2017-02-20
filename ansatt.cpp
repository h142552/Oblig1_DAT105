#include "ansatt.h"

Ansatt::Ansatt(std::string navn, unsigned int pnr)
    : Person(navn, pnr) { }

Ansatt::Ansatt(Person &&p)
    : Person(std::move(p)) { }

bool Ansatt::legg_til_ansatt(Ansatt *ansatt) {
    if(ansatte.size() <	10) {
        /// bruke en nivå-teller?
        /// eller if(this.mentor.mentor.mentor.mentor != nullptr)
        /// 	må såfall legge til ansatte, ikke personer,
        /// 	personer har ikke mentor
        // sjekk 4-nivå opp + legg til
        //if(ansatt->har_mentor()) { // rett count?
            //if(ansatt->get_mentor()->har_mentor())
                //if(ansatt->get_mentor()->get_mentor()->har_mentor())
                    //if(ansatt->get_mentor()->get_mentor()->get_mentor()->har_mentor())

        ansatt->tilknytt_mentor(*this);
        ansatte.push_back(ansatt);
        return true;
        //}
        //else return false;
    }
    else return false;
}

bool Ansatt::har_mentor() { // Sjekker om en ansatt har en mentor
    if(this->mentor == nullptr) return false;
    else return true;
}

void Ansatt::tilknytt_mentor(Ansatt& mentor) {
    if(!super_mentor) {
        this->mentor = std::make_unique<Ansatt>(std::move(mentor));
        this->mentor_nivå++;//helevveretettetet
    }
}

void Ansatt::set_super_mentor(bool super_mentor) {
    this->super_mentor = super_mentor;
}

std::string Ansatt::to_string() {
    return (
        Person::to_string() +
        "Antall ansatte:\t" + std::to_string(this->ansatte.size()) + "\n" +
        "Er super-mentor:" + std::to_string(this->super_mentor) + "\n" +
        "Mentor:\t\t" + (har_mentor()
            ? (this->mentor->get_navn()) : ("NULL")) + "\n"
    );
}

std::string Ansatt::list_ansatte() {
    std::string ansatte_string = "";
    for(auto a : ansatte) {
        ansatte_string += a->to_string();
    }
    return ansatte_string;
}
