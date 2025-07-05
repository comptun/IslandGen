#include "LuauRandom.h"

uint32_t LuauRandom::pcg32_random() {
    uint64_t oldstate = m_State;
    m_State = oldstate * 6364136223846793005ULL + (PCG32_INC | 1);
    uint32_t xorshifted = uint32_t(((oldstate >> 18u) ^ oldstate) >> 27u);
    uint32_t rot = uint32_t(oldstate >> 59u);
    return (xorshifted >> rot) | (xorshifted << ((-int32_t(rot)) & 31));
}
void LuauRandom::pcg32_seed(uint64_t seed) {
    m_State = 0;
    pcg32_random();
    m_State += seed;
    pcg32_random();
}

double LuauRandom::NextNumber() {
    uint32_t rl = pcg32_random();
    uint32_t rh = pcg32_random();
    double rd = ldexp(double(rl | (uint64_t(rh) << 32)), -64);
    return rd;
}

double LuauRandom::NextNumber(double l, double u) {
    return l + NextNumber() * (u - l);
}

int LuauRandom::NextInteger(int l, int u) {
    uint32_t ul = uint32_t(u) - uint32_t(l);
    uint64_t x = uint64_t(ul + 1) * pcg32_random();
    int r = int(l + (x >> 32));
    return r;
}

LuauRandom::LuauRandom(uint64_t seed) {
    pcg32_seed(seed);
}