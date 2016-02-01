/*
 * Square.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: Nadhem.Dridi
 */

#include "Square.h"

const string& Square::getColor() const
{
    return m_color;
}

void Square::setColor(const string& color)
{
    m_color = color;
}

Pawn* Square::getContainPawn()
{
    return m_containPawn;
}

void Square::setContainPawn(Pawn* containPawn)
{
    m_containPawn = containPawn;
}

int Square::getPosX() const
{
    return m_posX;
}

void Square::setPosX(int posX)
{
    m_posX = posX;
}

int Square::getPosY() const
{
    return m_posY;
}

void Square::setPosY(int posY)
{
    m_posY = posY;
}

