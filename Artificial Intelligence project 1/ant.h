#ifndef ANT_H

#define ANT_H

#include <list>

#include "map.h"



class Ant

{

public:

Ant();

Ant(Map *map);

void run( Draw *draw);

virtual ~Ant();


protected:


private:

int * path = nullptr;

std::list<int> cities_to_visit;

Map * map = nullptr;

int amount_cities_to_visit;

double path_lenght;

int path_choice(int&);





};


#endif // ANT_H
