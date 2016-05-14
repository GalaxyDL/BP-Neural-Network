#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
    freopen("test.in","w",stdout);
    printf("2 5 1\n");
    for(int i=1;i<=10000;i++){
        //printf("s0 0 0\ns0.1 0.1 0.1\ns0.2 0.2 0.2\ns0.3 0.3 0.3\ns0.4 0.4 0.4\ns0.5 0.5 0.5\ns0.6 0.6 0.6\ns0.7 0.7 0.7\ns0.8 0.8 0.8\ns0.9 0.9 0.9\ns1 1 1\n");
        //printf("s0 0 1\ns1 1 1\ns0 1 0\ns1 0 0\n");
    }
    //printf("w 0.05 0.05\nw 0.15 0.15\nw 0.25 0.25\nw 0.35 0.35\nw 0.45 0.45\nw 0.55 0.55\nw 0.65 0.65\nw 0.75 0.75\nw 0.85 0.85\nw 0.95 0.95\np\nl\n");
    freopen("net.txt","r",stdin);
    int tempI;
	float tempF;
	printf("i\n");
	for(int i=0; i<2;i++) {
		scanf("%d",&tempI);
		printf("%d\n",tempI);
		for(int j=0; j<=tempI; j++) {
			scanf("%f",&tempF);
			printf("%f ",tempF);
		}
		printf("\n");
	}
	for(int i=0; i<5; i++) {
		scanf("%d",&tempI);
		printf("%d\n",tempI);
		for(int j=0; j<=tempI; j++) {
			scanf("%f",&tempF);
			printf("%f ",tempF);
		}
		printf("\n");
	}
	for(int i=0; i<1; i++) {
		scanf("%d",&tempI);
		printf("%d\n",tempI);
		for(int j=0; j<=tempI; j++) {
			scanf("%f",&tempF);
			printf("%f ",tempF);
		}
		printf("\n");
	}
    printf("w1 0\nw0 0\nw1 1\nw0 1\np\nl\n");
    fclose(stdout);
    return 0;
}
