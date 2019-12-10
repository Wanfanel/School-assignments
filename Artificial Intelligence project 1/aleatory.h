#ifndef ALEATORY_H

#define ALEATORY_H


#include <random> //All random generators

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
