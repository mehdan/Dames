#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Player.h"
#include "Pawn.h"
#include "Square.h"

using namespace std;

/**
 *
 * Class Game
 *
 */

class Game
{
public:
    Game(int taille) :
            m_player1("Player1", "B"), m_player2("Player2", "W")
    {
        m_size = 10; // TODO : The game's default size is 10
        // prepare pawns
        for (int i = 0; i < (2 * m_size); i++)
        {
            Pawn* l_pawnW = new Pawn("W", 0, 0);
            Pawn* l_pawnB = new Pawn("B", 0, 0);
            m_pawns1.push_back(l_pawnB);
            m_pawns2.push_back(l_pawnW);
        }
        // create map
        for (int i = 0; i < m_size; i++)
        {
            vector<Square*> l_line;
            for (int j = 0; j < m_size; j++)
            {
                string l_color = (i + j) % 2 == 0 ? "W" : "B";
                Square* c = new Square(l_color, i, j);
                l_line.push_back(c);
            }
            m_matrix.push_back(l_line);
        }
    }
    /**
     * Game Management
     */

    const vector<vector<Square*> >& getMatrix() const
    {
        return m_matrix;
    }

    void setMatrix(const vector<vector<Square*> >& matrix)
    {
        m_matrix = matrix;
    }

    int getTaille() const
    {
        return m_size;
    }

    void setTaille(int taille)
    {
        m_size = taille;
    }

    void initMatrix()
    {
        // Initialization of game's pawn matrix
        for (int i=0; i < m_size; i++)
        {
            for (int j=0; j < m_size;j++)
            {
                if (m_pawns1.size()>0 && m_matrix[i][j]->getColor() == "B")
                {
                    m_matrix[i][j]->setContainPawn(m_pawns1.back());
                    m_matrix[i][j]->getContainPawn()->setPos(i,j);
                    m_pawns1.pop_back();
                }
                if (i >=6 && m_matrix[i][j]->getColor() == "B" && m_pawns2.size()>0)
                {
                    m_matrix[i][j]->setContainPawn(m_pawns2.back());
                    m_matrix[i][j]->getContainPawn()->setPos(i,j);
                    m_pawns2.pop_back();
                }
            }
        }
    }

    void showMatrix()
    {
        for (auto line : m_matrix)
        {
            cout << endl << "---------------------------------------" << endl;
            for (auto cell : line)
            {
                cout << "| " ;
                if (cell->getContainPawn() != NULL)
                cout << (cell->getContainPawn()->getColor() == "B" ? "*" : "O") << " " ;
                else
                cout << "  ";
            }
            cout << "|";
        }
        cout << endl << "---------------------------------------" << endl;
    }
        /**
         * Pawns Management
         */
        const vector<Pawn*> getPawns1() const
        {
            return m_pawns1;
        }

        void setPawns1(const vector<Pawn*>& pawns1)
        {
            m_pawns1 = pawns1;
        }

        const vector<Pawn*>& getPawns2() const
        {
            return m_pawns2;
        }

        void setPawns2(const vector<Pawn*>& pawns2)
        {
            m_pawns2 = pawns2;
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
        int m_size;
        vector<vector<Square*>> m_matrix;
        Player m_player1;
        Player m_player2;
        vector<Pawn*> m_pawns1;
        vector<Pawn*> m_pawns2;

    };

    int main()
    {
        std::string name;
        std::cout << "Enter chessboard's size :\n";
        getline(std::cin, name);
        std::cout << "Boff anyway.. size will be 10, it's better man!" << "!\n";
        Game GAME(10);
        GAME.initMatrix();
        GAME.showMatrix();

    }
