/*
 * Square.h
 *
 *  Created on: 1 févr. 2016
 *      Author: Nadhem.Dridi
 */
#include <iostream>
#include <string>

#include "Pawn.h"

using namespace std;

#ifndef SQUARE_H_
#define SQUARE_H_

/**
 *
 * Class Square
 *
 */
class Square
{
public:
    Square(string color, int posX, int posY) :
            m_color(color), m_containPawn(NULL), m_posX(posX), m_posY(posY)
    {
    }
    const string& getColor() const;
    void setColor(const string& color);
    Pawn* getContainPawn();
    void setContainPawn(Pawn* containPawn);
    int getPosX() const;
    void setPosX(int posX);
    int getPosY() const;
    void setPosY(int posY);
private:
    string m_color;
    Pawn* m_containPawn;
    int m_posX, m_posY;
};
#endif /* SQUARE_H_ */
