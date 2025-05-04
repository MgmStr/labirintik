#include "Headers.h"
#include "cellsclasses.h"
constexpr int Height = 30;

void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height, int cellSize = 20, int lineThickness = 2); //��������� ���������
void generatearray(Cell cells[][30], int width, int height); //�������� ���������
void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][30], int width, int height, short& count, sf::Sprite& ent, sf::Sprite& berry, float cellSize = 20.0f); //������ ��������
void initAnt(Ant Ant, sf::Sprite& mob, int cellSize = 20);//������������� ��������

int main()
{
    const int cellSize = 20;
    const int width = 40, height = Height; //������ ����(� ���������� �����)

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
    //�������������� ��� ������������� �������
    Ant Ant0;
    sf::Sprite entity0(redAnt);
    initAnt(Ant0, entity0);
    sf::Sprite Berry0(chernika);
    Berry0.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2 }));
    Ant Ant1;
    sf::Sprite entity1(redAnt);
    initAnt(Ant1, entity1);
    sf::Sprite Berry1(chernika);
    Berry1.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2}));
    Ant Ant2;
    sf::Sprite entity2(redAnt);
    initAnt(Ant2, entity2);
    sf::Sprite Berry2(chernika);
    Berry2.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2 }));
    Ant Ant3;
    sf::Sprite entity3(redAnt);
    initAnt(Ant3, entity3);
    sf::Sprite Berry3(chernika);
    Berry3.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2}));
    Ant Ant4;
    sf::Sprite entity4(redAnt);
    initAnt(Ant4, entity4);
    sf::Sprite Berry4(chernika);
    Berry4.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize -2}));
    Ant Ant5;
    sf::Sprite entity5(redAnt);
    initAnt(Ant5, entity5);
    sf::Sprite Berry5(chernika);
    Berry5.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2 }));
    Ant Ant6;
    sf::Sprite entity6(redAnt);
    initAnt(Ant6, entity6);
    sf::Sprite Berry6(chernika);
    Berry6.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2 }));
    Ant Ant7;
    sf::Sprite entity7(redAnt);
    initAnt(Ant7, entity7);
    sf::Sprite Berry7(chernika);
    Berry7.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2 }));
    Ant Ant8;
    sf::Sprite entity8(redAnt);
    initAnt(Ant8, entity8);
    sf::Sprite Berry8(chernika);
    Berry8.setTextureRect(sf::IntRect({ 0,0 }, { cellSize-2, cellSize-2 }));
    Ant Ant9;
    sf::Sprite entity9(redAnt);
    initAnt(Ant9, entity9);
    sf::Sprite Berry9(chernika);
    Berry9.setTextureRect(sf::IntRect({ 0,0 }, { cellSize, cellSize }));

    sf::Vector2i Home = { 0,0 };
    //�������� ����
    sf::Texture ground("background.png");
    sf::Sprite background(ground);
    background.setTextureRect(sf::IntRect({ 0, 0 }, { width*cellSize, height*cellSize }));
    sf::Texture hometexture("hole.png");
    sf::Sprite anthill(hometexture);
    anthill.setTextureRect(sf::IntRect({ 0, 0 }, {2 * cellSize, 2 * cellSize }));
    sf::RenderWindow window(sf::VideoMode({ width * cellSize, height * cellSize }), "Labirintio");
    short AntsCount = 1;
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                // ���� ����������� ����, ��������� �����������
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            if (AntsCount > 0)
            {
                Antmove(Ant0, Home, cells, width, height, AntsCount, entity0, Berry0);
                if (AntsCount > 1)
                {
                    Antmove(Ant1, Home, cells, width, height, AntsCount, entity1, Berry1);
                    if (AntsCount > 2)
                    {
                        Antmove(Ant2, Home, cells, width, height, AntsCount, entity2, Berry2);
                        if (AntsCount > 3)
                        {
                            Antmove(Ant3, Home, cells, width, height, AntsCount, entity3, Berry3);
                            if (AntsCount > 4)
                            {
                                Antmove(Ant4, Home, cells, width, height, AntsCount, entity4, Berry4);
                                if (AntsCount > 5)
                                {
                                    Antmove(Ant5, Home, cells, width, height, AntsCount, entity5, Berry5);
                                    if (AntsCount > 6)
                                    {
                                        Antmove(Ant6, Home, cells, width, height, AntsCount, entity6, Berry6);
                                        if (AntsCount > 7)
                                        {
                                            Antmove(Ant7, Home, cells, width, height, AntsCount, entity7, Berry7);
                                            if (AntsCount > 8)
                                            {
                                                Antmove(Ant8, Home, cells, width, height, AntsCount, entity8, Berry8);
                                                if (AntsCount>9)
                                                    Antmove(Ant9, Home, cells, width, height, AntsCount, entity9, Berry9);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            window.clear(sf::Color::White);
            window.draw(background);
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
            renderCells(window, cells, width, height); //�������� ������� ��������� ������ ��������
            window.draw(anthill);
            window.display();
        }
}