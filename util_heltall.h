#ifndef UTIL_HELTALL_H
#define UTIL_HELTALL_H

namespace oppgave2 {
    struct out_of_range_exception {};
    struct number_is_zero_exception {};
}

class util_heltall
{
private:
    unsigned long long heltall;
public:
    util_heltall();
    void set_heltall(unsigned long long heltall);
    unsigned long long get_heltall();

    // DEL 1:
    int bit_at(unsigned int k); // a)
    int bit_count();			// b)
    int bit1_count();			// c)
    int bit1_highest();			// d)
    int mirror();				// e)
    bool symmetric(); 			// f)
    int bit1_less_than(unsigned int k); 	// g)
    int bit1_greater_than(unsigned int k); 	// h)
};

#endif // UTIL_HELTALL_H
