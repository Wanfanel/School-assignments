#include "city.h"

#include <math.h>


City::City(float x,float y)

{

this->x = x;

this->y = y;

}


City::~City()

{

//dtor

}


double City::Distance_Calc(City s)

{

return sqrt(pow(this->get_x()-s.get_x(),2) + pow(this->get_y()-s.get_y(),2));

}


