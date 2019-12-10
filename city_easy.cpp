#include <iostream>
#include <vector>
#include <math.h>


struct City
{
    int x,y;

    City(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

};

class Algoritm
{
    int city_count=0;
    int start_city=0;
    std::vector <City> city_list;

public:
    Algoritm() {}
    void set_start(int m)
    {
        start_city = m-1;
    }
    void add(int x,int y)
    {
        city_list.push_back(City(x,y));
        city_count++;
    }

    void calculate()
    {
        std::vector <int> cities_to_visit_list;
        std::vector <int> cities_visited_list;
        double shortest_way = -1;
        double shortest_way_to_city, distance;
        int num_cities_to_visit = city_count, k_city;
        int actual_city = start_city;
        double total_distance;

        cities_visited_list.push_back(start_city);

        for (int i=0; i<start_city; i++)
            cities_to_visit_list.push_back(i);

        for (int i=start_city+1; i<city_count; i++)
            cities_to_visit_list.push_back(i);

        num_cities_to_visit--;

        int j= num_cities_to_visit;
        for (int i = 0; i<j; i++)
        {
            for(int k = 0 ; k<num_cities_to_visit; k++)
            {
                distance =sqrt( 
pow(double(city_list[cities_to_visit_list[k]].x -
city_list[actual_city].x),2) +
                             
pow(double(city_list[cities_to_visit_list[k]].y -
city_list[actual_city].y),2));

                if(shortest_way == -1.0f)
                {
                    shortest_way = distance;
                    shortest_way_to_city = cities_to_visit_list[k];
                    k_city = k;
                }
                else if( shortest_way> distance)
                {
                    shortest_way = distance;
                    shortest_way_to_city = cities_to_visit_list[k];
                    k_city = k;

                }
            }
            total_distance+= shortest_way;
            shortest_way = -1.0f;
            actual_city = shortest_way_to_city;
            cities_visited_list.push_back(shortest_way_to_city);
           
cities_to_visit_list.erase(cities_to_visit_list.begin()+k_city);
            num_cities_to_visit--;
        }
        cities_visited_list.push_back(start_city);
        total_distance+= distance =sqrt( 
pow(double(city_list[start_city].x - city_list[actual_city].x),2) +
                                  pow(double(city_list[start_city].y -
city_list[actual_city].y),2));

        for(int i = 0; i<city_count+1; i++)
            std:: cout<<
cities_visited_list[i]+1<<",";
        std:: cout<< "\n Droga przebyta: " <<
total_distance <<std:: endl;
    }
    void print()
    {
        std::  cout << "Liczba miast: "<<
city_count<<std:: endl;
        for (int i=0; i<city_count; i++)
            std::   cout<< "miasto: " <<
i+1<<"("<<city_list[i].x<<","<<city_list[i].y<<")"<<std::endl;
    }
};


int main()
{
    Algoritm algorytm;
    int choice;
    bool program_working=1;


    while (program_working)
    {
        std:: cout << "1.ADD 2.Calculate the route 3.Set start
city 4.End program\n";
        std:: cin >> choice;
        switch (choice)
        {
        case 1:
            int x,y;
            std::cout << "set x:\n";
            std::cin >> x;
            std:: cout << "set y:\n";
            std::cin >> y;
            algorytm.add(x,y);
            algorytm.print() ;
            break;
        case 2:
            algorytm.calculate();
            break;
        case 3:
            std::cout <<"Enter the city:\n";
            std::cin >> choice;
            algorytm.set_start(choice);
            break;
        case 4:
            program_working=0;
        }
    }
    return 0;
}
