#include "../include/Neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(int n):beforeN(n) {
	srand(rand()*time(NULL));
	w.resize(n+1);
	for(int i=0; i<=beforeN; i++) {
		w[i]=(float)(rand()%200)/100-1;
	}
}

Neuron::~Neuron() {}

float Neuron::inIt(vector<float> x) {
	float result=0;
	for(int i=0; i<=beforeN; i++) {
		result+=w[i]*x[i];
	}
	return fSigmoid(result);
}

void Neuron::printString() {
	printf("%d\n",beforeN);
	for(int i=0; i<=beforeN; i++) {
		printf("%f ",w[i]);
	}
	printf("\n");
}

int Neuron::getBeforeN() {
	return beforeN;
}

float Neuron::getW(int pos) {
	return w[pos];
}

void Neuron::setW(int pos,float data){
    w[pos]=data;
}
