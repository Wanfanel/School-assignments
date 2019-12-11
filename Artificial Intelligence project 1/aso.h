#ifndef ASO_H

#define ASO_H

#include "ant.h"

#include "Draw.h"

#include "map.h"

#include <sstream>

template <typename T>

std::string to_string(T value)

{

    std::ostringstream os;

    os << value;

    return os.str();
}

class Aso

{

public:
    Aso();

    Aso(Draw *draw);

    void set_city_beginning(int c);

    void draw_best();

    std::string best_way();

    float best_distance();

    virtual ~Aso();

    void add_city(float x, float y);

    void test();

    void run(Draw *draw);

    void Draw_cities();

protected:
private:
    Draw *draw = nullptr;

    Ant *ant = nullptr;

    Map city_map;

    float map_scale = 100;

    int ant_colony_size = 3;
};

#endif // ASO_H
