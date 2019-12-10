#include <iostream>
#include <string>
/*napisz klasse wizytówka
imie nzwsiko\ulica nr domu z mozliwosciami
drukowanie


klasa ułam,
z przeciożonymi operat dodawania i mnożenia
*/
using namespace std;

class ulamek
{
    double licznik;
    double mianownik;
public:
    ulamek();
    ulamek(double &w_licznik,double &w_mianownik);
void show();
ulamek operator+(ulamek &w);
ulamek operator*(ulamek &w);
};
class wizytowka
{
    string imie;
    string nazw;
    string ulica;
    int numer;
    int nmieszka;
public:
    wizytowka();
    wizytowka(string &w_imie,string &w_nazw,string &w_ulica,int w_numer, int w_nmieszka);
    void set_imie(string);
    void set_nazw(string);
    void set_ulica(string,int,int);
    void print();
};




int main()
{
 string imie, nazwisko, ulica;
 int dom , mieszkanie;
cerr<<"podaj imie"<< "\n";
 cin>> imie;
 cerr<<"podaj nazwisko"<< "\n";
 cin>> nazwisko;
 cerr<<"podaj nazwe ulicy"<< "\n";
 cin>> ulica;
 cerr<<"podaj nr domu"<< "\n";
 cin>> dom;
 cerr<<"podaj nr mieszkania"<< "\n";
 cin>> mieszkanie;
 wizytowka Mieszkaniec(imie,nazwisko,ulica,dom,mieszkanie);
 Mieszkaniec.print();

    cout << "Hello world!" << endl;
    return 0;
}

wizytowka::wizytowka()
{
    imie = "anonymus";
    nazw = "anonymus";
    ulica = "uknown";
    numer = 0;
    nmieszka  = 0;
}
wizytowka::wizytowka(string &w_imie,string &w_nazw,string &w_ulica,int w_numer, int w_nmieszka)
{
    imie = w_imie;
    nazw = w_nazw;
    ulica = w_ulica;
    numer = w_numer;
    nmieszka  = w_nmieszka;
}
void wizytowka::print()
{
    cout<< imie<<"\t"<<nazw<<"\n";
    cout<<ulica<<" "<<numer<<" "<<nmieszka<<"\n";
}

ulamek::ulamek()
{
    double uno = 1;
    ulamek(uno,uno);
}
ulamek::ulamek(double &w_licznik, double &w_mianownik)
{
    mianownik = w_mianownik;
    licznik = w_licznik;
}

