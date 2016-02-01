/*
 * Pawn.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: Nadhem.Dridi
 */

#include "Pawn.h"

const string& Pawn::getColor() const
{
    return m_color;
}

void Pawn::setColor(const string& color)
{
    m_color = color;
}

bool Pawn::isOnEchiquier() const
{
    return m_onEchiquier;
}

void Pawn::setOnEchiquier(bool onEchiquier)
{
    m_onEchiquier = onEchiquier;
}

int Pawn::getPosX() const
{
    return m_posX;
}

void Pawn::setPosX(int posX)
{
    m_posX = posX;
}

int Pawn::getPosY() const
{
    return m_posY;
}

void Pawn::setPosY(int posY)
{
    m_posY = posY;
}

void Pawn::setPos(int posX, int posY)
{
    m_posX = posX;
    m_posY = posY;
}
