// NeuralNetwork.h

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <eigen3/Eigen/Eigen>
#include <random>
#include <chrono>
// #include <iostream>
// #include <vector>

// // use typedefs for future ease for changing data types like : float to double
// typedef float Scalar;
// typedef Eigen::MatrixXf Matrix;
// typedef Eigen::RowVectorXf RowVector;
// typedef Eigen::VectorXf ColVector;

// // neural network implementation class!
// class NeuralNetwork {
// public:
// 	// constructor
// 	NeuralNetwork(std::vector<uint> topology, Scalar learningRate = Scalar(0.005));

// 	// function for forward propagation of data
// 	void propagateForward(RowVector& input);

// 	// function for backward propagation of errors made by neurons
// 	void propagateBackward(RowVector& output);

// 	// function to calculate errors made by neurons in each layer
// 	void calcErrors(RowVector& output);

// 	// function to update the weights of connections
// 	void updateWeights();

// 	// function to train the neural network give an array of data points
// 	void train(std::vector<RowVector*> data);

// 	// storage objects for working of neural network
// 	/*
// 		use pointers when using std::vector<Class> as std::vector<Class> calls destructor of
// 		Class as soon as it is pushed back! when we use pointers it can't do that, besides
// 		it also makes our neural network class less heavy!! It would be nice if you can use
// 		smart pointers instead of usual ones like this
// 		*/
// 	std::vector<RowVector*> neuronLayers; // stores the different layers of out network
// 	std::vector<RowVector*> cacheLayers; // stores the unactivated (activation fn not yet applied) values of layers
// 	std::vector<RowVector*> deltas; // stores the error contribution of each neurons
// 	std::vector<Matrix*> weights; // the connection weights itself
// 	Scalar learningRate;
// };

//#include <Eigen/Eigen> 
#include <vector> 

typedef Eigen::RowVectorXd RowVector;
typedef Eigen::MatrixXd Matrix;
using namespace std;

#define LEARNING_RATE   0.01

class NeuralNetwork {
public:
    enum Activation { TANH, SIGMOID } mActivation;
    // network learning rate
    double mLearningRate;
    // network layers architecture (input-hidden-output) 
    vector<int> mArchitecture;
    // network layers vectors
    vector<RowVector*> mNeurons;
    // neurons' output errors
    vector<RowVector*> mErrors;
    // connections' weights
    vector<Matrix*> mWeights;
    // confusion matrix
    Matrix* mConfusion;

    // constructors
    NeuralNetwork();
    ~NeuralNetwork();
    NeuralNetwork(
        vector<int> architecture, 
        double learningRate = LEARNING_RATE,
        Activation = TANH);
    void init(
        vector<int> architecture, 
        double learningRate = LEARNING_RATE,
        Activation = TANH);
    // load from file
    bool load(const char* file);

    // save to file
    void save(const char* file);

    // data forward propagation
    void forward(RowVector& input);
    double activation(double x);

    // backward propagation of errors
    void backward(RowVector& output);
    double activationDerivative(double x);

    // train the neural network given an input
    void train(RowVector& input, RowVector& output);

    // test the neural network given an input
    void test(RowVector& input, RowVector& output);

    void resetConfusion();
    void evaluate(RowVector& output);
    void confusionMatrix(RowVector*& precision, RowVector*& recall);

    // get max output index
    int vote(double& value);
    int vote(RowVector& v, double& value);

    // get last layer output
    double output(int col);
    
    // get output layer mean squere error
    double mse();

	// adjust weights
	void AdjustWeights(double min, double max);

	// random engine
	default_random_engine engine;// todo make static
};


#endif