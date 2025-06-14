#include "Headers.h"
void renderCells(sf::RenderWindow& window, Cell cells[][40], int width, int height)
{
    int cellSize = 20;
    int lineThickness = 2;
    sf::Texture grass("grasstexture.png");
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // ������� �������
            if (cells[x][y].Top == CellState::Close)
            {
                const sf::Vector2f cellPos(x * cellSize, y * cellSize); //�������� ���������� � ���� � ������� ����� �������� SFML
                sf::Sprite line(grass);
                line.setTextureRect(sf::IntRect({0,0}, {cellSize, lineThickness}));
                line.setPosition(cellPos);
                window.draw(line);
            }
            // ����� �������
            if (cells[x][y].Left == CellState::Close)
            {
                const sf::Vector2f cellPos(x * cellSize, y * cellSize); //�������� ���������� � ���� � ������� ����� �������� SFML
                sf::Sprite line(grass);
                line.setTextureRect(sf::IntRect({ 0, 0 }, { lineThickness, cellSize }));
                line.setPosition(cellPos);
                window.draw(line);
            }
            // ������ �������
            if (cells[x][y].Right == CellState::Close)
            {
                sf::Sprite line(grass);
                line.setTextureRect(sf::IntRect({ 0, 0 }, { lineThickness, cellSize }));
                line.setPosition(sf::Vector2f((x + 1) * cellSize - lineThickness, y * cellSize));
                window.draw(line);
            }
            // ������ �������
            if (cells[x][y].Bottom == CellState::Close)
            {
                sf::Sprite line(grass);
                line.setTextureRect(sf::IntRect({ 0,0 }, { cellSize, lineThickness }));
                line.setPosition(sf::Vector2f(x * cellSize, (y + 1) * cellSize - lineThickness));
                window.draw(line);
            }
        }
    }
}
void generatearray(Cell cells[][40], int width, int height)
{
    //�������� ������ ������ ������ ������ ��������
    int startX = rand() % width;
    int startY = rand() % height;

    cells[startX][startY].Visited = true;

    //������� ���� ������ � path � �������� ������� ����
    std::stack<Cell> path;
    path.push(cells[startX][startY]);

    while (!path.empty())
    {
        Cell _cell = path.top();

        //������� ��������, � ����� ������� ����� �����
        std::vector<Cell> nextStep;
        if (_cell.x > 0 && (cells[_cell.x - 1][_cell.y].Visited == false))
            nextStep.push_back(cells[_cell.x - 1][_cell.y]);
        if (_cell.x < width - 1 && (cells[_cell.x + 1][_cell.y].Visited == false))
            nextStep.push_back(cells[_cell.x + 1][_cell.y]);
        if (_cell.y > 0 && (cells[_cell.x][_cell.y - 1].Visited == false))
            nextStep.push_back(cells[_cell.x][_cell.y - 1]);
        if (_cell.y < height - 1 && (cells[_cell.x][_cell.y + 1].Visited == false))
            nextStep.push_back(cells[_cell.x][_cell.y + 1]);

        if (!nextStep.empty())
        {
            //�������� ������� �� ��������� ���������
            Cell next = nextStep[rand() % nextStep.size()];

            //��������� �������, � ������� ����� �� �������
            if (next.x != _cell.x)
            {
                if (_cell.x > next.x)
                {
                    cells[_cell.x][_cell.y].Left = CellState::Open;
                    cells[next.x][next.y].Right = CellState::Open;
                }
                else
                {
                    cells[_cell.x][_cell.y].Right = CellState::Open;
                    cells[next.x][next.y].Left = CellState::Open;
                }
            }
            if (next.y != _cell.y)
            {
                if (_cell.y - next.y > 0)
                {
                    cells[_cell.x][_cell.y].Top = CellState::Open;
                    cells[next.x][next.y].Bottom = CellState::Open;
                }
                else
                {
                    cells[_cell.x][_cell.y].Bottom = CellState::Open;
                    cells[next.x][next.y].Top = CellState::Open;
                }
            }
            cells[next.x][next.y].Visited = true;
            path.push(next);
        }
        else
        {
            //���� ����� ������ ������, ������������ � ����������� ����
            path.pop();
        }
    }
}