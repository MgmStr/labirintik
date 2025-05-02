#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
enum CellState { Close, Open };
class Cell
{
public:
    int x;
    int y;
    CellState Left;
    CellState Right;
    CellState Top;
    CellState Bottom;
    bool Visited;
    Cell() :x(0), y(0), Left(Close), Right(Close), Top(Close), Bottom(Close), Visited(false) //конструктор по умолчанию, чтобы все €чейки сразу создавались закрытыми и непосещЄнными
    {}
};

class Ant
{
protected:
    int x;
    int y;
    std::vector<sf::Vector2i> path;
    bool Satiety;
    bool findingFood;
    sf::Vector2i Foodcords;
    int step;
public:
    Ant (int start_x = 0, int start_y = 0): x(start_x), y(start_y), Satiety(false), findingFood(false), path(), Foodcords({-1,-1}), step(0) {}
    bool checkS()
    {
        return Satiety;
    }
    bool checkF()
    {
        return findingFood;
    }
    void plusStep()
    {
        step++;
        auto nextcord = path[step];
        x = nextcord.x;
        y = nextcord.y;
    }
    void zeroStep()
    {
        step = 0;
        findingFood = false;
        Satiety = false;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setpath(std::vector<sf::Vector2i> path_p)
    {
        path = path_p;
    }
    void isFinding(bool state)
    {
        findingFood = state;
    }
    void isHungry(bool state)
    {
        Satiety = state;
    }
    sf::Vector2i Foodpos()
    {
        return Foodcords;
    }
    void Foodpos(int i, int y)
    {
        Foodcords = { i, y };
    }
};

/*class Anthill
{
private:
    Ant ant;
    sf::RectangleShape entity;
    sf::CircleShape Berry0;
};*/