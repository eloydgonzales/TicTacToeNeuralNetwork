// Eloyd Lee Gonzales

#include <iostream>
#include "TicTacToeGame.h"
#include "NeuralNetwork.h"
#include <eigen3/Eigen/Eigen>
#include <algorithm>

//enum Space {none, xplayer, oplayer};

// void PrintBoard(Space b[9]);
// bool CheckForWin(Space b[9], Space currentPlayer);

int main()
{
    std::cout << "hello \n";

    NeuralNetwork net({9, 15, 15, 9}, 0.05, NeuralNetwork::Activation::SIGMOID);
    NeuralNetwork net2({9, 15, 15, 9}, 0.05, NeuralNetwork::Activation::SIGMOID);
    RowVector input(9);
    // input[1] = -1;

    // for (size_t i = 0; i < 9; i++)
    // {
    //     std::cout << input[i] << "\n";
    // }
    
    // net.forward(input);

    // for (size_t i = 0; i < 9; i++)
    // {
    //     std::cout << net.output(i) << "\n";
    // }

    // std::cout << "\nadjust\n";

    // net.AdjustWeights(0.1, 1.1);

    // net.forward(input);

    // for (size_t i = 0; i < 9; i++)
    // {
    //     std::cout << net.output(i) << "\n";
    // }
    

    TicTacToeGame game;
    int playerSelection {0};
    double output[9]{0, 0, 0, 0, 0, 0, 0, 0, 0};
    double largestVal{-100.0};

    do
    {
        game.PrintBoard();
        std::cout << game.GetCurrentPlayer() << "'s turn \n";

        //std::cin >> playerSelection;

        //game.NextMove(playerSelection);

        game.GetBoard(input);
        
        net.forward(input);

        largestVal = -100.0;
        for (size_t i = 0; i < 9; i++)
        {
            output[i] = net.output(i);
            // find the highest output to an empty space
            if (output[i] > largestVal && input[i] * input[i] < 0.00001)
            {
                largestVal = output[i];
                playerSelection = i;
            }
            
        }
        game.NextMove(playerSelection);

        game.PrintBoard();
        std::cout << game.GetCurrentPlayer() << "'s turn \n";
        game.GetBoard(input);
        
        net2.forward(input);

        largestVal = -100.0;
        for (size_t i = 0; i < 9; i++)
        {
            output[i] = net2.output(i);
            // find the highest output to an empty space
            if (output[i] > largestVal && input[i] * input[i] < 0.00001)
            {
                largestVal = output[i];
                playerSelection = i;
            }
            
        }
        game.NextMove(playerSelection);
    } while (!game.IsGameOver());

    // display winner
    game.PrintBoard();
    std::cout << game.GetWinner() << " wins\n";

    // Space board[9]{none, none, none, none, none, none, none, none, none};
    // int playerSelection {0};
    // Space currentPlayer {xplayer};
    // bool gameOver {false};

    // do
    // {
    //     PrintBoard(board);
    //     std::cout << currentPlayer << "'s turn \n";

    //     std::cin >> playerSelection;

    //     if (board[playerSelection] == none)
    //     {
    //         board[playerSelection] = currentPlayer;
    //         if (CheckForWin(board, currentPlayer))
    //         {
    //             std::cout << currentPlayer << " Wins \n";
    //             gameOver = true;
    //         }
    //         if (currentPlayer == xplayer)
    //         {
    //             currentPlayer = oplayer;
    //         }
    //         else
    //         {
    //             currentPlayer = xplayer;
    //         }
    //     }
    // } while (!gameOver);
    

    
    
    
    return 0;
}

// void PrintBoard(Space b[9])
// {
//     for (size_t i = 0; i < 9; i += 3)
//     {
//         std::cout << b[i] << b[i + 1] << b[i + 2] << std::endl;
//     }
    
// }

// bool CheckForWin(Space b[9], Space currentPlayer)
// {
//     for (size_t i = 0; i < 9; i += 3)
//     {
//         if (currentPlayer == b[i] && currentPlayer == b[i + 1] && currentPlayer == b[i + 2])
//         {
//             return true;
//         }
//     }
//     for (size_t i = 0; i < 3; i++)
//     {
//         if (currentPlayer == b[i] && currentPlayer == b[i + 3] && currentPlayer == b[i + 6])
//         {
//             return true;
//         }
//     }
//     if (currentPlayer == b[0] && currentPlayer == b[4] && currentPlayer == b[8])
//     {
//         return true;
//     }
//     if (currentPlayer == b[2] && currentPlayer == b[4] && currentPlayer == b[6])
//     {
//         return true;
//     }
    
// }