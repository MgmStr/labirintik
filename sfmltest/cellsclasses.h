#pragma once
#include "Headers.h"
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
private:
    int x;
    int y;
    std::vector<sf::Vector2i> path;
    bool Satiety;
    bool findingFood;
    sf::Vector2i Foodcords;
    int step;
public:
    sf::Sprite entity;
    Ant (sf::Sprite p_entity): x(0), y(0), Satiety(false), findingFood(false), path(), Foodcords({-1,-1}), step(0), entity(p_entity){}
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
    float rotateChek()
    {
        float scalable = 2.0;
        if ((step>0))
        scalable = sqrt(pow((path[step + 1].x - path[step - 1].x), 2) + pow((path[step + 1].y - path[step - 1].y), 2));
        return scalable;
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

struct Food
{
    sf::Sprite berry;
    Food(sf::Sprite p_berry):berry(p_berry)
    {
        berry.setTextureRect(sf::IntRect({ 0,0 }, { 18, 18 }));
    }
};