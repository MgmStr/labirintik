#include "Headers.h"

int main()
{
    const int cellSize = 20;
    const int width = 60, height = 40; //������ ����(� ���������� �����)
    const int maximum = 20; //������������ �������� ��������/����

    Cell cells[width][height];

    //��������� ��������� ������ ��� �����
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cells[x][y].x = x;
            cells[x][y].y = y;
        }
    }
    srand(time(0));
    generatearray(cells, width, height); //������ ��������������� �������� � ������� �����
    sf::Texture redAnt("unnamed.png");
    sf::Texture chernika("blueberry.png");
    //�������������� ��� ������������� �������;
    sf::Sprite entity(redAnt);
    Ant ants[maximum] = { entity, entity, entity, entity, entity, entity, entity, entity, entity,
        entity, entity, entity, entity, entity, entity, entity, entity, entity, entity, entity };;
    for (int i = 0; i < maximum; i++)
    {
        initAnt(cells, ants[i], ants[i].entity);
    }
    sf::Sprite Berry(chernika);
    Food Berryies[maximum] = { Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry,
        Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry };
    sf::Vector2i Home = { 0,0 };
    //�������� ����
    sf::Texture ground("background.png");
    sf::Sprite background(ground);
    background.setTextureRect(sf::IntRect({ 0, 0 }, { width*cellSize, height*cellSize }));
    sf::Texture hometexture("hole.png");
    sf::Sprite anthill(hometexture);
    sf::Texture yellow("yellow.png");
    sf::Sprite badass(yellow);
    BadAnt enemyies[5] = { badass, badass, badass, badass, badass };
    for (int i = 0; i < 5; i++)
    {
        initAnt(cells, enemyies[i]);
    }
    anthill.setTextureRect(sf::IntRect({ 0, 0 }, {2 * cellSize+3, 2 * cellSize +3}));
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    int AntsCount = 1;
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(10);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // ���� ����������� ����, ��������� �����������
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            for (int i = 0; i < AntsCount; i++)
            {
                if (AntsCount <= maximum)
                    Antmove(ants[i], Home, cells, width, height, AntsCount, Berryies[i].berry);
                else AntsCount = maximum;
            }
            window.clear(sf::Color::White);
            window.draw(background);
            for (int i = 0; i < AntsCount; i++)
                if (AntsCount <= maximum)
                {
                    window.draw(ants[i].entity); 
                    window.draw(Berryies[i].berry);
                }
            War(ants, enemyies, cells, width, height, AntsCount, Home);
            for (int i = 0; i < 5; i++)
                window.draw(enemyies[i].entity);
            renderCells(window, cells, width, height); //�������� ������� ��������� ������ ��������
            window.draw(anthill);
            window.display();
        }
}