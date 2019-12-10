#ifndef CITY_H

#define CITY_H



class City

{

public:

City(float x = -1.0, float y = -1.0);

virtual ~City();


float get_x(){return x;}

float get_y(){return y;}


double Distance_Calc(City s);




protected:


private:

float x;

float y;

};


#endif // CITY_H
