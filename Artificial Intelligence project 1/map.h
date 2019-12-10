#ifndef MAP_H

#define MAP_H


#include "city.h"

#include "tab2d.h"

#include "aleatory.h"

#include "Draw.h"



class Map

{

public:


Map();

// Map(Draw * draw);

virtual ~Map();

City GetCity(int c)

{

return city[c];

}

double get_cityDistance(int &fCity, int sCity){ return city_distance[fCity][sCity];}

double get_path_visibility(int &fCity,int sCity){return path_visibility[fCity][sCity];}

int get_first_city(){return city_start;}

int get_cityAmount(){return city_count;}

double get_pheromone(int &fCity,int sCity){return pheromone.get(fCity,sCity);}

double get_delta_pheromone(int &fCity,int sCity){return delta_pheromone.get(fCity,sCity);}

double get_alfa(){return alfa;}

double get_chance();

double get_Q(){return Q;}

double get_best_lenght(){return best;}

int get_best_city(int c){return best_path[c];}

City get_city(int icity){return city[icity];}

void reset_best(){best = -1.0;}


void set_start_city(int c){city_start = c;}

void set_pheromone(int &fCity,int sCity,double var){pheromone.set_mirror( fCity, sCity, var);}

void set_delta_pheromone(int &fCity,int sCity, double var){delta_pheromone.set_mirror( fCity, sCity, var);}

void add_delta_pheromone(int fCity,int &sCity, double &var){delta_pheromone.add_mirror( fCity, sCity, var);}

bool if_best_path(double &lenght);

void save_best( int * path);


void add_city(float x, float y);

void update_pheromone_from_delta();


Draw * draw = nullptr;

protected:

private:


int city_count = 0;

int city_max = 4;

City * city;

double ** city_distance;

double ** path_visibility;

double Q = 80;

double beta = 2.8;

double alfa = 1.5;

double evaporation = 0.2;


Tab2D delta_pheromone;

Tab2D pheromone;

double best = -1;

int * best_path = nullptr;

int ants;

int city_start = 0;


Aleatory chance;


};


#endif // MAP_H


