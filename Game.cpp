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

    const vector<vector<Square*>>& getMatrix() const
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
        for (int i = 0; i < m_size; i++)
        {
            for (int j = 0; j < m_size; j++)
            {
                if (m_pawns1.size() > 0 && m_matrix[i][j]->getColor() == "B")
                {
                    m_matrix[i][j]->setContainPawn(m_pawns1.back());
                    m_matrix[i][j]->getContainPawn()->setPos(i, j);
                    m_pawns1.pop_back();
                }
                if (i >= 6 && m_matrix[i][j]->getColor() == "B"
                        && m_pawns2.size() > 0)
                {
                    m_matrix[i][j]->setContainPawn(m_pawns2.back());
                    m_matrix[i][j]->getContainPawn()->setPos(i, j);
                    m_pawns2.pop_back();
                }
            }
        }
    }

    void showMatrix()
    {
        cout << "   0   1   2   3   4   5   6   7   8   9";
        int i = 0;
        for (auto line : m_matrix)
        {
            cout << endl << "---------------------------------------" << endl;
            for (auto cell : line)
            {
                cout << "| ";
                if (cell->getContainPawn() != NULL)
                    cout
                            << (cell->getContainPawn()->getColor() == "B" ?
                                    "*" : "O") << " ";
                else
                    cout << "  ";
            }
            cout << "| " << i;
            i++;
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
    bool moveCheckerByPlayer(int srcX, int srcY, int dstX, int dstY)
    {
        if (!m_matrix[srcX][srcY]->getContainPawn()->isChecker())
            return false;
        // check positions and align of source and destination
        if (!_checkMovePositions(srcX, srcY, dstX, dstY)
                || !_checkAlign(srcX, srcY, dstX, dstY))
            return false;
        vector<pair<int, int>> l_result = _getSegment(srcX, srcY, dstX, dstY);
        vector<pair<int, int>> l_toEat;
        Pawn* l_pawn = m_matrix[srcX][srcY]->getContainPawn();
        for (auto p : l_result)
        {
            if (m_matrix[p.first][p.second]->getContainPawn()->getColor()
                    == l_pawn->getColor())
                return false;
            l_toEat.push_back(p);
        }
        _eatChecker(l_toEat);
        _movePawn(srcX, srcY, dstX, dstY);
        return true;
    }
    bool movePawnByPlayer(int srcX, int srcY, int dstX, int dstY)
    {
        //check positions and align of source and destination
        if (!_checkMovePositions(srcX, srcY, dstX, dstY)
                || !_checkAlign(srcX, srcY, dstX, dstY))
            return false;
        Pawn* l_pawn = m_matrix[srcX][srcY]->getContainPawn();
        int l_direction = l_pawn->getColor() == "W" ? -1 : 1;
        // ensure that jump is with 2 gaps
        if ((srcX + l_direction != dstX)
                || (abs(dstY - srcY) != abs(l_direction)))
            return false;
        // check that there is a pawn to eat
        _movePawn(srcX, srcY, dstX, dstY);
        return true;
    }

    bool eatPawn(int srcX, int srcY, int dstX, int dstY)
    {
        //check positions and align of source and destiny
        if (!_checkMovePositions(srcX, srcY, dstX, dstY)
                || !_checkAlign(srcX, srcY, dstX, dstY))
            return false;
        Pawn* l_pawn = m_matrix[srcX][srcY]->getContainPawn();
        // ensure that jump is with 2 gaps
        if ((abs(srcX - dstX) != 2) || (abs(dstY - srcY) != abs(2)))
            return false;
        // check that there is a pawn to eat
        if (m_matrix[(srcX + dstX) / 2][(srcY + dstY) / 2]->getContainPawn() == NULL)
            return false;
        Pawn* l_victim =
                m_matrix[(srcX + dstX) / 2][(srcY + dstY) / 2]->getContainPawn();
        // check color of pawn to eat
        if (l_pawn->getColor() == l_victim->getColor())
            return false;
        // execute action
        _eatPawn(srcX, srcY, dstX, dstY);
        return true;
    }

    bool playTour(int srcX, int srcY, int dstX, int dstY)
    {
        if (!_checkMovePositions(srcX, srcY, dstX, dstY)
                || !_checkAlign(srcX, srcY, dstX, dstY))
        {
            return false;
        }
        // get type of pawn (pawn/checker)
        bool l_isChecker = m_matrix[srcX][srcY]->getContainPawn()->isChecker();
        // check if it is a simple move or an eat
        cerr << " IS CHECKER " << l_isChecker << endl;
        bool l_isEat = abs(srcX - dstX) == 2 ? true : false;
        cerr << " IS EATING " << l_isEat << endl;
        if (l_isChecker)
            return moveCheckerByPlayer(srcX, srcY, dstX, dstY);
        else
        {
            if (l_isEat)
            {
                return eatPawn(srcX, srcY, dstX, dstY);
            }
            else
                return movePawnByPlayer(srcX, srcY, dstX, dstY);
        }
    }

private:
    /**
     * calculate all diagonals black positions
     */
    vector<pair<int, int> > _getDiagonals(int X, int Y)
    {
        int x = X, y = Y;
        vector<pair<int, int> > l_diagonals;
        while (x <= 9 && y <= 9)
        {
            l_diagonals.push_back(pair<int, int>(x++, y++));
        }
        x = X - 1;
        y = Y - 1;
        while (x >= 0 && y >= 0)
        {
            l_diagonals.push_back(pair<int, int>(x--, y--));
        }
        x = X + 1;
        y = Y - 1;
        while (x <= 9 && y >= 0)
        {
            l_diagonals.push_back(pair<int, int>(x++, y--));
        }
        x = X - 1;
        y = Y + 1;
        while (x >= 0 && y <= 9)
        {
            l_diagonals.push_back(pair<int, int>(x--, y++));
        }
#ifdef DEBUG
        for (auto v : l_diagonals)
        {
            cout << "( " << v.first << ", " << v.second << " )"<< endl;
        }
#endif
        return l_diagonals;
    }
    /**
     * check that source and destination positions are aligned
     */
    bool _checkAlign(int srcX, int srcY, int dstX, int dstY)
    {
        vector<pair<int, int>> l_diagonals = _getDiagonals(srcX, srcY);
        if (find(l_diagonals.begin(), l_diagonals.end(),
                pair<int, int>(dstX, dstY)) != l_diagonals.end())
            return true;
        return false;
    }
    /**
     * check that the source and destination positions are valid
     */
    bool _checkMovePositions(int srcX, int srcY, int dstX, int dstY)
    {
        // check that given position's square contain a pawn
        Pawn* l_pawn = m_matrix[srcX][srcY]->getContainPawn();
        if (l_pawn == NULL)
            return false;
        // Check that destination position is empty
        if ((m_matrix[dstX][dstY]->getContainPawn() != NULL)
                && (m_matrix[dstX][dstY]->getColor() == "B"))
            return false;
        return true;
    }
    /**
     * eat pawn between source and destination position
     */
    void _eatPawn(int srcX, int srcY, int dstX, int dstY)
    {
        Pawn* l_victim =
                m_matrix[(srcX + dstX) / 2][(srcY + dstY) / 2]->getContainPawn();
        // move pawn
        _movePawn(srcX, srcY, dstX, dstY);
        // exit victim
        l_victim->kill();
        vector<Pawn*> *l_pile =
                l_victim->getColor() == "W" ? &m_pawns1 : &m_pawns2;
        l_pile->push_back(l_victim);
        // empty victim's square
        m_matrix[(srcX + dstX) / 2][(srcY + dstY) / 2]->empty();
    }
    /**
     * eat pawns after checker movement
     */
    void _eatChecker(vector<pair<int, int>> l_toEat)
    {
        for (auto p : l_toEat)
        {
            Pawn* l_victim = m_matrix[p.first][p.second]->getContainPawn();
            l_victim->kill();
            vector<Pawn*> *l_pile =
                    l_victim->getColor() == "W" ? &m_pawns1 : &m_pawns2;
            l_pile->push_back(l_victim);
            // empty victim's square
            m_matrix[p.first][p.second]->empty();
        }
    }
    /**
     * move pawn from source and destination position
     */
    void _movePawn(int srcX, int srcY, int dstX, int dstY)
    {
        cout << "get pointer" << endl;
        Pawn* l_pawn = m_matrix[srcX][srcY]->getContainPawn();
        // move pawn
        cout << "set pawn pos" << endl;
        l_pawn->setPos(dstX, dstY);
        cout << "square takes pawn" << endl;
        m_matrix[dstX][dstY]->setContainPawn(l_pawn);
        // empty pawn's old square
        cout << "empty last square" << endl;
        m_matrix[srcX][srcY]->empty();
    }
    /**
     * get segment squares between source and destination points
     */
    vector<pair<int, int>> _getSegment(int srcX, int srcY, int dstX, int dstY)
    {
        vector<pair<int, int>> l_result;
        pair<int, int> l_tmp1(srcX, srcY), l_tmp2(dstX, dstY);
        short l_signX, l_signY;
        l_signX = srcX < dstY ? 1 : -1;
        l_signY = srcY < dstY ? 1 : -1;
        while ((l_tmp1.first + l_signX) != l_tmp2.first)
        {
            l_tmp1.first += l_signX;
            l_tmp1.second += l_signY;
            l_result.push_back(l_tmp1);
        }
#ifdef DEBUG
        for (auto l : l_result)
        {
            cout << l.first << "; " << l.second << endl;
        }
#endif
        return l_result;
    }
    int m_size;
    vector<vector<Square*>> m_matrix;
    Player m_player1;
    Player m_player2;
    vector<Pawn*> m_pawns1;
    vector<Pawn*> m_pawns2;
};

int main()
{
    Game GAME(10);
    GAME.initMatrix();
    GAME.showMatrix();
    int srcX, srcY, dstX, dstY;
    string command;
    while (1)
    {
        cin >> srcX >> srcY >> dstX >> dstY;
        bool rslt = GAME.playTour(srcX, srcY, dstX, dstY);
        if (!rslt)
            cerr << "ERROR When moving " << endl;
        cout << string(100, '\n');
        GAME.showMatrix();
    }
    //GAME._getSegment(8, 0, 0, 8);
// GAME.getDiagonals(0,8);

}

