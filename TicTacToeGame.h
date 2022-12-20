// Eloyd Lee Gonzales

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <iostream>
#include <eigen3/Eigen/Eigen>
#include "AIAgent.h"

typedef Eigen::RowVectorXd RowVector;

class TicTacToeGame
{
public:
    enum Space {none, xplayer, oplayer};
    
    TicTacToeGame(/* args */);
    ~TicTacToeGame();

    void NextMove(int playerSelection);
    void PrintBoard();

    Space GetCurrentPlayer(){return currentPlayer;};
    void GetBoard(RowVector& board);
    bool IsGameOver(){return gameOver;};
    Space GetWinner(){return winner;};
    void PlayGame(AIAgent &player1, AIAgent &player2);
    void ResetGame();
private:
    Space board[9]{none, none, none, none, none, none, none, none, none};
    Space currentPlayer {xplayer};
    Space winner {none};
    bool gameOver {false};
    int moves {0};

    bool CheckForWin();
};

TicTacToeGame::TicTacToeGame(/* args */)
{
}

TicTacToeGame::~TicTacToeGame()
{
}

void TicTacToeGame::NextMove(int playerSelection)
{
    if (gameOver)
    {
        return;
    }
    
    if (board[playerSelection] == none)
    {
        board[playerSelection] = currentPlayer;
        moves++;

        gameOver = CheckForWin();
        if (gameOver)
        {
            winner = currentPlayer;
            return;
        }

        // check for tie
        if (moves >= 9)
        {
            gameOver = true;
            return;
        }

        // switch current player
        if (currentPlayer == xplayer)
        {
            currentPlayer = oplayer;
        }
        else
        {
            currentPlayer = xplayer;
        }
    }
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

void TicTacToeGame::PlayGame(AIAgent &player1, AIAgent &player2)
{
    ResetGame();
    RowVector input(9);
    do
    {
        // PrintBoard();
        // std::cout << currentPlayer << "'s turn \n";

        GetBoard(input);

        if (currentPlayer == 1)
        {
            NextMove(player1.GetMove(input));
        }
        else
        {
            NextMove(player2.GetMove(input));
        }
    } while (!IsGameOver());

    // update wins
    if (winner == 1)
    {
        player1.IncrementWins();
    }
    else
    {
        player2.IncrementWins();
    }
    

    // display winner
    // PrintBoard();
    // std::cout << winner << " wins\n";
}

void TicTacToeGame::ResetGame()
{
    for (size_t i = 0; i < 9; i++)
    {
        board[i] = none;
    }
    currentPlayer = xplayer;
    winner = none;
    gameOver = false;
    moves = 0;
}

#endif