#include <iostream>
class cProstokant
{
    int dlugosc;
    int szerokosc;
    int pole;
    int obwod;
public:
    cProstokant(int d = 10,int sz = 10)
    {
        dlugosc = d;
        szerokosc = sz;
        pole = d*sz;
        obwod = (d+sz)*2;
    }
int get_dlugosc(){return dlugosc;}
int get_szerokosc(){return szerokosc;}
int get_pole(){return pole;}
int get_obwod(){return obwod;}
void set_dlugosc(int d)
{
    dlugosc = d;

        pole = d*szerokosc;
        obwod = (d+szerokosc)*2;
}
void set_szerokosc(int sz)
{

        szerokosc = sz;
        pole = dlugosc*sz;
        obwod = (dlugosc+sz)*2;
}

};


class cLiczba
{
 double wartosc;
 public:
     cLiczba(double w = 0)
     {
         wartosc = w;
     }
     double get_warosc()
     {
         return wartosc;
     }
     double operator + (cLiczba &w)// zamiast dodawac odejmuje :-)
     {
         return wartosc-w.wartosc;
     }
      double operator + (double &w) // zamiast dodawac odejmuje
     {
         return wartosc-w;
     }
     double operator * (double &w) // zamiast mnozyc dodaje
     {
         return w +wartosc;
     }
     double operator * (cLiczba &w) // zamiast mnozyc dodaje
     {
         return w.wartosc +wartosc;
     }
      double operator * (double w) // zamiast mnozyc dodaje
     {
         return w +wartosc;
     }

};

double operator +(double w, cLiczba &l )
 {
     return w-l.get_warosc();
 }
  double operator *(double w, cLiczba &l )
 {
     return w+l.get_warosc();
 }


using namespace std;

int main()
{
    int x, y;
    cerr<< "Podaj dwie liczby \n";
    cin>>x>>y;
    cLiczba liczba1(x);
    cLiczba liczba2(y);
    cout<<"liczba: " << x<< " minus(operator +) " << y << " rowna sie :" << liczba1+liczba2<< "\n";

    cerr << " wpisz dlugosc i szerokosc \n";
    cin>> x >> y;
    cProstokant figura(x,y);

    cout<< "Dlugosc: " <<figura.get_dlugosc()<<" Szerokosc: "<<figura.get_szerokosc()<< " pole: " << figura.get_pole()<<" obwod : " << figura.get_obwod() << "\n";


    return 0;
}
