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

bool Pawn::isChecker() const
{
    return m_checker;
}

void Pawn::setChecker(bool checker)
{
    m_checker = checker;
}

int Pawn::getPosX() const
{
    return m_posX;
}

void Pawn::setPosX(int posX)
{
    m_posX = posX;
    checkChecker();
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
    // update position
    m_posX = posX;
    m_posY = posY;
    cout << "SET POSITION" << endl;
    checkChecker();
}

void Pawn::kill()
{
    m_posX = -1;
    m_posY = -1;
}

void Pawn::checkChecker()
{
    cout << "CHECK CHECKER" << endl;
    // check if pawn attempts other player's last line
    if(m_color == "B" && m_posX == 0 && m_checker == false)
        m_checker = true;
    if(m_color == "W" && m_posX == 9 && m_checker == false)
        m_checker = true;
}
