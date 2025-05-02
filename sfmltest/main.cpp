#include "Headers.h"
#include "cellsclasses.h"
constexpr int Height = 30;

void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height, float cellSize = 20.0f, float lineThickness = 2.0f); //отрисовка лабиринта
void generatearray(Cell cells[][30], int width, int height); //создание лабиринта
void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][30], int width, int height, short& count);

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
    //инициализируем все потенциальные объекты
    Ant Ant0;
    sf::RectangleShape entity0({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry0({ cellSize / 2 });
    entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize, Ant0.getY() * cellSize));
    entity0.setFillColor(sf::Color::Red);
    Berry0.setFillColor(sf::Color::Blue);
    Ant Ant1;
    sf::RectangleShape entity1({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry1({ cellSize / 2 });
    entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize, Ant1.getY() * cellSize));
    entity1.setFillColor(sf::Color::Red);
    Berry1.setFillColor(sf::Color::Blue);
    Ant Ant2;
    sf::RectangleShape entity2({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry2({ cellSize / 2 });
    entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize, Ant2.getY() * cellSize));
    entity2.setFillColor(sf::Color::Red);
    Berry2.setFillColor(sf::Color::Blue);
    Ant Ant3;
    sf::RectangleShape entity3({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry3({ cellSize / 2 });
    entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize, Ant3.getY() * cellSize));
    entity3.setFillColor(sf::Color::Red);
    Berry3.setFillColor(sf::Color::Blue);
    Ant Ant4;
    sf::RectangleShape entity4({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry4({ cellSize / 2 });
    entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize, Ant4.getY() * cellSize));
    entity4.setFillColor(sf::Color::Red);
    Berry4.setFillColor(sf::Color::Blue);
    Ant Ant5;
    sf::RectangleShape entity5({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry5({ cellSize / 2 });
    entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize, Ant5.getY() * cellSize));
    entity5.setFillColor(sf::Color::Red);
    Berry5.setFillColor(sf::Color::Blue);
    Ant Ant6;
    sf::RectangleShape entity6({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry6({ cellSize / 2 });
    entity6.setPosition(sf::Vector2f(Ant6.getX() * cellSize, Ant6.getY() * cellSize));
    entity6.setFillColor(sf::Color::Red);
    Berry6.setFillColor(sf::Color::Blue);
    Ant Ant7;
    sf::RectangleShape entity7({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry7({ cellSize / 2 });
    entity7.setPosition(sf::Vector2f(Ant7.getX() * cellSize, Ant7.getY() * cellSize));
    entity7.setFillColor(sf::Color::Red);
    Berry7.setFillColor(sf::Color::Blue);
    Ant Ant8;
    sf::RectangleShape entity8({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry8({ cellSize / 2 });
    entity8.setPosition(sf::Vector2f(Ant8.getX() * cellSize, Ant8.getY() * cellSize));
    entity8.setFillColor(sf::Color::Red);
    Berry8.setFillColor(sf::Color::Blue);
    Ant Ant9;
    sf::RectangleShape entity9({ cellSize - 5, cellSize - 5 });
    sf::CircleShape Berry9({ cellSize / 2 });
    entity9.setPosition(sf::Vector2f(Ant9.getX() * cellSize, Ant9.getY() * cellSize));
    entity9.setFillColor(sf::Color::Red);
    Berry9.setFillColor(sf::Color::Blue);
    sf::Vector2i Home = { 0,0 };
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    short AntsCount = 1;
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(5);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // если закрываетс€ окно, программа закрываетс€
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            switch (AntsCount)
            {
            case 1:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                break;
            }
            case 2:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                break;
            }
            case 3:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                break;
            }
            case 4:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                break;
            }
            case 5:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                break;
            }
            case 6:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                Antmove(Ant5, Home, cells, width, height, AntsCount);
                Berry5.setPosition(sf::Vector2f(Ant5.Foodpos().x * cellSize, Ant5.Foodpos().y * cellSize));
                entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize + 5 / 2, Ant5.getY() * cellSize + 5 / 2));
                break;
            }
            case 7:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                Antmove(Ant5, Home, cells, width, height, AntsCount);
                Berry5.setPosition(sf::Vector2f(Ant5.Foodpos().x * cellSize, Ant5.Foodpos().y * cellSize));
                entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize + 5 / 2, Ant5.getY() * cellSize + 5 / 2));
                Antmove(Ant6, Home, cells, width, height, AntsCount);
                Berry6.setPosition(sf::Vector2f(Ant6.Foodpos().x * cellSize, Ant6.Foodpos().y * cellSize));
                entity6.setPosition(sf::Vector2f(Ant6.getX() * cellSize + 5 / 2, Ant6.getY() * cellSize + 5 / 2));
                break;
            }
            case 8:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                Antmove(Ant5, Home, cells, width, height, AntsCount);
                Berry5.setPosition(sf::Vector2f(Ant5.Foodpos().x * cellSize, Ant5.Foodpos().y * cellSize));
                entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize + 5 / 2, Ant5.getY() * cellSize + 5 / 2));
                Antmove(Ant6, Home, cells, width, height, AntsCount);
                Berry6.setPosition(sf::Vector2f(Ant6.Foodpos().x * cellSize, Ant6.Foodpos().y * cellSize));
                entity6.setPosition(sf::Vector2f(Ant6.getX() * cellSize + 5 / 2, Ant6.getY() * cellSize + 5 / 2));
                Antmove(Ant7, Home, cells, width, height, AntsCount);
                Berry7.setPosition(sf::Vector2f(Ant7.Foodpos().x * cellSize, Ant7.Foodpos().y * cellSize));
                entity7.setPosition(sf::Vector2f(Ant7.getX() * cellSize + 5 / 2, Ant7.getY() * cellSize + 5 / 2));
                break;
            }
            case 9:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                Antmove(Ant5, Home, cells, width, height, AntsCount);
                Berry5.setPosition(sf::Vector2f(Ant5.Foodpos().x * cellSize, Ant5.Foodpos().y * cellSize));
                entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize + 5 / 2, Ant5.getY() * cellSize + 5 / 2));
                Antmove(Ant6, Home, cells, width, height, AntsCount);
                Berry6.setPosition(sf::Vector2f(Ant6.Foodpos().x * cellSize, Ant6.Foodpos().y * cellSize));
                entity6.setPosition(sf::Vector2f(Ant6.getX() * cellSize + 5 / 2, Ant6.getY() * cellSize + 5 / 2));
                Antmove(Ant7, Home, cells, width, height, AntsCount);
                Berry7.setPosition(sf::Vector2f(Ant7.Foodpos().x * cellSize, Ant7.Foodpos().y * cellSize));
                entity7.setPosition(sf::Vector2f(Ant7.getX() * cellSize + 5 / 2, Ant7.getY() * cellSize + 5 / 2));
                Antmove(Ant8, Home, cells, width, height, AntsCount);
                Berry8.setPosition(sf::Vector2f(Ant8.Foodpos().x * cellSize, Ant8.Foodpos().y * cellSize));
                entity8.setPosition(sf::Vector2f(Ant8.getX() * cellSize + 5 / 2, Ant8.getY() * cellSize + 5 / 2));
                break;
            }
            case 10:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                Antmove(Ant5, Home, cells, width, height, AntsCount);
                Berry5.setPosition(sf::Vector2f(Ant5.Foodpos().x * cellSize, Ant5.Foodpos().y * cellSize));
                entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize + 5 / 2, Ant5.getY() * cellSize + 5 / 2));
                Antmove(Ant6, Home, cells, width, height, AntsCount);
                Berry6.setPosition(sf::Vector2f(Ant6.Foodpos().x * cellSize, Ant6.Foodpos().y * cellSize));
                entity6.setPosition(sf::Vector2f(Ant6.getX() * cellSize + 5 / 2, Ant6.getY() * cellSize + 5 / 2));
                Antmove(Ant7, Home, cells, width, height, AntsCount);
                Berry7.setPosition(sf::Vector2f(Ant7.Foodpos().x * cellSize, Ant7.Foodpos().y * cellSize));
                entity7.setPosition(sf::Vector2f(Ant7.getX() * cellSize + 5 / 2, Ant7.getY() * cellSize + 5 / 2));
                Antmove(Ant8, Home, cells, width, height, AntsCount);
                Berry8.setPosition(sf::Vector2f(Ant8.Foodpos().x * cellSize, Ant8.Foodpos().y * cellSize));
                entity8.setPosition(sf::Vector2f(Ant8.getX() * cellSize + 5 / 2, Ant8.getY() * cellSize + 5 / 2));
                Antmove(Ant9, Home, cells, width, height, AntsCount);
                Berry9.setPosition(sf::Vector2f(Ant9.Foodpos().x * cellSize, Ant9.Foodpos().y * cellSize));
                entity9.setPosition(sf::Vector2f(Ant9.getX() * cellSize + 5 / 2, Ant9.getY() * cellSize + 5 / 2));
                break;
            }
            default:
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount);
                Berry0.setPosition(sf::Vector2f(Ant0.Foodpos().x * cellSize, Ant0.Foodpos().y * cellSize));
                entity0.setPosition(sf::Vector2f(Ant0.getX() * cellSize + 5 / 2, Ant0.getY() * cellSize + 5 / 2));
                Antmove(Ant1, Home, cells, width, height, AntsCount);
                Berry1.setPosition(sf::Vector2f(Ant1.Foodpos().x * cellSize, Ant1.Foodpos().y * cellSize));
                entity1.setPosition(sf::Vector2f(Ant1.getX() * cellSize + 5 / 2, Ant1.getY() * cellSize + 5 / 2));
                Antmove(Ant2, Home, cells, width, height, AntsCount);
                Berry2.setPosition(sf::Vector2f(Ant2.Foodpos().x * cellSize, Ant2.Foodpos().y * cellSize));
                entity2.setPosition(sf::Vector2f(Ant2.getX() * cellSize + 5 / 2, Ant2.getY() * cellSize + 5 / 2));
                Antmove(Ant3, Home, cells, width, height, AntsCount);
                Berry3.setPosition(sf::Vector2f(Ant3.Foodpos().x * cellSize, Ant3.Foodpos().y * cellSize));
                entity3.setPosition(sf::Vector2f(Ant3.getX() * cellSize + 5 / 2, Ant3.getY() * cellSize + 5 / 2));
                Antmove(Ant4, Home, cells, width, height, AntsCount);
                Berry4.setPosition(sf::Vector2f(Ant4.Foodpos().x * cellSize, Ant4.Foodpos().y * cellSize));
                entity4.setPosition(sf::Vector2f(Ant4.getX() * cellSize + 5 / 2, Ant4.getY() * cellSize + 5 / 2));
                Antmove(Ant5, Home, cells, width, height, AntsCount);
                Berry5.setPosition(sf::Vector2f(Ant5.Foodpos().x * cellSize, Ant5.Foodpos().y * cellSize));
                entity5.setPosition(sf::Vector2f(Ant5.getX() * cellSize + 5 / 2, Ant5.getY() * cellSize + 5 / 2));
                Antmove(Ant6, Home, cells, width, height, AntsCount);
                Berry6.setPosition(sf::Vector2f(Ant6.Foodpos().x * cellSize, Ant6.Foodpos().y * cellSize));
                entity6.setPosition(sf::Vector2f(Ant6.getX() * cellSize + 5 / 2, Ant6.getY() * cellSize + 5 / 2));
                Antmove(Ant7, Home, cells, width, height, AntsCount);
                Berry7.setPosition(sf::Vector2f(Ant7.Foodpos().x * cellSize, Ant7.Foodpos().y * cellSize));
                entity7.setPosition(sf::Vector2f(Ant7.getX() * cellSize + 5 / 2, Ant7.getY() * cellSize + 5 / 2));
                Antmove(Ant8, Home, cells, width, height, AntsCount);
                Berry8.setPosition(sf::Vector2f(Ant8.Foodpos().x * cellSize, Ant8.Foodpos().y * cellSize));
                entity8.setPosition(sf::Vector2f(Ant8.getX() * cellSize + 5 / 2, Ant8.getY() * cellSize + 5 / 2));
                Antmove(Ant9, Home, cells, width, height, AntsCount);
                Berry9.setPosition(sf::Vector2f(Ant9.Foodpos().x * cellSize, Ant9.Foodpos().y * cellSize));
                entity9.setPosition(sf::Vector2f(Ant9.getX() * cellSize + 5 / 2, Ant9.getY() * cellSize + 5 / 2));
                break;
            }
            }
            window.clear(sf::Color::White);
            switch (AntsCount)
            {
            case 1:
            { window.draw(entity0); window.draw(Berry0); break; }
            case 2:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                break;
            }
            case 3:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                break;
            }
            case 4:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                break;
            }
            case 5:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                break;
            }
            case 6:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                window.draw(entity5); window.draw(Berry5);
                break;
            }
            case 7:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                window.draw(entity5); window.draw(Berry5);
                window.draw(entity6); window.draw(Berry6);
                break;
            }
            case 8:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                window.draw(entity5); window.draw(Berry5);
                window.draw(entity6); window.draw(Berry6);
                window.draw(entity7); window.draw(Berry7);
                break;
            }
            case 9:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                window.draw(entity5); window.draw(Berry5);
                window.draw(entity6); window.draw(Berry6);
                window.draw(entity7); window.draw(Berry7);
                window.draw(entity8); window.draw(Berry8);
                break;
            }
            case 10:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                window.draw(entity5); window.draw(Berry5);
                window.draw(entity6); window.draw(Berry6);
                window.draw(entity7); window.draw(Berry7);
                window.draw(entity8); window.draw(Berry8);
                window.draw(entity9); window.draw(Berry9);
                break;
            }
            default:
            {
                window.draw(entity0); window.draw(Berry0);
                window.draw(entity1); window.draw(Berry1);
                window.draw(entity2); window.draw(Berry2);
                window.draw(entity3); window.draw(Berry3);
                window.draw(entity4); window.draw(Berry4);
                window.draw(entity5); window.draw(Berry5);
                window.draw(entity6); window.draw(Berry6);
                window.draw(entity7); window.draw(Berry7);
                window.draw(entity8); window.draw(Berry8);
                window.draw(entity9); window.draw(Berry9);
            }
            }
            
            
            renderCells(window, cells, width, height); //вызываем функцию отрисовки стенок лабиринт
            window.display();
        }
}