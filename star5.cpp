#include <iostream>

using namespace std;

int main(void) {
	
	int N;
	int i, j;
	
	cin >> N;
	
	for(i = 1; i <= N; i ++) {
		for(j = N - i; j > 0; j --) {
			printf(" ");
		}
		for(j = 1; j <= 2*i - 1; j ++) {
			printf("*");
		}
		cout << endl;
	}
	
	return 0;
}
