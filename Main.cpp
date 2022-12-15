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
    RowVector input(9);
    

    TicTacToeGame game;
    int playerSelection {0};
    double output[9]{0, 0, 0, 0, 0, 0, 0, 0, 0};
    double largestVal{-100.0};

    do
    {
        game.PrintBoard();
        std::cout << game.GetCurrentPlayer() << "'s turn \n";

        game.GetBoard(input);

        game.NextMove(player1.GetMove(input));

        game.PrintBoard();
        std::cout << game.GetCurrentPlayer() << "'s turn \n";
        game.GetBoard(input);

        game.NextMove(player1.GetMove(input));
    } while (!game.IsGameOver());

    // display winner
    game.PrintBoard();
    std::cout << game.GetWinner() << " wins\n";

    return 0;
}