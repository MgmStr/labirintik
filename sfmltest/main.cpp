#include "Headers.h"
#include "cellsclasses.h"
constexpr int Height = 30;


void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height, float cellSize = 20.0f, float lineThickness = 2.0f); //отрисовка лабиринта
void generatearray(Cell cells[][30], int width, int height); //создание лабиринта
std::vector<sf::Vector2i> findPath(Cell cells[][30], int width, int height, sf::Vector2i start, sf::Vector2i end);


int main()
{
    const int cellSize = 20;
    const int width = 40, height = Height; //размер пол€(в количестве €чеек)

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
    Ant Ant;
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(2);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // если закрываетс€ окно, программа закрываетс€
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            if (Ant.check() == false)
            {
                sf::Vector2i currentpos = { Ant.getX(), Ant.getY() };
                sf::Vector2i Foodpos = { rand() % width, rand() % height };
                Ant.setpath(findPath(cells, width, height, currentpos, Foodpos));
                Ant.check() == true;
            }
            window.clear(sf::Color::White);
            renderCells(window, cells, width, height); //вызываем функцию отрисовки стенок лабиринт
            window.display();
        }
}

