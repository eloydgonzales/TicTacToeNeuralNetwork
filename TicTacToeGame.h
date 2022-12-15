// Eloyd Lee Gonzales

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <iostream>
#include <eigen3/Eigen/Eigen>

typedef Eigen::RowVectorXd RowVector;

class TicTacToeGame
{
public:
    enum Space {none, xplayer, oplayer};
    
    TicTacToeGame(/* args */);
    ~TicTacToeGame();

    bool NextMove(int playerSelection);
    void PrintBoard();

    Space GetCurrentPlayer(){return currentPlayer;};
    void GetBoard(RowVector& board);
    bool IsGameOver(){return gameOver;};
    Space GetWinner(){return winner;};
private:
    Space board[9]{none, none, none, none, none, none, none, none, none};
    Space currentPlayer {xplayer};
    Space winner {none};
    bool gameOver {false};

    bool CheckForWin();
};

TicTacToeGame::TicTacToeGame(/* args */)
{
}

TicTacToeGame::~TicTacToeGame()
{
}

bool TicTacToeGame::NextMove(int playerSelection)
{
    if (gameOver)
    {
        return false;
    }
    
    if (board[playerSelection] == none)
    {
        board[playerSelection] = currentPlayer;
        gameOver = CheckForWin();
        if (gameOver)
        {
            winner = currentPlayer;
            return false;
        }
        if (currentPlayer == xplayer)
        {
            currentPlayer = oplayer;
        }
        else
        {
            currentPlayer = xplayer;
        }
        return true;
    }
    return false;
}

bool TicTacToeGame::CheckForWin()
{
    for (std::size_t i = 0; i < 9; i += 3)
    {
        if (currentPlayer == board[i] && currentPlayer == board[i + 1] && currentPlayer == board[i + 2])
        {
            return true;
        }
    }
    for (std::size_t i = 0; i < 3; i++)
    {
        if (currentPlayer == board[i] && currentPlayer == board[i + 3] && currentPlayer == board[i + 6])
        {
            return true;
        }
    }
    if (currentPlayer == board[0] && currentPlayer == board[4] && currentPlayer == board[8])
    {
        return true;
    }
    if (currentPlayer == board[2] && currentPlayer == board[4] && currentPlayer == board[6])
    {
        return true;
    }
    return false;
}

void TicTacToeGame::PrintBoard()
{
    for (std::size_t i = 0; i < 9; i += 3)
    {
        std::cout << board[i] << board[i + 1] << board[i + 2] << std::endl;
    }
    
}

void TicTacToeGame::GetBoard(RowVector& board)
{
    for (size_t i = 0; i < 9; i++)// todo fix bounds overflow
    {
        if (this->board[i] == currentPlayer)
        {
            board[i] = 1;
        }
        else if (this->board[i] == none)
        {
            board[i] = 0;
        }
        else
        {
            board[i] = -1;
        }
    }
    
}

#endif