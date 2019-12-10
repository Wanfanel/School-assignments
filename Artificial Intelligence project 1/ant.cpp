#include "ant.h"

#include <math.h>

#include "Draw.h"

Ant::Ant()

{


}


int Ant::path_choice(int &current_city)

{

double *probability =new double[amount_cities_to_visit];

double omega = 0;

int i = 0;

for (std::list<int>::const_iterator iterator = cities_to_visit.begin(); iterator != cities_to_visit.end(); ++iterator)

{

int city = *iterator;

omega += probability[i]= map->get_path_visibility(current_city,city)* pow(map->get_pheromone(current_city,city),map->get_alfa());

i++;

}

i = 0;

double chance = map->get_chance();

double probability_sum = probability[0]/omega;


while(probability_sum<=chance)

{

i++;

probability_sum += probability[i]/omega;

}

delete [] probability;

int j = 0;

for (std::list<int>::const_iterator iterator = cities_to_visit.begin(); iterator != cities_to_visit.end(); ++iterator)

{

if(i==j)

{

j = *iterator;

cities_to_visit.erase(iterator);

amount_cities_to_visit --;

return j;


}

j++;

}

return -1;

}


void Ant::run(Draw * draw)

{

if(map == nullptr)

return;


path_lenght = 0;

amount_cities_to_visit = map->get_cityAmount();

path = new int[amount_cities_to_visit];

int current_city = map->get_first_city();

for(int i = 0 ; i< current_city; i++)

{

cities_to_visit.push_back(i);

}

for(int i = current_city+1; i<amount_cities_to_visit; i++)

{

cities_to_visit.push_back(i);

}

amount_cities_to_visit--;

int j = amount_cities_to_visit;


for(int i = 0; i<j; i++)

{

int last_city = current_city;

int succes = -1;

while(succes==-1)

{

current_city = path[i] = path_choice(current_city);

succes=current_city;

}


path_lenght += map->get_cityDistance(last_city,current_city);


}

path_lenght += map->get_cityDistance(current_city,map->get_first_city());

double trail = map->get_Q()/path_lenght;

map->add_delta_pheromone(map->get_first_city(),path[0],trail);

draw->RenderDrawLine(map->GetCity(map->get_first_city()), map->GetCity(path[0]));

map->add_delta_pheromone(map->get_first_city(),path[map->get_cityAmount()-2], trail);

draw->RenderDrawLine(map->GetCity(map->get_first_city()),map->GetCity(path[map->get_cityAmount()-2]));


for(int i = 1 ; i< map->get_cityAmount()-1; i++)

{

map->add_delta_pheromone(path[i],path[i-1],trail);

draw->RenderDrawLine(map->GetCity(path[i]).get_x(),map->GetCity(path[i]).get_y(),

map->GetCity(path[i-1]).get_x(),map->GetCity(path[i-1]).get_y());


}

if(map->if_best_path(path_lenght))

map->save_best(path);
