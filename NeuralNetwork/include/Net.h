#ifndef NET_H
#define NET_H

#include "../include/Neuron.h"
#include <cstdio>
#include <vector>

using namespace std;

class Net {
public:
	Net();
	Net(int inputN,int hiddenN,int outputN);
	virtual ~Net();
	void work();
	void study();
	void printString();
	int getInputN();
	int getHiddenN();
	int getOutputN();
	void setW();
protected:
private:
	int inputN,hiddenN,outputN;
	vector<Neuron> inputNet;
	vector<Neuron> hiddenNet;
	vector<Neuron> outputNet;
	vector<float> inputOut;
	vector<float> hiddenOut;
	vector<float> outputOut;
	float studyEffect=1;
};

#endif // NET_H
