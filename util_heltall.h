#ifndef UTIL_HELTALL_H
#define UTIL_HELTALL_H

namespace oppgave2 {
    struct out_of_range_exception {};
    struct number_is_zero_exception {};
}

class util_heltall
{
private:
    unsigned int heltall;
public:
    util_heltall();
    void set_heltall(unsigned int heltall);
    unsigned int get_heltall();

    // DEL 1:
    int bit_at(unsigned int k); // a)
    int bit_count();			// b)
    int bit1_count();			// c)
    int bit1_highest();			// d)
    int mirror();				// e)
};

#endif // UTIL_HELTALL_H
