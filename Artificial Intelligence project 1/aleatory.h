#ifndef ALEATORY_H
#define ALEATORY_H

#include <random>       //All random generators Moreus
#include <chrono>

class Aleatory
{
public:
    Aleatory();
    Aleatory(int boundMin,
          int bountMax,
          int seed = std::chrono::steady_clock::now().time_since_epoch().count());
    int getRandInt();


    virtual ~Aleatory();

protected:

private:
    int seed_;
    std::default_random_engine defGen_;
    std::uniform_int_distribution<int> randInt_;
};

#endif // CRAND_H
