#include "Headers.h"

void Ant::checkNew()
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

void Ant::moveTo(int p_x, int p_y)
{
    x = p_x;
    y = p_y;
    newBorn = true;
    entity.setRotation(sf::degrees(0));
}

void BadAnt::plusStep()
{
    step++;
    auto nextcord = path[step];
    x = nextcord.x;
    y = nextcord.y;
}

void BadAnt::goHome()
{
    x = 59;
    y = 39;
    hunting = false;
    step = 0;
    newBorn = true;
    entity.setRotation(sf::degrees(0));
}

void BadAnt::checkNew()
{
    if ((newBorn == true) && (path[1].x == 58))
    {
        newBorn = false;
        entity.rotate(sf::degrees(90));
    }
    else if ((newBorn == true) && (path[1].y == 38))
    {
        newBorn = false;
        entity.rotate(sf::degrees(180));
    }
    else return;
}

float BadAnt::rotateChek()
{
    float scalable = 2.0;
    if ((step > 0))
        scalable = sqrt(pow((path[step + 1].x - path[step - 1].x), 2) + pow((path[step + 1].y - path[step - 1].y), 2));
    return scalable;
}
