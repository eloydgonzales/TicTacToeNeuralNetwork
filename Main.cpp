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

    const int numberOfAI{ 10 };
    const int numberOfGenerations{ 10 };

    AIAgent players[numberOfAI];
    TicTacToeGame game;

    for (size_t i = 0; i < numberOfGenerations; i++)
    {
        for (size_t i = 0; i < numberOfAI - 1; i++)
        {
            for (size_t j = i + 1; j < numberOfAI; j++)
            {
                game.PlayGame(players[i], players[j]);
                game.PlayGame(players[j], players[i]);
            }
        }
        sort(std::begin(players), std::end(players));// the problem

        for (size_t i = 0; i < numberOfAI; i++)
        {
            std::cout << players[i].GetWins() << "\n";
            players[i].ResetWins();
        }
        
        for (size_t i = 0; i < numberOfAI / 2; i++)
        {
            players[i].AdjustBrain(0.1);
        }
    }
    return 0;
}