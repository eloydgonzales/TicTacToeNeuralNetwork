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
    void SetBrain(vector<int> architecture = {9, 15, 15, 9}, 
        double learningRate = 0.05,
        NeuralNetwork::Activation activation = NeuralNetwork::Activation::SIGMOID);
    void AdjustBrain(double percent);
    int GetMove(RowVector& input);
    int GetWins(){return wins;};
    void IncrementWins(){wins++;};
    void ResetWins();
    void SaveBrain(const string file);
    bool LoadBrain(const string file);

    bool operator<(AIAgent& agent);
    bool operator>(AIAgent& agent);
};

AIAgent::AIAgent(/* args */)
{
    SetBrain();
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

void AIAgent::AdjustBrain(double range)
{
    brain.AdjustWeights(range);
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

void AIAgent::SaveBrain(const string file)
{
    brain.save(file.c_str());
}

bool AIAgent::LoadBrain(const string file)
{
    return brain.load(file.c_str());
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