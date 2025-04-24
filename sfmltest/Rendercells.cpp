#include "cellsclasses.h" //файл с классами и конструктором
#include "Headers.h"
void renderCells(sf::RenderWindow& window, Cell cells[][30], int width, int height, float cellSize = 20.0f, float lineThickness = 2.0f)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Верхняя граница
            if (cells[x][y].Top == CellState::Close)
            {
                const sf::Vector2f cellPos(x * cellSize, y * cellSize); //приводим координаты к типу с которым может работать SFML
                sf::RectangleShape line(sf::Vector2f(cellSize, lineThickness));
                line.setPosition(cellPos);
                line.setFillColor(sf::Color::Black);
                window.draw(line);
            }
            // Левая граница
            if (cells[x][y].Left == CellState::Close)
            {
                const sf::Vector2f cellPos(x * cellSize, y * cellSize); //приводим координаты к типу с которым может работать SFML
                sf::RectangleShape line(sf::Vector2f(lineThickness, cellSize));
                line.setPosition(cellPos);
                line.setFillColor(sf::Color::Black);
                window.draw(line);
            }
            // Правая граница
            if (cells[x][y].Right == CellState::Close)
            {
                sf::RectangleShape line(sf::Vector2f(lineThickness, cellSize));
                line.setPosition(sf::Vector2f((x + 1) * cellSize - lineThickness, y * cellSize));
                line.setFillColor(sf::Color::Black);
                window.draw(line);
            }
            // Нижняя граница
            if (cells[x][y].Bottom == CellState::Close)
            {
                sf::RectangleShape line(sf::Vector2f(cellSize, lineThickness));
                line.setPosition(sf::Vector2f(x * cellSize, (y + 1) * cellSize - lineThickness));
                line.setFillColor(sf::Color::Black);
                window.draw(line);
            }
        }
    }
}
void generatearray(Cell cells[][30], int width, int height)
{
    int startX = rand() % width;
    int startY = rand() % height;

    cells[startX][startY].Visited = true;

    //Заносим нашу ячейке в path и начинаем строить путь
    std::stack<Cell> path;
    path.push(cells[startX][startY]);

    while (!path.empty())
    {
        Cell _cell = path.top();

        //смотрим варианты, в какую сторону можно пойти
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
            //выбираем сторону из возможных вариантов
            Cell next = nextStep[rand() % nextStep.size()];

            //Открываем сторону, в которую пошли на ячейках
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
            //если пойти никуда нельзя, возвращаемся к предыдущему узлу
            path.pop();
        }
    }
}