#include <iostream>

using namespace std;

int main(void) {
	
	int X;
	int binary[7];
	int i;
	int cnt = 0;
	
	for(i = 0; i < 7; i ++)
		binary[i] = 0;
	
	cin >> X;
	
	
	for(i = 0; X != 0; i ++) {
		binary[i] = X % 2;
		X /= 2;
	}
	for(i = 0; i < 7; i ++)
		if(binary[i] == 1)
			cnt ++;
	
	cout << cnt;
	return 0;
}
