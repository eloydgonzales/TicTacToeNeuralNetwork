// Eloyd Lee Gonzales

#include <iostream>
#include "TicTacToeGame.h"
#include "NeuralNetwork.h"
#include "AIAgent.h"
#include <eigen3/Eigen/Eigen>
#include <algorithm>

int main()
{
    std::cout << "hello \n";

    AIAgent player1, player2;
    AIAgent players[10];
    RowVector input(9);
    

    TicTacToeGame game;

    //game.PlayGame(player1, player2);
    game.PlayGame(players[1], players[2]);

    return 0;
}