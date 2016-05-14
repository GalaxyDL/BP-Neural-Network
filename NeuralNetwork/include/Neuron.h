#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "sigmoid.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Neuron {
public:
	Neuron();
	Neuron(int n);
	virtual ~Neuron();
	float inIt(vector<float> x);
	void printString();
	int getBeforeN();
	float getW(int pos);
	void setW(int pos,float data);
protected:
private:
	int beforeN;
	vector<float> w;
};

#endif // NEURON_H
