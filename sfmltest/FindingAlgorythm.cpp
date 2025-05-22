#include "Headers.h"

void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][30], int width, int height, int& count, sf::Sprite& ent, sf::Sprite& berry)
{
    float cellSize = 20.0f;
    if ((Ant.checkF() == false) && (Ant.checkS() == false)) //���� �������� � �� ���� ���, �� �������� ����
    {
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.Foodpos(rand() % (width-1)+1, rand() % (height-1)+1);
        Ant.setpath(findPath(cells, width, height, currentpos, Ant.Foodpos()));
        Ant.isFinding(true);
        Ant.checkNew();
    }
    Ant.plusStep();
    if ((Ant.getX() == Ant.Foodpos().x) && (Ant.getY() == Ant.Foodpos().y)) //���� ���, ������������ �����
    {
        Ant.zeroStep();
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.isHungry(true);
        Ant.Foodpos(-1, -1);
        Ant.setpath(findPath(cells, width, height, currentpos, home));
    }
    if ((Ant.getX() == home.x) && (Ant.getY() == home.y) && (Ant.checkS() == true)) //��������� ���������
    {
        Ant.zeroStep();
        count++;
    }
    //�������� �����
    berry.setPosition(sf::Vector2f(Ant.Foodpos().x * cellSize, Ant.Foodpos().y * cellSize));
    ent.setPosition(sf::Vector2f(7.5+Ant.getX() * cellSize + 5 / 2, 10.0+Ant.getY() * cellSize + 5 / 2));
    if (Ant.rotateChek() < 2)
        ent.rotate(sf::degrees(90));
}
void initAnt(Cell cells[][30], Ant Ant, sf::Sprite& mob)
{
    int cellSize = 20;
    mob.setTextureRect(sf::IntRect({ 0,0 }, { cellSize - 5, cellSize }));
    mob.setPosition(sf::Vector2f(Ant.getX() * cellSize, Ant.getY() * cellSize));
    mob.setOrigin({ 7.5f, 10.0f });
}