#include "Headers.h"
#include "cellsclasses.h"
std::vector<sf::Vector2i> findPath(Cell cells[][30], int width, int height, sf::Vector2i start, sf::Vector2i end);

void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][30], int width, int height, short& count)
{
    if ((Ant.checkF() == false) && (Ant.checkS() == false))
    {
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.Foodpos(rand() % width, rand() % height);
        Ant.setpath(findPath(cells, width, height, currentpos, Ant.Foodpos()));
        Ant.isFinding(true);
    }
    Ant.plusStep();
    if ((Ant.getX() == Ant.Foodpos().x) && (Ant.getY() == Ant.Foodpos().y))
    {
        Ant.zeroStep();
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.isHungry(true);
        Ant.Foodpos(-1, -1);
        Ant.setpath(findPath(cells, width, height, currentpos, home));
    }
    if ((Ant.getX() == home.x) && (Ant.getY() == home.y) && (Ant.checkS() == true))
    {
        Ant.zeroStep();
        count++;
    }
    return;
}