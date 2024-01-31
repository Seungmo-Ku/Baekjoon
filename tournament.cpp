#include <iostream>

using namespace std;

int main(void) {
	
	int N, a, b;
	int round = 1;
	
	cin >> N >> a >> b;
	
	if(a < b) {
		int c = a;
		a = b;
		b = c;
	} //bigger one to a, small one to b
	
	while(true) {
		if(a - b == 1 && a % 2 == 0) //차이가 1이고 더 큰 수가 짝수이면 끝 
			break;
		round ++;
		if(a % 2 == 1) {
			a = (a / 2) + 1;
		}else {
			a = a / 2;
		}
		if(b % 2 == 1) {
			b = (b / 2) + 1;
		}else {
			b = b / 2;
		}
	}
	
	cout << round << endl;
	
	
	return 0;
}
