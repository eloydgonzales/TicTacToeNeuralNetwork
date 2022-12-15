// Eloyd Lee Gonzales

#ifndef AIAGENT_H
#define AIAGENT_H

#include "NeuralNetwork.h"

class AIAgent
{
private:
    NeuralNetwork brain;
    int wins {0};
public:
    AIAgent(/* args */);
    ~AIAgent();
    void SetBrain(vector<int> architecture, 
        double learningRate,
        NeuralNetwork::Activation SIGMOID);
    void AdjustBrain(double percent);
    int GetMove(RowVector& input);
    int GetWins(){return wins;};
    void IncrementWins(){wins++;};
    void Reset();
};

AIAgent::AIAgent(/* args */)
{
}

AIAgent::~AIAgent()
{
}

int AIAgent::GetMove(RowVector& input)
{
    double largestVal{-100.0};
    int largestIndex{0};
    brain.forward(input);
    for (size_t i = 0; i < 9; i++)
    {
        // find the highest output to an empty space
        if (brain.output(i) > largestVal && input[i] < 0.01)// input[i] < 0.01 checks if input[i] is close to 0
        {
            largestVal = brain.output(i);
            largestIndex = i;
        }
    }
    return largestIndex;
}


#endif