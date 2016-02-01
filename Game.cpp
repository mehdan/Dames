#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *
 * Class Player
 *
 */

class Player
{
public:
    Player(string name, string color) :
            m_name(name), m_score(0), m_color(color)
    {
    }

    const string& getColor() const
    {
        return m_color;
    }

    void setColor(const string& color)
    {
        m_color = color;
    }

    const string& getName() const
    {
        return m_name;
    }

    void setName(const string& name)
    {
        m_name = name;
    }

    int getScore() const
    {
        return m_score;
    }

    void setScore(int score)
    {
        m_score = score;
    }

private:
    string m_name;
    int m_score;
    string m_color;
};

/**
 *
 * Class Pion
 *
 */

class Pion
{
public:
    Pion(string color, int posX, int posY) :
            m_color(color), m_posX(posX), m_posY(posY), m_onEchiquier(false)
    {

    }
    const string& getColor() const
    {
        return m_color;
    }

    void setColor(const string& color)
    {
        m_color = color;
    }

    bool isOnEchiquier() const
    {
        return m_onEchiquier;
    }

    void setOnEchiquier(bool onEchiquier)
    {
        m_onEchiquier = onEchiquier;
    }

    /**
     * Position Management
     */

    int getPosX() const
    {
        return m_posX;
    }

    void setPosX(int posX)
    {
        m_posX = posX;
    }

    int getPosY() const
    {
        return m_posY;
    }

    void setPosY(int posY)
    {
        m_posY = posY;
    }

    void setPos(int posX, int posY)
    {
        m_posX = posX;
        m_posY = posY;
    }

private:
    string m_color;
    int m_posX;
    int m_posY;
    bool m_onEchiquier;
};

/**
 *
 * Class Case
 *
 */
class Case
{
public:
    const string& getColor() const
    {
        return m_color;
    }

    void setColor(const string& color)
    {
        m_color = color;
    }

    Pion* getContainPion()
    {
        return m_containPion;
    }

    void setContainPion(Pion* containPion)
    {
        m_containPion = containPion;
    }

private:
    string m_color;
    Pion* m_containPion;
};
/**
 *
 * Class Game
 *
 */

class Game
{
public:
    Game(int taille) : m_player1("Player1", "B"), m_player2("Player2", "W")
{
        // create map
        m_taille = (taille % 2) != 0 ? taille -1 : taille;
        for (int i =0; i< m_taille; i++)
        {
            for (int j=0; j< m_taille; j++)
            {

            }
        }
}
    /**
     * Game Management
     */

    const vector<vector<Case*> >& getMatrix() const
    {
        return m_matrix;
    }

    void setMatrix(const vector<vector<Case*> >& matrix)
    {
        m_matrix = matrix;
    }

    int getTaille() const
    {
        return m_taille;
    }

    void setTaille(int taille)
    {
        m_taille = taille;
    }

    void initMatrix()
    {
        // Initialization of game matrix
    }
    /**
     * Pions Management
     */
    const vector<Pion>& getPions1() const
    {
        return m_pions1;
    }

    void setPions1(const vector<Pion>& pions1)
    {
        m_pions1 = pions1;
    }

    const vector<Pion>& getPions2() const
    {
        return m_pions2;
    }

    void setPions2(const vector<Pion>& pions2)
    {
        m_pions2 = pions2;
    }
    /**
     * Players Management
     */
    const Player& getPlayer1() const
    {
        return m_player1;
    }

    void setPlayer1(const Player& player1)
    {
        m_player1 = player1;
    }

    const Player& getPlayer2() const
    {
        return m_player2;
    }

    void setPlayer2(const Player& player2)
    {
        m_player2 = player2;
    }

private:
    int m_taille;
    vector<vector<Case*>> m_matrix;
    Player m_player1;
    Player m_player2;
    vector<Pion> m_pions1;
    vector<Pion> m_pions2;


};

int main()
{
    std::string name;
    std::cout << "Taille de l'echiquier \n";
    getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";
}
