#include <iostream>

using namespace std;

int main(void) {
	
	int N, M;
	int *packagePrice, *singlePrice;
	int leastPrice = 0;
	
	int i;
	int leastInSingle = 6001;
	int leastInPackage = 6001;
	
	cin >> N >> M;
	
	packagePrice = new int[M];
	singlePrice = new int[M];
	
	for(i = 0; i < M; i ++) {
		cin >> packagePrice[i] >> singlePrice[i];
	}
	for(i = 0; i < M; i ++) {
		if(packagePrice[i] < leastInPackage)
			leastInPackage = packagePrice[i];
		if(singlePrice[i] * 6 < leastInPackage) 
			leastInPackage = singlePrice[i] * 6;
		if(singlePrice[i] < leastInSingle)
			leastInSingle = singlePrice[i];
		
	}
	while(N >= 6) {
		leastPrice += leastInPackage;
		N -= 6;
	}
	while(N > 0) {
		if(leastInPackage < leastInSingle * N) {
			leastPrice += leastInPackage;
			N = 0;
		}else {
			leastPrice += leastInSingle;
			N --;
		}
	}
	cout << leastPrice;
	
	
	
	
	delete[] packagePrice;
	delete[] singlePrice;
	
	return 0;
}
