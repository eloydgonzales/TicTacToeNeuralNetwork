// NeuralNetwork.cpp
// Eloyd Lee Gonzales

// Original code written by Hatem Mostafa at https://www.codeproject.com/Articles/5292985/Artificial-Neural-Network-Cplusplus-class#DigitsSaveNetwork released under the CPOL 1.02 https://www.codeproject.com/info/cpol10.aspx
/*The Code Project Open License (CPOL) 1.02

Preamble

This License governs Your use of the Work. This License is intended to allow developers to use the Source Code and Executable Files provided as part of the Work in any application in any form.

The main points subject to the terms of the License are:

    Source Code and Executable Files can be used in commercial applications;
    Source Code and Executable Files can be redistributed; and
    Source Code can be modified to create derivative works.
    No claim of suitability, guarantee, or any warranty whatsoever is provided. The software is provided "as-is".
    The Article accompanying the Work may not be distributed or republished without the Author's consent

This License is entered between You, the individual or other entity reading or otherwise making use of the Work licensed pursuant to this License and the individual or other entity which offers the Work under the terms of this License ("Author").
License

THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CODE PROJECT OPEN LICENSE ("LICENSE"). THE WORK IS PROTECTED BY COPYRIGHT AND/OR OTHER APPLICABLE LAW. ANY USE OF THE WORK OTHER THAN AS AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.

BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HEREIN, YOU ACCEPT AND AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE. THE AUTHOR GRANTS YOU THE RIGHTS CONTAINED HEREIN IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS. IF YOU DO NOT AGREE TO ACCEPT AND BE BOUND BY THE TERMS OF THIS LICENSE, YOU CANNOT MAKE ANY USE OF THE WORK.

    Definitions.
        "Articles" means, collectively, all articles written by Author which describes how the Source Code and Executable Files for the Work may be used by a user.
        "Author" means the individual or entity that offers the Work under the terms of this License.
        "Derivative Work" means a work based upon the Work or upon the Work and other pre-existing works.
        "Executable Files" refer to the executables, binary files, configuration and any required data files included in the Work.
        "Publisher" means the provider of the website, magazine, CD-ROM, DVD or other medium from or by which the Work is obtained by You.
        "Source Code" refers to the collection of source code and configuration files used to create the Executable Files.
        "Standard Version" refers to such a Work if it has not been modified, or has been modified in accordance with the consent of the Author, such consent being in the full discretion of the Author.
        "Work" refers to the collection of files distributed by the Publisher, including the Source Code, Executable Files, binaries, data files, documentation, whitepapers and the Articles.
        "You" is you, an individual or entity wishing to use the Work and exercise your rights under this License.
    Fair Use/Fair Use Rights. Nothing in this License is intended to reduce, limit, or restrict any rights arising from fair use, fair dealing, first sale or other limitations on the exclusive rights of the copyright owner under copyright law or other applicable laws.
    License Grant. Subject to the terms and conditions of this License, the Author hereby grants You a worldwide, royalty-free, non-exclusive, perpetual (for the duration of the applicable copyright) license to exercise the rights in the Work as stated below:
        You may use the standard version of the Source Code or Executable Files in Your own applications.
        You may apply bug fixes, portability fixes and other modifications obtained from the Public Domain or from the Author. A Work modified in such a way shall still be considered the standard version and will be subject to this License.
        You may otherwise modify Your copy of this Work (excluding the Articles) in any way to create a Derivative Work, provided that You insert a prominent notice in each changed file stating how, when and where You changed that file.
        You may distribute the standard version of the Executable Files and Source Code or Derivative Work in aggregate with other (possibly commercial) programs as part of a larger (possibly commercial) software distribution.
        The Articles discussing the Work published in any form by the author may not be distributed or republished without the Author's consent. The author retains copyright to any such Articles. You may use the Executable Files and Source Code pursuant to this License but you may not repost or republish or otherwise distribute or make available the Articles, without the prior written consent of the Author.
    Any subroutines or modules supplied by You and linked into the Source Code or Executable Files of this Work shall not be considered part of this Work and will not be subject to the terms of this License.
    Patent License. Subject to the terms and conditions of this License, each Author hereby grants to You a perpetual, worldwide, non-exclusive, no-charge, royalty-free, irrevocable (except as stated in this section) patent license to make, have made, use, import, and otherwise transfer the Work.
    Restrictions. The license granted in Section 3 above is expressly made subject to and limited by the following restrictions:
        You agree not to remove any of the original copyright, patent, trademark, and attribution notices and associated disclaimers that may appear in the Source Code or Executable Files.
        You agree not to advertise or in any way imply that this Work is a product of Your own.
        The name of the Author may not be used to endorse or promote products derived from the Work without the prior written consent of the Author.
        You agree not to sell, lease, or rent any part of the Work. This does not restrict you from including the Work or any part of the Work inside a larger software distribution that itself is being sold. The Work by itself, though, cannot be sold, leased or rented.
        You may distribute the Executable Files and Source Code only under the terms of this License, and You must include a copy of, or the Uniform Resource Identifier for, this License with every copy of the Executable Files or Source Code You distribute and ensure that anyone receiving such Executable Files and Source Code agrees that the terms of this License apply to such Executable Files and/or Source Code. You may not offer or impose any terms on the Work that alter or restrict the terms of this License or the recipients' exercise of the rights granted hereunder. You may not sublicense the Work. You must keep intact all notices that refer to this License and to the disclaimer of warranties. You may not distribute the Executable Files or Source Code with any technological measures that control access or use of the Work in a manner inconsistent with the terms of this License.
        You agree not to use the Work for illegal, immoral or improper purposes, or on pages containing illegal, immoral or improper material. The Work is subject to applicable export laws. You agree to comply with all such laws and regulations that may apply to the Work after Your receipt of the Work.
    Representations, Warranties and Disclaimer. THIS WORK IS PROVIDED "AS IS", "WHERE IS" AND "AS AVAILABLE", WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES OR CONDITIONS OR GUARANTEES. YOU, THE USER, ASSUME ALL RISK IN ITS USE, INCLUDING COPYRIGHT INFRINGEMENT, PATENT INFRINGEMENT, SUITABILITY, ETC. AUTHOR EXPRESSLY DISCLAIMS ALL EXPRESS, IMPLIED OR STATUTORY WARRANTIES OR CONDITIONS, INCLUDING WITHOUT LIMITATION, WARRANTIES OR CONDITIONS OF MERCHANTABILITY, MERCHANTABLE QUALITY OR FITNESS FOR A PARTICULAR PURPOSE, OR ANY WARRANTY OF TITLE OR NON-INFRINGEMENT, OR THAT THE WORK (OR ANY PORTION THEREOF) IS CORRECT, USEFUL, BUG-FREE OR FREE OF VIRUSES. YOU MUST PASS THIS DISCLAIMER ON WHENEVER YOU DISTRIBUTE THE WORK OR DERIVATIVE WORKS.
    Indemnity. You agree to defend, indemnify and hold harmless the Author and the Publisher from and against any claims, suits, losses, damages, liabilities, costs, and expenses (including reasonable legal or attorneys’ fees) resulting from or relating to any use of the Work by You.
    Limitation on Liability. EXCEPT TO THE EXTENT REQUIRED BY APPLICABLE LAW, IN NO EVENT WILL THE AUTHOR OR THE PUBLISHER BE LIABLE TO YOU ON ANY LEGAL THEORY FOR ANY SPECIAL, INCIDENTAL, CONSEQUENTIAL, PUNITIVE OR EXEMPLARY DAMAGES ARISING OUT OF THIS LICENSE OR THE USE OF THE WORK OR OTHERWISE, EVEN IF THE AUTHOR OR THE PUBLISHER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Termination.
        This License and the rights granted hereunder will terminate automatically upon any breach by You of any term of this License. Individuals or entities who have received Derivative Works from You under this License, however, will not have their licenses terminated provided such individuals or entities remain in full compliance with those licenses. Sections 1, 2, 6, 7, 8, 9, 10 and 11 will survive any termination of this License.
        If You bring a copyright, trademark, patent or any other infringement claim against any contributor over infringements You claim are made by the Work, your License from such contributor to the Work ends automatically.
        Subject to the above terms and conditions, this License is perpetual (for the duration of the applicable copyright in the Work). Notwithstanding the above, the Author reserves the right to release the Work under different license terms or to stop distributing the Work at any time; provided, however that any such election will not serve to withdraw this License (or any other license that has been, or is required to be, granted under the terms of this License), and this License will continue in full force and effect unless terminated as stated above.
    Publisher. The parties hereby confirm that the Publisher shall not, under any circumstances, be responsible for and shall not have any liability in respect of the subject matter of this License. The Publisher makes no warranty whatsoever in connection with the Work and shall not be liable to You or any party on any legal theory for any damages whatsoever, including without limitation any general, special, incidental or consequential damages arising in connection to this license. The Publisher reserves the right to cease making the Work available to You at any time without notice
    Miscellaneous
        This License shall be governed by the laws of the location of the head office of the Author or if the Author is an individual, the laws of location of the principal place of residence of the Author.
        If any provision of this License is invalid or unenforceable under applicable law, it shall not affect the validity or enforceability of the remainder of the terms of this License, and without further action by the parties to this License, such provision shall be reformed to the minimum extent necessary to make such provision valid and enforceable.
        No term or provision of this License shall be deemed waived and no breach consented to unless such waiver or consent shall be in writing and signed by the party to be charged with such waiver or consent.
        This License constitutes the entire agreement between the parties with respect to the Work licensed herein. There are no understandings, agreements or representations with respect to the Work not specified herein. The Author shall not be bound by any additional provisions that may appear in any communication from You. This License may not be modified without the mutual written agreement of the Author and You.

*/

// I have modified this code to work for training with genetic algorithms.

#include <iostream> 
#include <fstream> 
#include "NeuralNetwork.h"
#include "math.h"
#include <string>

NeuralNetwork::NeuralNetwork() {
	mConfusion = nullptr;
}

NeuralNetwork::~NeuralNetwork() {
	if (mConfusion)
		delete mConfusion;
}

NeuralNetwork::NeuralNetwork(
	vector<int> architecture,
	double learningRate /*= LEARNING_RATE*/,
	Activation activation /*= TANH*/) {
	init(architecture, learningRate, activation);
}

void NeuralNetwork::init(
	vector<int> architecture,
	double learningRate /*= LEARNING_RATE*/,
	Activation activation/*= TANH*/) {
	mArchitecture = architecture;
	mLearningRate = learningRate;
	mActivation = activation;

	mNeurons.clear();
	mErrors.clear();
	mWeights.clear();

	for (unsigned int i = 0; i < architecture.size(); i++) {
		// add extra neuron to each layer as a bias (with weight = 1)
		int size = architecture[i] + (i != architecture.size() - 1);
		mNeurons.push_back(new RowVector(size));
		mErrors.push_back(new RowVector(size));

		mNeurons.back()->setZero();
		if (i < architecture.size() - 1)
			// set bias to 1 (used in vectors dot product)
			mNeurons.back()->coeffRef(architecture[i]) = 1.0;

		// initialize weights
		if (i > 0) {
			if (i != architecture.size() - 1) {
				mWeights.push_back(new Matrix(architecture[i - 1] + 1, architecture[i] + 1));
				mWeights.back()->setRandom();
				mWeights.back()->col(architecture[i]).setZero();
				mWeights.back()->coeffRef(architecture[i - 1], architecture[i]) = 1.0;
			} else {
				mWeights.push_back(new Matrix(architecture[i - 1] + 1, architecture[i]));
				mWeights.back()->setRandom();
			}
		}
	}
	mConfusion = new Matrix(architecture.back(), architecture.back());
	mConfusion->setZero();

    // Eloyd added
    // seed random engine
	engine.seed(chrono::system_clock::now().time_since_epoch().count());
}

double NeuralNetwork::activation(double x) {
	if (mActivation == TANH)
		return tanh(x);
	if (mActivation == SIGMOID)
		return 1.0 / (1.0 + exp(-x));
	return 0;
}

double NeuralNetwork::activationDerivative(double x) {
	if (mActivation == TANH)
		return 1 - tanh(x) * tanh(x);
	if (mActivation == SIGMOID)
		return x * (1.0 - x);
	return 0;
}

void NeuralNetwork::forward(RowVector& input) {
	// set first layer input
	mNeurons.front()->block(0, 0, 1, input.size()) = input;

	// propagate forward (vector multiplication)
	for (unsigned int i = 1; i < mArchitecture.size(); i++) {
		// copy values ingoring last neuron as it is a bias
		mNeurons[i]->block(0, 0, 1, mArchitecture[i]) = (*mNeurons[i - 1] * *mWeights[i - 1]).block(0, 0, 1, mArchitecture[i]);
		// apply activation function
		for (int col = 0; col < mArchitecture[i]; col++)
			mNeurons[i]->coeffRef(col) = activation(mNeurons[i]->coeffRef(col));
	}
}

void NeuralNetwork::test(RowVector& input, RowVector& output) {
	forward(input);
	// calculate last layer errors
	*mErrors.back() = output - *mNeurons.back();
}

void NeuralNetwork::resetConfusion() {
	if (mConfusion)
		mConfusion->setZero();
}

void NeuralNetwork::evaluate(RowVector& output) {
	double desired = 0, actual = 0;
	mConfusion->coeffRef(
		vote(output, desired),
		vote(*mNeurons.back(), actual)
	)++;
}

void NeuralNetwork::confusionMatrix(RowVector*& precision, RowVector*& recall) {
	int rows = (int)mConfusion->rows();
	int cols = (int)mConfusion->cols();

	precision = new RowVector(cols);
	for (int col = 0; col < cols; col++) {
		double colSum = 0;
		for (int row = 0; row < rows; row++)
			colSum += mConfusion->coeffRef(row, col);
		precision->coeffRef(col) = mConfusion->coeffRef(col, col) / colSum;
	}

	recall = new RowVector(rows);
	for (int row = 0; row < rows; row++) {
		double rowSum = 0;
		for (int col = 0; col < cols; col++)
			rowSum += mConfusion->coeffRef(row, col);
		recall->coeffRef(row) = mConfusion->coeffRef(row, row) / rowSum;
	}

	// convert confusion to percentage 
	for (int row = 0; row < rows; row++) {
		double rowSum = 0;
		for (int col = 0; col < cols; col++)
			rowSum += mConfusion->coeffRef(row, col);
		for (int col = 0; col < cols; col++)
			mConfusion->coeffRef(row, col) = mConfusion->coeffRef(row, col) * 100 / rowSum;
	}
}


void NeuralNetwork::backward(RowVector& output) {
	// calculate last layer errors
	*mErrors.back() = output - *mNeurons.back();

	// calculate hidden layers' errors (vector multiplication)
	for (size_t i = mErrors.size() - 2; i > 0; i--)
		*mErrors[i] = *mErrors[i + 1] * mWeights[i]->transpose();

	// update weights
	for (size_t i = 0, size = mWeights.size(); i < size; i++)
		for (int row = 0, rows = (int)mWeights[i]->rows(); row < rows; row++)
			for (int col = 0, cols = (int)mWeights[i]->cols(); col < cols; col++)
				mWeights[i]->coeffRef(row, col) +=
				mLearningRate *
				mErrors[i + 1]->coeffRef(col) *
				mNeurons[i]->coeffRef(row) *
				activationDerivative(mNeurons[i + 1]->coeffRef(col));
}

void NeuralNetwork::train(RowVector& input, RowVector& output) {
	forward(input);
	backward(output);
}

// mean square error
double NeuralNetwork::mse() {
	return sqrt((*mErrors.back()).dot((*mErrors.back())) / mErrors.back()->size());
}

int NeuralNetwork::vote(double& value) {
	auto it = mNeurons.back();
	return vote(*it, value);
}

int NeuralNetwork::vote(RowVector& v, double& value) {
	int index = 0;
	for (int i = 1; i < v.cols(); i++)
		if (v[i] > v[index])
			index = i;
	value = v[index];
	return index;
}

double NeuralNetwork::output(int col) {
	auto it = mNeurons.back();
	return (*it)[col];
}

void NeuralNetwork::save(const char* filename) {
	stringstream tplgy;
	for (auto it = mArchitecture.begin(), _end = mArchitecture.end(); it != _end; it++)
		tplgy << *it << (it != _end - 1 ? "," : "");

	stringstream wts;
	for (auto it = mWeights.begin(), _end = mWeights.end(); it != _end; it++)
		wts << **it << (it != _end - 1 ? "," : "") << endl;

	ofstream file(filename);
	file << "learningRate: " << mLearningRate << endl;
	file << "architecture: " << tplgy.str() << endl;
	file << "activation: " << mActivation << endl;
	file << "weights: " << endl << wts.str() << endl;
	file.close();
}

bool NeuralNetwork::load(const char* filename) {
	mArchitecture.clear();

	ifstream file(filename);
	if (!file.is_open())
		return false;
	string line, name, value;
	if (!getline(file, line, '\n'))
		return false;
	stringstream lr(line);

	// read learning rate
	getline(lr, name, ':');
	if (name != "learningRate")
		return false;
	if (!getline(lr, value, '\n'))
		return false;
	mLearningRate = atof(value.c_str());

	// read topoplogy
	getline(file, line, '\n');
	stringstream ss(line);
	getline(ss, name, ':');
	if (name != "architecture")
		return false;
	while (getline(ss, value, ','))
		mArchitecture.push_back(atoi(value.c_str()));

	// read activation
	getline(file, line, '\n');
	stringstream sss(line);
	getline(sss, name, ':');
	if (name != "activation")
		return false;
	if (!getline(sss, value, '\n'))
		return false;
	mActivation = (Activation)atoi(value.c_str());

	// initialize using read architecture
	init(mArchitecture, mLearningRate, mActivation);

	// read weights
	getline(file, line, '\n');
	stringstream we(line);
	getline(we, name, ':');
    if (name != "weights")
        return false;
	// if (!name._Equal("weights"))// !std::equal(name.begin(), name.end(), "weights"
	// 	return false;

	string matrix;
	for (int i = 0; i < mArchitecture.size(); i++)
		if (getline(file, matrix, ',')) {
			stringstream ss(matrix);
			int row = 0;
			while (getline(ss, value, '\n'))
				if (!value.empty()) {
					stringstream word(value);
					int col = 0;
					while (getline(word, value, ' '))
						if (!value.empty())
							mWeights[i]->coeffRef(row, col++) = atof(value.c_str());
					row++;
				}
		}

	file.close();
	return true;
}

// Eloyd added
void NeuralNetwork::AdjustWeights(double percent)
{
    uniform_real_distribution<double> dist(-percent, percent);
    for (auto it = mWeights.begin(), _end = mWeights.end(); it != _end; it++)
        **it = **it * dist(engine);
}

// Eloyd added
NeuralNetwork::NeuralNetwork(const NeuralNetwork &other)
	: mActivation(other.mActivation), 
	mLearningRate(other.mLearningRate), 
	mArchitecture(other.mArchitecture), 
	mNeurons(other.mNeurons), 
	mErrors(other.mErrors), 
	mWeights(other.mWeights)
{
	mConfusion = new Matrix(mArchitecture.back(), mArchitecture.back());
	*mConfusion = *other.mConfusion;
}

// Eloyd added
NeuralNetwork &NeuralNetwork::operator=(NeuralNetwork other)
{
    std::swap(mActivation, other.mActivation);
    std::swap(mLearningRate, other.mLearningRate);
    std::swap(mArchitecture, other.mArchitecture);
    std::swap(mNeurons, other.mNeurons);
    std::swap(mErrors, other.mErrors);
    std::swap(mWeights, other.mWeights);
    *mConfusion = *other.mConfusion;
    return *this;
}
