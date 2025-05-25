#include "Headers.h"


std::vector<std::vector<bool>> mazeToGrid(Cell cells[][40], int width, int height) 
{
    std::vector<std::vector<bool>> grid(height * 2 + 1, std::vector<bool>(width * 2 + 1, false));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int gridX = x * 2 + 1;
            int gridY = y * 2 + 1;
            grid[gridY][gridX] = true; // Клетка всегда проходима

            // Проверяем стенки
            if (cells[x][y].Top == Open) 
                grid[gridY - 1][gridX] = true;
            if (cells[x][y].Bottom == Open) 
                grid[gridY + 1][gridX] = true;
            if (cells[x][y].Left == Open) 
                grid[gridY][gridX - 1] = true;
            if (cells[x][y].Right == Open) 
                grid[gridY][gridX + 1] = true;
        }
    }
    return grid;
}

std::vector<sf::Vector2i> findPath(Cell cells[][40], int width, int height, sf::Vector2i start, sf::Vector2i end) 
{
    // Преобразуем лабиринт в сетку
    auto grid = mazeToGrid(cells, width, height);

    // Масштабируем координаты
    sf::Vector2i scaledStart(start.x * 2 + 1, start.y * 2 + 1);
    sf::Vector2i scaledEnd(end.x * 2 + 1, end.y * 2 + 1);

    // Направления движения (вверх, вниз, влево, вправо)
    const std::vector<sf::Vector2i> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Подготовка данных для волнового алгоритма
    std::vector<std::vector<int>> wave(height * 2 + 1, std::vector<int>(width * 2 + 1, -1));
    std::queue<sf::Vector2i> queue;

    wave[scaledStart.y][scaledStart.x] = 0;
    queue.push(scaledStart);

    // Распространение волны
    while (!queue.empty()) 
    {
        auto current = queue.front();
        queue.pop();
        if (current == scaledEnd)
            break;
        for (const auto& dir : directions) 
        {
            sf::Vector2i next(current.x + dir.x, current.y + dir.y);
            // Проверяем границы и проходимость
            if (next.x >= 0 && next.y >= 0 && next.x < grid[0].size() && next.y < grid.size() && grid[next.y][next.x] && wave[next.y][next.x] == -1) 
            {
                wave[next.y][next.x] = wave[current.y][current.x] + 1;
                queue.push(next);
            }
        }
    }

    // Восстановление пути (если он есть)
    std::vector<sf::Vector2i> path;
    if (wave[scaledEnd.y][scaledEnd.x] == -1) 
        return path;
    sf::Vector2i current = scaledEnd;
    path.push_back({ current.x / 2, current.y / 2 });

    while (current != scaledStart) 
    {
        for (const auto& dir : directions) 
        {
            sf::Vector2i prev(current.x + dir.x, current.y + dir.y);

            if (prev.x >= 0 && prev.y >= 0 && prev.x < grid[0].size() && prev.y < grid.size() && wave[prev.y][prev.x] == wave[current.y][current.x] - 1) 
            {
                current = prev;
                if (current.x % 2 == 1 && current.y % 2 == 1) 
                    path.push_back({ current.x / 2, current.y / 2 });
                break;
            }
        }
    }
    std::reverse(path.begin(), path.end());
    return path;
}