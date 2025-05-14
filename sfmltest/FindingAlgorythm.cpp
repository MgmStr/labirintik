#include "Headers.h"
#include "cellsclasses.h"
std::vector<sf::Vector2i> findPath(Cell cells[][30], int width, int height, sf::Vector2i start, sf::Vector2i end);//функция поиска пути

void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][30], int width, int height, int& count, sf::Sprite& ent, sf::Sprite& berry, float cellSize = 20.0f)
{
    if ((Ant.checkF() == false) && (Ant.checkS() == false)) //если голодный и не ищет еду, то получает путь
    {
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.Foodpos(rand() % width, rand() % height);
        Ant.setpath(findPath(cells, width, height, currentpos, Ant.Foodpos()));
        Ant.isFinding(true);
        Ant.checkNew();
    }
    Ant.plusStep();
    if ((Ant.getX() == Ant.Foodpos().x) && (Ant.getY() == Ant.Foodpos().y)) //если сыт, возвращается домой
    {
        Ant.zeroStep();
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.isHungry(true);
        Ant.Foodpos(-1, -1);
        Ant.setpath(findPath(cells, width, height, currentpos, home));
    }
    if ((Ant.getX() == home.x) && (Ant.getY() == home.y) && (Ant.checkS() == true)) //обнуление состояния
    {
        Ant.zeroStep();
        count++;
    }
    //движения фигур
    berry.setPosition(sf::Vector2f(Ant.Foodpos().x * cellSize, Ant.Foodpos().y * cellSize));
    ent.setPosition(sf::Vector2f(7.5+Ant.getX() * cellSize + 5 / 2, 10.0+Ant.getY() * cellSize + 5 / 2));
    if (Ant.rotateChek() > 2)
        ent.rotate(sf::degrees(90));
    if (Ant.rotateChek() <2)
        ent.rotate(sf::degrees(-90));
    return;
}
void initAnt(Cell cells[][30], Ant Ant, sf::Sprite& mob, int cellSize = 20)
{
    mob.setTextureRect(sf::IntRect({ 0,0 }, { cellSize - 5, cellSize }));
    mob.setPosition(sf::Vector2f(Ant.getX() * cellSize, Ant.getY() * cellSize));
    mob.setOrigin({ 7.5f, 10.0f });
}