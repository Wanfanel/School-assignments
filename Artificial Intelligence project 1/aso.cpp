#include "aso.h"

Aso::Aso()

{
}

Aso::Aso(Draw *draw)

{

    this->draw = draw;

    ant = new Ant[ant_colony_size];

    for (int i = 0; i < ant_colony_size; i++)

        ant[i] = Ant(&city_map);
}

void Aso::add_city(float x, float y)

{

    city_map.add_city(x, y);
}

void Aso::test()

{

    float temp = city_map.GetCity(1).get_x();

    SDL_LogMessage(SDL_LOG_CATEGORY_TEST, SDL_LOG_PRIORITY_INFO, "City 0 x = %f", temp);

    draw->RenderDrawCity(100, 100);
}

void Aso::run(Draw *draw)

{

    for (int i = 0; i < ant_colony_size; i++)

    {

        ant[i].run(draw);
    }

    city_map.update_pheromone_from_delta();
}

void Aso::Draw_cities()

{

    for (int i = 0; i < city_map.get_cityAmount(); i++)

    {

        City temp_city = city_map.GetCity(i);

        draw->RenderDrawCity(temp_city.get_x(), temp_city.get_y());
    }
}

void Aso::draw_best()

{

    if (city_map.get_best_lenght())

    {

        int last_city = city_map.get_cityAmount() - 1;

        draw->RenderDrawLine(city_map.get_city(city_map.get_first_city()), city_map.get_city(city_map.get_best_city(0)));

        draw->RenderDrawLine(city_map.get_city(city_map.get_first_city()), city_map.get_city(city_map.get_best_city(last_city - 1)));

        for (int i = 1; i != last_city; i++)
        {

            draw->RenderDrawLine(city_map.get_city(city_map.get_best_city(i - 1)), city_map.get_city(city_map.get_best_city(i)));
        }
    }
}

void Aso::set_city_beginning(int c)

{

    if (0 < c && c < city_map.get_cityAmount())
    {

        city_map.set_start_city(c);

        city_map.reset_best();
    }
}

std::string Aso::best_way()

{

    int last_city = city_map.get_cityAmount() - 1;

    std::string best = to_string(city_map.get_first_city());

    for (int i = 0; i < last_city; i++)

        best += "," + to_string(city_map.get_best_city(i));

    best += "," + to_string(city_map.get_first_city());

    return best;
}

float Aso::best_distance()

{

    return (float)city_map.get_best_lenght();
}

Aso::~Aso()

{

    if (ant != nullptr)

    {

        delete[] ant;
    }
}

delete[] path;
}

Ant::Ant(Map *map)

{

    this->map = map;
}

Ant::~Ant()

{

    if (path != nullptr)

    {

        delete[] path;
    }
}
