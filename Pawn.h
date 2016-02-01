/*
 * Pawn.h
 *
 *  Created on: 1 févr. 2016
 *      Author: Nadhem.Dridi
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef PAWN_H_
#define PAWN_H_

/**
 *
 * Class Pawn
 *
 */

class Pawn
{
public:
    Pawn(string color, int posX, int posY) :
            m_color(color), m_posX(posX), m_posY(posY), m_onEchiquier(false)
    {

    }
    const string& getColor() const;
    void setColor(const string& color);
    bool isOnEchiquier() const;
    void setOnEchiquier(bool onEchiquier);
    /**
     * Position Management
     */
    int getPosX() const;
    void setPosX(int posX);
    int getPosY() const;
    void setPosY(int posY);
    void setPos(int posX, int posY);

private:
    string m_color;
    int m_posX;
    int m_posY;
    bool m_onEchiquier;
};

#endif /* PAWN_H_ */