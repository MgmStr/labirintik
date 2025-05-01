#include "Headers.h"
#include "cellsclasses.h"
constexpr int Height = 30;

void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height, float cellSize = 20.0f, float lineThickness = 2.0f); //отрисовка лабиринта
void generatearray(Cell cells[][30], int width, int height); //создание лабиринта
void hungryAndLost(sf::Vector2i& Foodpos, Cell cells[][30], int width, int height, Ant& Ant);
void goHome(sf::Vector2i& home, sf::Vector2i& Foodpos, Cell cells[][30], int width, int height, Ant& Ant, int& step);

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
    Ant Ant0;
    int step = 0;
    sf::Vector2i Foodpos = { 0, 0 };
    sf::Vector2i Home = { 0,0 };
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    sf::RectangleShape entity({ cellSize-5, cellSize-5});
    sf::CircleShape Berry({ cellSize / 2 });
    entity.setPosition(sf::Vector2f(Ant0.getX()*cellSize, Ant0.getY()*cellSize));
    entity.setFillColor(sf::Color::Red);
    Berry.setFillColor(sf::Color::Blue);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(2);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // если закрываетс€ окно, программа закрываетс€
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            if ((Ant0.checkF() == false)&&(Ant0.checkS()==false))
                hungryAndLost(Foodpos, cells, width, height, Ant0);
            Berry.setPosition(sf::Vector2f(Foodpos.x * cellSize, Foodpos.y * cellSize));
            Ant0.plusStep(step);
            step++;
            entity.setPosition(sf::Vector2f(Ant0.getX() * cellSize+3, Ant0.getY() * cellSize+3));
            if ((Ant0.getX() == Foodpos.x) && (Ant0.getY() == Foodpos.y))
                goHome(Home, Foodpos, cells, width, height, Ant0, step);
            if ((Ant0.getX() == Home.x) && (Ant0.getY() == Home.y) && (Ant0.checkS() == true))
            {
                Ant0.isFinding(false);
                step = 0;
                Ant0.isHungry(false);
            }
            window.clear(sf::Color::White);
            renderCells(window, cells, width, height); //вызываем функцию отрисовки стенок лабиринт
            window.draw(entity);
            window.draw(Berry);
            window.display();
        }
}