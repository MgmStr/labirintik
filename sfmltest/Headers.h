#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include "cellsclasses.h"

void renderCells(sf::RenderWindow& window, Cell cells[][40], int width, int height); //отрисовка лабиринта
void generatearray(Cell cells[][40], int width, int height); //создание лабиринта
void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][40], int width, int height, int& count, sf::Sprite& ent, sf::Sprite& berry); //логика движения
void initAnt(Cell cells[][40], Ant Ant, sf::Sprite& mob);//инициализация спрайтов
std::vector<sf::Vector2i> findPath(Cell cells[][40], int width, int height, sf::Vector2i start, sf::Vector2i end);//функция поиска пути
std::vector<std::vector<bool>> mazeToGrid(Cell cells[][40], int width, int height);