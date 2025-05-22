#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include "cellsclasses.h"

void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height); //��������� ���������
void generatearray(Cell cells[][30], int width, int height); //�������� ���������
void Antmove(Ant& Ant, sf::Vector2i& home, Cell cells[][30], int width, int height, int& count, sf::Sprite& ent, sf::Sprite& berry); //������ ��������
void initAnt(Cell cells[][30], Ant Ant, sf::Sprite& mob);//������������� ��������
std::vector<sf::Vector2i> findPath(Cell cells[][30], int width, int height, sf::Vector2i start, sf::Vector2i end);//������� ������ ����
std::vector<std::vector<bool>> mazeToGrid(Cell cells[][30], int width, int height);