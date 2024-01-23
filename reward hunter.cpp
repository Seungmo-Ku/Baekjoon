#include <iostream>

using namespace std;

int main(void) {
	int T;
	int a, b;
	int *reward;
	int i;
	

	cin >> T; //number of simulation
	
	reward = new int[T];
	
	for(i = 0; i < T; i ++) { //T times
		cin >> a >> b;
		reward[i] = 0;
		if (a <= 0 || a > 21) reward[i] += 0;
		else if(a == 1) reward[i] += 5000000;
		else if (a <= 3) reward[i] += 3000000;
		else if (a <= 6) reward[i] += 2000000;
		else if (a <= 10) reward[i] += 500000;
		else if (a <= 15) reward[i] += 300000;
		else if (a <= 21) reward[i] += 100000;
		
		if (b <= 0 || b > 31) reward[i] += 0;
		else if(b == 1) reward[i] += 5120000;
		else if (b <= 3) reward[i] += 2560000;
		else if (b <= 7) reward[i] += 1280000;
		else if (b <= 15) reward[i] += 640000;
		else if (b <= 31) reward[i] += 320000;
		
		//cout << reward << endl;

	}
	for(i = 0; i < T; i ++) {
		cout << reward[i] << endl;
	}
	
	delete [] reward;
	return 0;
}
