#include "Headers.h"

int main()
{
    const int cellSize = 20;
    const int width = 60, height = 40; //размер пол€(в количестве €чеек)
    const int maximum = 20; //максимальное значение муравьЄв/€год
    int AntsCount = 1;
    Cell cells[width][height];
    //заполн€ем начальные данные дл€ €чеек
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cells[x][y].x = x;
            cells[x][y].y = y;
        }
    }
    srand(time(0));
    generatearray(cells, width, height); //создаЄм непосредственно лабиринт в массиве €чеек
    sf::Texture redAnt("yellow.png");
    sf::Texture chernika("blueberry.png");
    sf::Texture ground("background.png");
    sf::Texture hometexture("hole.png");
    sf::Texture yellow("unnamed.png");
    sf::Sprite entity(redAnt);
    sf::Sprite Berry(chernika);
    sf::Sprite background(ground);
    sf::Sprite anthill1(hometexture);
    sf::Sprite anthill2(hometexture);
    sf::Sprite badass(yellow);
    //инициализируем все потенциальные объекты;
    Ant ants[maximum] = { entity, entity, entity, entity, entity, entity, entity, entity, entity,
        entity, entity, entity, entity, entity, entity, entity, entity, entity, entity, entity };;
    for (int i = 0; i < maximum; i++)
    {
        initAnt(ants[i]);
    }
    Food Berryies[maximum] = { Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry,
        Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry };
    BadAnt enemyies[5] = { badass, badass, badass, badass, badass };
    for (int i = 0; i < 5; i++)
    {
        initAnt(enemyies[i]);
    }
    sf::Vector2i Home = { 0,0 };
    background.setTextureRect(sf::IntRect({ 0, 0 }, { width*cellSize, height*cellSize }));
    anthill1.setTextureRect(sf::IntRect({ 0, 0 }, {2 * cellSize+3, 2 * cellSize +3}));
    anthill2.setTextureRect(sf::IntRect({ 0, 0 }, { 2 * cellSize + 3, 2 * cellSize + 3 }));
    anthill2.setPosition({ (width - 2) * cellSize, (height - 2) * cellSize });
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(10);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // если закрываетс€ окно, программа закрываетс€
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
            War(window, ants, enemyies, cells, width, height, AntsCount, Home);
            for (int i = 0; i < 5; i++)
                window.draw(enemyies[i].entity);
            renderCells(window, cells, width, height); //вызываем функцию отрисовки стенок лабиринт
            War(window, ants, enemyies, cells, width, height, AntsCount, Home);
            for (int i = 0; i < 5; i++)
                window.draw(enemyies[i].entity);
            window.draw(anthill1);
            window.draw(anthill2);
            window.display();
        }
}