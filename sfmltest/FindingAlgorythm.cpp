#include "Headers.h"

void Antmove(Ant& Ant, sf::Vector2i home, Cell cells[][40], int width, int height, int& count, sf::Sprite& berry)
{
    float cellSize = 20.0f;
    if ((Ant.checkF() == false) && (Ant.checkS() == false)) //если голодный и не ищет еду, то получает путь
    {
        sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
        Ant.Foodpos(rand() % (width-1)+1, rand() % (height-1)+1);
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
    Ant.entity.setPosition(sf::Vector2f(7.5 + Ant.getX() * cellSize + 5 / 2, 10.0 + Ant.getY() * cellSize + 5 / 2));
    if (Ant.rotateChek() < 2)
    {
        Ant.entity.rotate(sf::degrees(90));
    }
}
void initAnt(Ant& Ant)
{
    int cellSize = 20;
    Ant.entity.setTextureRect(sf::IntRect({ 0,0 }, { cellSize - 5, cellSize }));
    Ant.entity.setPosition(sf::Vector2f(Ant.getX() * cellSize, Ant.getY() * cellSize));
    Ant.entity.setOrigin({ 7.5f, 10.0f });
}
void initAnt(BadAnt& Ant)
{
    int cellSize = 20;
    Ant.entity.setTextureRect(sf::IntRect({ 0,0 }, { cellSize - 5, cellSize }));
    Ant.entity.setPosition(sf::Vector2f(Ant.getX() * cellSize, Ant.getY() * cellSize));
    Ant.entity.setOrigin({ 7.5f, 10.0f });
}

void War(sf::RenderWindow& window, Ant ants[], BadAnt enemyies[], Cell cells[][40], int width, int height, int& count, sf::Vector2i home)
{
    int cellSize = 20.0f;
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
                if ((ants[n].getX() == enemyies[i].getX()) && (ants[n].getY() == enemyies[i].getY()) || ((ants[n].getX() == enemyies[i].checkNext().x) && (ants[n].getY() == enemyies[i].checkNext().y)))
                {
                    ants[n].zeroStep();
                    ants[n].moveTo(0, 0);
                    count--;
                    enemyies[i].goHome();
                }
            }
            enemyies[i].plusStep();
            enemyies[i].entity.setPosition(sf::Vector2f(7.5 + enemyies[i].getX() * cellSize + 5 / 2, 10.0 + enemyies[i].getY() * cellSize + 5 / 2));
            if (enemyies[i].rotateChek() < 2)
            {
                enemyies[i].entity.rotate(sf::degrees(90));
            }
        }
        if ((enemyies[i].getX()==home.x) && (enemyies[i].getY() == home.x))
        {
            sf::Texture end("end.png");
            sf::Sprite SOD(end);
            SOD.setTextureRect(sf::IntRect({ 0,0 }, { width * cellSize, height * cellSize }));
            window.draw(SOD);
            window.setFramerateLimit(0);
            return;
        }
    }
}

//попробовать задавать угол поворота через переменную и в zerostate обнулять её