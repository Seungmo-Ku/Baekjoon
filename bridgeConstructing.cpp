#include <iostream>

using namespace std;


int main(void) {
	
	int T; 
	int N, M;	
	int i, j;
	long *ans;
	long mot = 1, son = 1;
	
	cin >> T; //test case
	ans = new long[T];
	for(i = 0; i < T; i ++) {
		cin >> N >> M;
		mot = 1;
		son = 1;
		//8C7
		if(M / 2 < N)
			N = M - N;
		for(j = 1; j <= N; j ++) {
			mot = mot * (M - j + 1); 
			son = son * j;
		}
		//cout << "mother : " << mot << " son : " << son << endl;
		ans[i] = (long)mot / (long)son;
	}
	
	for(i = 0; i < T; i ++){
		cout << ans[i] << endl;
	}
	
	delete[] ans;
	return 0;
}
