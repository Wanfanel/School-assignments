#include <iostream>
#include "algorytm.h"
#include "aleatory.h"


int main()
{
    Algorytm algorytm;
    double best_score;
    int best_count ;
    bool running = true;
    int chosen;
    while(running)
    {

        std::cout<< "1.Ustaw(a),(b), \n2.Uruchom, \n3.Wyjdz.\n";
                 std::cin>> chosen;
        switch(chosen)
        {
        case 1:
            std::cout<< "1>wprowadz a b dla:\n a*sqrt(x)*b*log10(x) + cos(M_PI*pow(x,2)/180.0f)\n>";
             std::cin>> chosen;
             algorytm.set_a(chosen);
               std::cin>> chosen;
             algorytm.set_b(chosen);
             std::cout<< "FUNKCJA: "<<algorytm.get_a()<<"*sqrt(x)*"<<algorytm.get_b()<<"*log10(x) + cos(M_PI*pow(x,2)/180.0f)\n\n";
            break;
        case 2:
best_count = 0;
best_score = std::numeric_limits<double>::min();


            for(int i = 0; i<1000; i++)
            {
                std::cout<< "ITERACJA:\t"<< i <<std::endl<<std::endl;
                algorytm.Selection();
                algorytm.Crossover();
                algorytm.Mutation();
                algorytm.Print();

                if(best_score == algorytm.getBest_score())
                {
                    best_count++;
                    if(best_count>16)
                    {
                        i = 1000;
                    }
                }
                else
                {
                    best_score = algorytm.getBest_score();
                    best_count = 0;
                }



            }
            break;
        case 3:
            running = 0;
            break;
        }
    }

    return 0;
}
