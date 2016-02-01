/*
 * Player.h
 *
 *  Created on: 1 févr. 2016
 *      Author: Nadhem.Dridi
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
public:
    Player(string name, string color) :
            m_name(name), m_score(0), m_color(color)
    {
    }
    const string& getColor() const;
    void setColor(const string& color);
    const string& getName() const;
    void setName(const string& name);
    void setScore(int score);
    int getScore() const;
private:
    string m_name;
    int m_score;
    string m_color;
};

#endif /* PLAYER_H_ */
