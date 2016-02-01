/*
 * Player.cpp
 *
 *  Created on: 1 févr. 2016
 *      Author: Nadhem.Dridi
 */

#include "Player.h"

/**
 *
 * Class Player
 *
 */

const string& Player::getColor() const
{
    return m_color;
}

void Player::setColor(const string& color)
{
    m_color = color;
}

const string& Player::getName() const
{
    return m_name;
}

void Player::setName(const string& name)
{
    m_name = name;
}

int Player::getScore() const
{
    return m_score;
}

void Player::setScore(int score)
{
    m_score = score;
}
