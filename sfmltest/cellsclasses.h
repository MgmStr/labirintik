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
    bool newBorn;
public:
    sf::Sprite entity;
    Ant(sf::Sprite p_ent) : x(0), y(0), Satiety(false), findingFood(false), path(), Foodcords({ -1,-1 }), step(0), newBorn(true), entity(p_ent) {}
    void checkNew();
    void plusStep();
    void zeroStep();
    float rotateChek();
    void moveTo(int p_x, int p_y);
    bool checkS()
    {
        return Satiety;
    }
    bool checkF()
    {
        return findingFood;
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

struct Food
{
    sf::Sprite berry;
    Food(sf::Sprite p_berry):berry(p_berry)
    {
        berry.setTextureRect(sf::IntRect({ 0,0 }, { 18, 18 }));
    }
};

class BadAnt
{
private:
    int x;
    int y;
    std::vector<sf::Vector2i> path;
    int step;
    bool newBorn;
    bool hunting;
public:
    sf::Sprite entity;
    BadAnt(sf::Sprite p_ent) : x(59), y(39), entity(p_ent), step(0), newBorn(true), hunting(false) {}
    void plusStep();
    sf::Vector2i checkNext()
    {
        return path[step + 1];
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
    void isHunting(bool state)
    {
        hunting = state;
    }
    bool checkH()
    {
        return hunting;
    }
    void goHome();
    void checkNew();
    float rotateChek();
};