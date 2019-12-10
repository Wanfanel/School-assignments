#include "aleatory.h"

Aleatory::Aleatory()
{
    //ctor
}
Aleatory::Aleatory(int boundMin, int bountMax,int seed)
    : seed_(seed),defGen_(seed_),randInt_(boundMin, bountMax)
{
/// Nothing here
}
int Aleatory::getRandInt()
{
    return randInt_(defGen_);
}

Aleatory::~Aleatory()
{
    //dtor
}

