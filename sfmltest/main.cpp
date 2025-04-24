#include "Headers.h"
#include "cellsclasses.h"
constexpr int Height = 30;


void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height, float cellSize = 20.0f, float lineThickness = 2.0f); //отрисовка лабиринта
void generatearray(Cell cells[][30], int width, int height); //создание лабиринта

void moveant(sf::CircleShape& Ant, Cell cells[][30], int antcords[2], float cellSize = 20.0f)
{
    int antX = antcords[0];
    int antY = antcords[1];
    if (cells[antX][antY].Right == CellState::Open)
            {
                antcords[0]++;
                Ant.move(sf::Vector2f(cellSize, 0));
                return;
            }       
    else if (cells[antX][antY].Top == CellState::Open)
    {
        antcords[1]--;
        Ant.move(sf::Vector2f(0, -cellSize));
        return;
    }
    else if (cells[antX][antY].Left == CellState::Open)
    {
        antcords[0]--;
        Ant.move(sf::Vector2f(-cellSize, 0));
        return;
    }
    else if (cells[antX][antY].Bottom == CellState::Open)
    {
        antcords[1]++;
        Ant.move(sf::Vector2f(0, cellSize));
        return;
    }
            
}

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
    //¬ыбираем первую €чейку откуда начнем движение
    srand(time(0));
    generatearray(cells, width, height); //создаЄм непосредственно лабиринт в массиве €чеек
    int antcords[2] = { 0 };
    antcords[0] = rand() % (width);
    antcords[1] = rand() % (height);

    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    window.setVerticalSyncEnabled(true);
    sf::CircleShape Ant({ cellSize / 2 });
    int antX = antcords[0]*cellSize;
    int antY = antcords[1]*cellSize;
    Ant.setPosition(sf::Vector2f(antX, antY));
    Ant.setFillColor(sf::Color::Red);
    window.setFramerateLimit(5);
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
            moveant(Ant, cells, antcords);
            window.draw(Ant);
            window.display();
        }
}

