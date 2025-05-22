#include "Headers.h"

void Ant::checkNew()
{
    {
        if ((newBorn == true) && (path[1].x == 1))
        {
            newBorn = false;
            entity.rotate(sf::degrees(90));
        }
        else if ((newBorn == true) && (path[1].y == 1))
        {
            newBorn = false;
            entity.rotate(sf::degrees(180));
        }
        else return;
    }
}

void Ant::plusStep()
{
     step++;
     auto nextcord = path[step];
     x = nextcord.x;
     y = nextcord.y;
}

void Ant::zeroStep()
{
    step = 0;
    findingFood = false;
    Satiety = false;
}

float Ant::rotateChek()
{
    float scalable = 2.0;
    if ((step > 0))
        scalable = sqrt(pow((path[step + 1].x - path[step - 1].x), 2) + pow((path[step + 1].y - path[step - 1].y), 2));
    return scalable;
}
