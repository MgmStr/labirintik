#include "Headers.h"

void Antmove(Ant& Ant, sf::Vector2i home, Cell cells[][40], int width, int height, int& count, sf::Sprite& berry)
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
    Ant.entity.setPosition(sf::Vector2f(7.5 + Ant.getX() * cellSize + 5 / 2, 10.0 + Ant.getY() * cellSize + 5 / 2));
    if (Ant.rotateChek() < 2)
    {
        Ant.plus90();
        Ant.entity.rotate(sf::degrees(90));
    }
}
void initAnt(Cell cells[][40], Ant Ant, sf::Sprite& mob)
{
    int cellSize = 20;
    mob.setTextureRect(sf::IntRect({ 0,0 }, { cellSize - 5, cellSize }));
    mob.setPosition(sf::Vector2f(Ant.getX() * cellSize, Ant.getY() * cellSize));
    mob.setOrigin({ 7.5f, 10.0f });
}
void initAnt(Cell cells[][40], BadAnt& Ant)
{
    int cellSize = 20;
    Ant.entity.setTextureRect(sf::IntRect({ 0,0 }, { cellSize - 5, cellSize }));
    Ant.entity.setPosition(sf::Vector2f(Ant.getX() * cellSize, Ant.getY() * cellSize));
    Ant.entity.setOrigin({ 7.5f, 10.0f });
}

void War(Ant ants[], BadAnt enemyies[], Cell cells[][40], int width, int height, int& count, sf::Vector2i home)
{
    float cellSize = 20.0f;
    if (count >= 20)
    {
        sf::Vector2i corner = { (width-1),(height-1)};
        for (int i = 0; i < 5; i++)
        {
            if (enemyies[i].checkH() != true)
            {
                enemyies[i].setpath(findPath(cells, width, height, corner, home));
                enemyies[i].isHunting(true);
                enemyies[i].checkNew();
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (enemyies[i].checkH() == true)
        {
            for (int n = 0; n < count; n++)
            {
                if ((ants[n].getX() == enemyies[i].getX()) && (ants[n].getY() == enemyies[i].getY()))
                {
                    ants[n].zeroStep();
                    ants[n].moveTo(0, 0);
                    ants[n].entity.rotate(sf::degrees(-ants[n].plus90()));
                    count--;
                    enemyies[i].goHome();
                    enemyies[i].entity.rotate(sf::degrees(-enemyies[n].plus90()));
                }
            }
            enemyies[i].plusStep();
            enemyies[i].entity.setPosition(sf::Vector2f(7.5 + enemyies[i].getX() * cellSize + 5 / 2, 10.0 + enemyies[i].getY() * cellSize + 5 / 2));
            if (enemyies[i].rotateChek() < 2)
            {
                enemyies[i].plus90();
                enemyies[i].entity.rotate(sf::degrees(90));
            }
        }
    }
}

//����������� �������� ���� �������� ����� ���������� � � zerostate �������� �