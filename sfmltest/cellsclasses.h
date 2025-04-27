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
private:
    int x;
    int y;
    std::vector<sf::Vector2i> path;
    bool Satiety;
    bool findingFood;
public:
    Ant (int start_x = 0, int start_y = 0): x(start_x), y(start_y), Satiety(false), findingFood(false), path() {}
    bool check()
    {
        if (findingFood == false)
            return false;
        else return true;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    const std::vector<sf::Vector2i>& getPath() const 
    { 
        return path; 
    }
    void setpath(std::vector<sf::Vector2i> path_p)
    {
        path = path_p;
    }
};
