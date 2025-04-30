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
    Cell() :x(0), y(0), Left(Close), Right(Close), Top(Close), Bottom(Close), Visited(false) //����������� �� ���������, ����� ��� ������ ����� ����������� ��������� � �������������
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
        return findingFood;
    }
    void plusStep(int step)
    {
        auto nextcord = path[step];
        x = nextcord.x;
        y = nextcord.y;
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
    void isSatiety()
    {
        Satiety = true;
    }
};
