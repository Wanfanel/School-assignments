#ifndef ALGORYTM_H
#define ALGORYTM_H

#define M_PI       3.14159265358979323846

#include "aleatory.h"
#include <bitset>
#include <math.h>
#include <limits>

#include <iostream>

class Algorytm
{
std::bitset<7> * osobnik;
 Aleatory * d128 = new Aleatory(0,127);
 Aleatory * d126 = new Aleatory(1,126);
 Aleatory * d100 = new Aleatory(0,99);
 Aleatory * d7   = new Aleatory(0,6);
int pk = 80, pm = 20;
int a = 1, b =1;
double highest_negative_value = 0;
double best_score = std::numeric_limits<double>::min();
std::bitset<7> najlepszy_osobnik;


    public:
        Algorytm();
        ~Algorytm();

        void set_a( int a){this->a = a;}
        void set_b( int b){this->b = b;}
        int get_a(){return a;}
        int get_b(){return b;}
        double getBest_score(){return best_score;}
        double funkcja(std::bitset<7> &wejscie);
        void Selection();
        void Crossover();
        void Mutation();
        void Print();

    protected:


};

#endif // ALGORYTM_H
