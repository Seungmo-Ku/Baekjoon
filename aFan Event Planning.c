#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	long N, Q;
	long *E;
	int *R; //Reboot
	long d, s, e;
	long i, j;
	int func;
	long sum;
	scanf("%ld %ld", &N, &Q); //N, Q input

	E = (long*)malloc(sizeof(long)*N);
	for(i = 0; i < N; i ++) //E input
		scanf("%ld", &E[i]); 
		
	//for(i = 0; i < N; i ++)
	//	printf("%ld\n", E[i]);
		
	R = (int*)malloc(sizeof(int)*N);
	memset(R, 0, sizeof(int)*N);
	//for(i = 0; i < N; i ++)
//		R[i] = 0;
	//if R[i] is 0, no reboot	
		
	for(i = 0; i < Q-1; i ++) { //test function
		scanf("%d", &func);
		if(func == 1) {
			scanf("%ld", &d);
			R[d - 1] = 1; //reboot
		}else if(func == 2) {
			scanf("%ld %ld", &s, &e); //s, e input
			sum = 0;
			for(j = s-1; j <= e-1; j ++) {
				sum += E[j];
				if(R[j] == 1)
					sum = 0;
			}printf("%d\n", sum);
		}
	}
	//last function
	scanf("%d %ld %ld", &sum, &s, &e); //s, e input
			sum = 0;
			for(j = s-1; j <= e-1; j ++) {
				sum += E[j];
				if(R[j] == 1)
					sum = 0;
			}printf("%d\n", sum);
	free(E);
	free(R);
	return 0;
}
