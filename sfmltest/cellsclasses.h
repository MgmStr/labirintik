#pragma once
enum CellState { Close, Open };
class Cell
{
public:
    int x;
    int y;
    CellState Left;
    CellState Right;
    CellState Top;
    CellState Bottom;
    bool Visited;
    Cell() :x(0), y(0), Left(Close), Right(Close), Top(Close), Bottom(Close), Visited(false) //конструктор по умолчанию, чтобы все €чейки сразу создавались закрытыми и непосещЄнными
    {
    }
};