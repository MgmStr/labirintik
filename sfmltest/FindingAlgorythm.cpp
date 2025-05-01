#include "Headers.h"
#include "cellsclasses.h"
std::vector<sf::Vector2i> findPath(Cell cells[][30], int width, int height, sf::Vector2i start, sf::Vector2i end);

void hungryAndLost(sf::Vector2i& Foodpos, Cell cells[][30], int width, int height, Ant& Ant)
{
    sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
    Foodpos = { rand() % width, rand() % height };
    Ant.setpath(findPath(cells, width, height, currentpos, Foodpos));
    Ant.isFinding(true);
}

void goHome(sf::Vector2i& home, sf::Vector2i& Foodpos, Cell cells[][30], int width, int height, Ant& Ant, int& step)
{
    step = 0;
    sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
    Ant.isHungry(true);
    Foodpos = { -1, -1 };
    Ant.setpath(findPath(cells, width, height, currentpos, home));
}