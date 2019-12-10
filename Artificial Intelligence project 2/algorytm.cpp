#include "algorytm.h"


Algorytm::Algorytm()
{
    osobnik = new std::bitset<7>[16];
    ///cout<< "Osobniki startowe" << endl;

    for(int i= 0; i<16; i++)
    {
        osobnik[i]= d128->getRandInt();
       /// std::cout <<"ch "<< i << "\t: "<< osobnik[i] <<endl;
    }
}

void Algorytm::Selection()
{
  std::bitset<7> *  buffer = new std::bitset<7>[16];
double random_event[16];
double omega = 0;
double chance;
double score;
bool searhing;
int j;
  for(int i = 0 ; i < 16; i++)
  {
      score = funkcja(osobnik[i]);
      if(score>best_score){
        best_score=score;
        najlepszy_osobnik = osobnik[i];
        }
     random_event[i] = score + highest_negative_value;
    if(random_event[i]<0)
    {
        highest_negative_value -= random_event[i];
        omega = 0;
        i=-1;
    }
    else{
        omega+= random_event[i];
    }


  }
  random_event[0] /= omega;
 for(int i = 1 ; i < 16; i++){
    random_event[i] /= omega;
    random_event[i]+=random_event[i-1];
 }
  for(int i = 0 ; i < 16; i++){
    // TODO LOSS
    searhing = 1;
    j = 0;
    chance = (double)d100->getRandInt()/100;
    while(searhing) {
        if(chance<random_event[j])
        {
        ///DEBUG    cout<< "szansa:"<< chance << " osobnik:" << j << " A/Omega:"<<random_event[j]<<endl;
            buffer[i] = osobnik[j];
            searhing = 0;
        }
        j++;

    }

  }

  delete [] osobnik;
  osobnik = buffer;


}


void Algorytm::Crossover()
{
    for(int i= 0; i<16; i+=2)
    {
          if(pk > d100->getRandInt())
          {
              std::bitset<7> slice = d126->getRandInt();
              std::cout<< "Osobnik "<< i << " : "<< osobnik[i]<< " i osobnik " << i+1 << " : " << osobnik[i+1] << "\nkrzyzuja sie w miejscach : " << slice<< std::endl;


                  for(int j = 0;j<7;j++)
                  {
                      if(slice[j]&&osobnik[i][j]!=osobnik[i+1][j])
                      {
                          osobnik[i][j].flip();
                          osobnik[i+1][j].flip();
                      }
                  }
            std::cout<< "child "<< i << " to: " <<osobnik[i] << " child "<< i+1 << " to: " <<osobnik[i+1] << std::endl << std::endl;

          }
    }
}

void Algorytm::Mutation()
{
    for(int i= 0; i<16; i++)
    {
        if(pm > d100->getRandInt())
        {
            std::cout << "OSOBNIK " << i << " MUTUJE! z " << osobnik[i] << " na ";
            osobnik[i][d7->getRandInt()].flip();
            std::cout <<  osobnik[i] << std::endl;
        }
    }
}

void Algorytm::Print()
{
    std::cout<<"Osobniki: \n";
    for(int i= 0; i<16; i++)
    {
        std::cout <<"ch "<< i << "\t: "<< osobnik[i] <<std::endl;
    }
    std::cout <<"\nBEST SCORE:\t"<<best_score<< " Best gen:\t"<< najlepszy_osobnik<<"("<< najlepszy_osobnik.to_ulong() <<")" <<std::endl<<std::endl;
}

Algorytm::~Algorytm()
{
    delete d128;
    delete d100;
    delete d126;
    delete d7;
    delete [] osobnik;

}

double Algorytm::funkcja(std::bitset<7> &wejscie){

unsigned long x = wejscie.to_ulong();
if(!x)
{
    wejscie[d7->getRandInt()].flip();
    x = wejscie.to_ulong();
}
return a*std::sqrt(x)*b*log10(x) + std::cos(M_PI*std::pow(x,2)/180.0f);
}
