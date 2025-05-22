#include "Headers.h"

int main()
{
    const int cellSize = 20;
    const int width = 40, height = 30; //размер пол€(в количестве €чеек)
    const int maximum = 20;

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
    sf::Texture redAnt("unnamed.png");
    sf::Texture chernika("blueberry.png");
    //инициализируем все потенциальные объекты;
    sf::Sprite entity(redAnt);
    Ant ants[maximum] = {entity, entity, entity, entity, entity, entity, entity, entity, entity, 
        entity, entity, entity, entity, entity, entity, entity, entity, entity, entity, entity };
    for (int i = 0; i < maximum; i++)
    {
        initAnt(cells, ants[i], ants[i].entity);
    }
    sf::Sprite Berry(chernika);
    Food Berryies[maximum] = { Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry,
        Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry, Berry };
    sf::Vector2i Home = { 0,0 };
    //текстура фона
    sf::Texture ground("background.png");
    sf::Sprite background(ground);
    background.setTextureRect(sf::IntRect({ 0, 0 }, { width*cellSize, height*cellSize }));
    sf::Texture hometexture("hole.png");
    sf::Sprite anthill(hometexture);
    anthill.setTextureRect(sf::IntRect({ 0, 0 }, {2 * cellSize+3, 2 * cellSize +3}));
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    int AntsCount = 1;
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
                    Antmove(ants[i], Home, cells, width, height, AntsCount, ants[i].entity, Berryies[i].berry);
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
            renderCells(window, cells, width, height); //вызываем функцию отрисовки стенок лабиринт
            window.draw(anthill);
            window.display();
        }
}