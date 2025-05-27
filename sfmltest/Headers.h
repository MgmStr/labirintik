#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include "cellsclasses.h"

void renderCells(sf::RenderWindow& window, Cell cells[][40], int width, int height); //��������� ���������
void generatearray(Cell cells[][40], int width, int height); //�������� ���������
void Antmove(Ant& Ant, sf::Vector2i home, Cell cells[][40], int width, int height, int& count, sf::Sprite& berry); //������ ��������
void initAnt(Cell cells[][40], Ant Ant, sf::Sprite& mob);//������������� ��������
void initAnt(Cell cells[][40], BadAnt& Ant);
std::vector<sf::Vector2i> findPath(Cell cells[][40], int width, int height, sf::Vector2i start, sf::Vector2i end);//������� ������ ����
std::vector<std::vector<bool>> mazeToGrid(Cell cells[][40], int width, int height);
void War(Ant ants[], BadAnt enemyies[], Cell cells[][40], int width, int height, int& count, sf::Vector2i home);