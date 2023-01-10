// Eloyd Lee Gonzales

#include <iostream>
#include "TicTacToeGame.h"
#include "NeuralNetwork.h"
#include "AIAgent.h"
#include <eigen3/Eigen/Eigen>
#include <algorithm>
#include <fstream>
#include <thread>

void playGame(TicTacToeGame game, AIAgent& player1, AIAgent& player2)
{
    game.PlayGame(player1, player2);
}

int main()
{
    std::cout << "hello \n";

    const int numberOfAI{ 100 };
    const int numberOfGenerations{ 5000 };
    const int numberOfSavedAgents{ numberOfAI };

    AIAgent players[numberOfAI];
    TicTacToeGame game;

    std::vector<std::thread> threads;

    // load Agent's brains
    for (size_t i = 0; i < numberOfSavedAgents; i++)
    {
        if (!players[i].LoadBrain("savedBrains/" + to_string(i) + ".txt"))
        {
            players[i].SetBrain();
            i = numberOfSavedAgents;
        }
        
    }
    

    for (size_t i = 0; i < numberOfGenerations; i++)
    {
        // have each AIAgent play 2 games against every other AIAgent
        for (size_t i = 0; i < numberOfAI - 1; i++)
        {
            for (size_t j = i + 1; j < numberOfAI; j++)
            {
                // in the first game players[i] goes first in the second players[j] goes first
                // threads.push_back(std::thread(playGame, game, std::ref(players[i]), std::ref(players[j])));
                // threads.push_back(std::thread(playGame, game, std::ref(players[j]), std::ref(players[i])));
                game.PlayGame(players[i], players[j]);
                game.PlayGame(players[j], players[i]);
            }
        }
        for (auto &th : threads)
        {
            th.join();
        }
        threads.clear();
        // sorts players by number of wins
        sort(std::begin(players), std::end(players));

        for (size_t i = 0; i < numberOfAI; i++)
        {
            std::cout << players[i].GetWins() << "\n";
            players[i].ResetWins();
        }
        
        // todo make from 0 to 90% mutate less and less
        for (size_t i = 0; i < floor(numberOfAI * 0.5); i++)
        {
            players[i].AdjustBrain(1 - i / numberOfAI);
        }
    }

    // have each AIAgent play 2 games against every other AIAgent
    for (size_t i = 0; i < numberOfAI - 1; i++)
    {
        for (size_t j = i + 1; j < numberOfAI; j++)
        {
            // in the first game players[i] goes first in the second players[j] goes first
            game.PlayGame(players[i], players[j]);
            game.PlayGame(players[j], players[i]);
        }
    }
    // sorts players by number of wins
    sort(std::begin(players), std::end(players));

    // save Agent's brains
    for (size_t i = 0; i < numberOfSavedAgents; i++)
    {
        players[i].SaveBrain("savedBrains/" + to_string(i) + ".txt");
    }
    

    do
    {
        game.ResetGame();
        RowVector input(9);
        int playerSelection{ 0 };
        do
        {
            game.PrintBoard();
            std::cout << game.GetCurrentPlayer() << "'s turn \n";

            cin >> playerSelection;

            game.NextMove(playerSelection);

            game.GetBoard(input);
            game.NextMove(players[numberOfAI - 1].GetMove(input));
        } while (!game.IsGameOver());
        // display winner
        game.PrintBoard();
        std::cout << game.GetWinner() << " wins\n";
    } while (true);
    
    

    

    return 0;
}