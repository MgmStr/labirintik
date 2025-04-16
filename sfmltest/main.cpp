#include "Headers.h"
#include "cellsclasses.h"
constexpr int Height = 40;


void renderCells(sf::RenderWindow& window, Cell cells[][40], int width, int height, float cellSize = 20.0f, float lineThickness = 2.0f); //отрисовка лабиринта
void generatearray(Cell cells[][40], int width, int height); //создание лабиринта

int main()
{
    const int cellSize = 20;
    const int width = 60, height = Height; //размер пол€(в количестве €чеек)

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
    //¬ыбираем первую €чейку откуда начнем движение
    srand(time(0));
    generatearray(cells, width, height); //создаЄм непосредственно лабиринт в массиве €чеек

        sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // если закрываетс€ окно, программа закрываетс€
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            window.clear(sf::Color::White);
            renderCells(window, cells, width, height); //вызываем функцию отрисовки стенок лабиринта
            window.display();
        }
}