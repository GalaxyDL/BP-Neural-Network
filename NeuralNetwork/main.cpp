#include <iostream>
#include "include/Neuron.h"
#include "include/Net.h"

using namespace std;

int main() {
	freopen("test.in","r",stdin);
	int iN,hN,oN;
	char cmd;
	scanf("%d%d%d",&iN,&hN,&oN);
	Net net=Net(iN,hN,oN);
	while(1) {
		cmd=getchar();
		if(cmd=='s')net.study();
		if(cmd=='w')net.work();
		if(cmd=='p')net.printString();
		if(cmd=='e')break;
		if(cmd=='l') {
			freopen("net.txt","w",stdout);
			net.printString();
			fclose(stdout);
		}
		if(cmd=='i'){
            net.setW();
		}
	}
	fclose(stdin);
	return 0;
}
