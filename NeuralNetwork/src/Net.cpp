#include "Net.h"

Net::Net() {}

Net::Net(int inputN,int hiddenN,int outputN):inputN(inputN),hiddenN(hiddenN),outputN(outputN) {
	inputNet.resize(inputN);
	hiddenNet.resize(hiddenN);
	outputNet.resize(outputN);
	for(int i=0; i<inputN; i++) {
		inputNet[i]=Neuron(1);
	}
	for(int i=0; i<hiddenN; i++) {
		hiddenNet[i]=Neuron(inputN);
	}
	for(int i=0; i<outputN; i++) {
		outputNet[i]=Neuron(hiddenN);
	}
}

Net::~Net() {}

void Net::work() {
	inputOut.resize(inputN+1);
	inputOut[0]=1;
	for(int i=1; i<=inputN; i++) {
		scanf("%f",&inputOut[i]);
	}
	hiddenOut.resize(hiddenN+1);
	hiddenOut[0]=1;
	for(int i=0; i<hiddenN; i++) {
		hiddenOut[i+1]=hiddenNet[i].inIt(inputOut);
	}
	for(int i=0; i<outputN; i++) {
		printf("%f\n",outputNet[i].inIt(hiddenOut));
	}
}

void Net::study() {
	inputOut.resize(inputN+1);
	inputOut[0]=1;
	for(int i=1; i<=inputN; i++) {
		scanf("%f",&inputOut[i]);
	}
	hiddenOut.resize(hiddenN+1);
	hiddenOut[0]=1;
	for(int i=0; i<hiddenN; i++) {
		hiddenOut[i+1]=hiddenNet[i].inIt(inputOut);
	}
	outputOut.resize(outputN);
	for(int i=0; i<outputN; i++) {
		outputOut[i]=outputNet[i].inIt(hiddenOut);
	}

	float trueReslut[outputN],e[outputN];
	for(int i=0; i<outputN; i++) {
		scanf("%f",&trueReslut[i]);
		e[i]=trueReslut[i]-outputOut[i];
	}

	float NewHiddenW[inputN+1][hiddenN],NewOutputW[hiddenN+1][outputN];
	for(int i=0; i<hiddenN; i++) {
		float sum=0;
		for(int j=0; j<outputN; j++) {
			sum+=e[j]*outputNet[j].getW(i+1);
		}

		for(int j=1; j<=inputN; j++) {
			NewHiddenW[j][i]=hiddenNet[i].getW(j)+studyEffect*hiddenOut[i+1]*(1-hiddenOut[i+1])*inputOut[j]*sum;
		}
	}

	for(int i=0; i<outputN; i++) {
		for(int j=1; j<=hiddenN; j++) {
			NewOutputW[j][i]=outputNet[i].getW(j)+studyEffect*hiddenOut[j]*e[i];
		}
	}


	for(int i=0; i<hiddenN; i++) {
		float sum=0;
		for(int j=0; j<outputN; j++) {
			sum+=e[j]*outputNet[j].getW(i+1);
		}
		NewHiddenW[0][i]=hiddenNet[i].getW(0)+studyEffect*hiddenOut[i+1]*(1-hiddenOut[i+1])*sum;
	}

	for(int i=0; i<outputN; i++) {
		NewOutputW[0][i]=outputNet[i].getW(0)+studyEffect*e[i];
	}


	for(int i=0; i<hiddenN; i++) {
		for(int j=0; j<=inputN; j++) {
			hiddenNet[i].setW(j,NewHiddenW[j][i]);
		}
	}
	for(int i=0; i<outputN; i++) {
		for(int j=0; j<=hiddenN; j++) {
			outputNet[i].setW(j,NewOutputW[j][i]);
		}
	}
}

void Net::setW() {
	int tempI;
	float tempF;
	for(int i=0; i<inputN; i++) {
		scanf("%d",&tempI);
		for(int j=0; j<=tempI; j++) {
			scanf("%f",&tempF);
			inputNet[i].setW(j,tempF);
		}
	}
	for(int i=0; i<hiddenN; i++) {
		scanf("%d",&tempI);
		for(int j=0; j<=tempI; j++) {
			scanf("%f",&tempF);
			hiddenNet[i].setW(j,tempF);
		}
	}
	for(int i=0; i<outputN; i++) {
		scanf("%d",&tempI);
		for(int j=0; j<=tempI; j++) {
			scanf("%f",&tempF);
			outputNet[i].setW(j,tempF);
		}
	}
}

void Net::printString() {
	for(int i=0; i<inputN; i++) {
		inputNet[i].printString();
	}
	for(int i=0; i<hiddenN; i++) {
		hiddenNet[i].printString();
	}
	for(int i=0; i<outputN; i++) {
		outputNet[i].printString();
	}
}

int Net::getInputN() {
	return inputN;
}

int Net::getHiddenN() {
	return hiddenN;
}

int Net::getOutputN() {
	return outputN;
}
