#include "../include/sigmoid.h"

float fSigmoid(float x) {
	//return 1.0/(1+pow(2.718,-1.0*x));
	return x>0.5?1:0;
}
