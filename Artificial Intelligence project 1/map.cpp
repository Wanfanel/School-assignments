#include "map.h"

#include "Draw.h"

#include <math.h>


Map::Map()

{

city = new City[city_max];


city_distance = new double*[city_max];

path_visibility = new double*[city_max];

best_path = new int[city_max];

chance = Aleatory(0,9999);

}



void Map::update_pheromone_from_delta()

{

pheromone.all_multiply_by(evaporation);

pheromone.add_all(delta_pheromone);

delta_pheromone.set_all(0);

}


void Map::add_city(float x, float y)

{

best = -1.0;

pheromone.add();

delta_pheromone.add();

if(city_count == city_max)

{

city_max *=2;

City * temp = new City[city_max];

double ** temp_distance = new double * [city_max];

double ** temp_path_visibility = new double * [city_max];

delete []best_path;

best_path = new int[city_max];





for(int i=0; i<city_count; i++)

{

temp[i]=city[i];

temp_distance[i] = new double[city_max];

temp_path_visibility[i] = new double[city_max];

for (int j = 0; j<city_count; j++)

{

temp_distance[i][j]= city_distance[i][j];

temp_path_visibility[i][j] = path_visibility[i][j];

}

}


for(int i = 0; i<city_max/2; i++)

{

delete [] city_distance[i];

delete [] path_visibility[i];

}

delete [] city_distance;

delete [] path_visibility;


city_distance = temp_distance;

path_visibility = temp_path_visibility;


delete [] city;

city = temp;

}

city[city_count] = City(x,y);

city_distance[city_count] = new double[city_max];

path_visibility[city_count]= new double[city_max];


for(int i = 0; i<city_count; i++)

{

pheromone.set_mirror(city_count,i,1);

delta_pheromone.set_mirror(city_count,i,0);

city_distance[i][city_count] = city_distance[city_count][i] = city[i].Distance_Calc(city[city_count]);

if(city_distance[i][city_count]) /// !0

{

path_visibility[i][city_count] = path_visibility[city_count][i] = pow((1/city_distance[city_count][i]),beta);

}

}

city_count++;


}


double Map::get_chance()

{

return (double)chance.getRandInt()/10000;

}


bool Map::if_best_path(double &lenght)

{

if(best == -1.0)

{

best = lenght;

return 1;

}

else if(best>lenght)

{

best = lenght;

return 1;

}

return 0;

}


void Map::save_best(int* path)

{

for(int i = 0; i<city_count-1; i++)

{

best_path[i]=path[i];

}


}


Map::~Map()

{

delete [] city;

for(int i = 0; i< city_count; i++)

{


delete [] path_visibility[i];

delete [] city_distance[i];

}

delete [] path_visibility;

delete [] city_distance;


}


