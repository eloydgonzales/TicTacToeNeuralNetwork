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
        NeuralNetwork::Activation activation);
    void AdjustBrain(double percent);
    int GetMove(RowVector& input);
    int GetWins(){return wins;};
    void IncrementWins(){wins++;};
    void ResetWins();

    bool operator<(AIAgent& agent);
    bool operator>(AIAgent& agent);
};

AIAgent::AIAgent(/* args */)
{
    SetBrain({9, 15, 15, 9}, 0.05, NeuralNetwork::Activation::SIGMOID);
}

AIAgent::~AIAgent()
{
}

void AIAgent::SetBrain(vector<int> architecture, 
        double learningRate,
        NeuralNetwork::Activation activation)
{
    brain.init(architecture, learningRate, activation);
}

void AIAgent::AdjustBrain(double percent)
{
    brain.AdjustWeights(percent);
}

int AIAgent::GetMove(RowVector& input)
{
    double largestVal{-100.0};
    int largestIndex{0};
    brain.forward(input);
    for (size_t i = 0; i < 9; i++)
    {
        // find the highest output to an empty space
        //std::cout << input[i] << "\n";
        if (brain.output(i) > largestVal && input[i] * input[i] < 0.01)// input[i] * input[i] < 0.01 checks if input[i] is close to 0 regardless of its sign (+/-)
        {
            largestVal = brain.output(i);
            largestIndex = i;
        }
    }
    return largestIndex;
}

void AIAgent::ResetWins()
{
    wins = 0;
}

bool AIAgent::operator<(AIAgent &agent)
{
    if (wins < agent.wins)
    {
        return true;
    }
    return false;
}

bool AIAgent::operator>(AIAgent& agent)
{
    if (wins > agent.wins)
    {
        return true;
    }
    return false;
}

#endif