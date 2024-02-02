#include <iostream>

using namespace std;

int main(void) {
	
	int N;
	int i, j;
	
	cin >> N;
	
	for(i = 1; i <= N; i ++) {
		for(j = 1; j < i; j ++) {
			printf(" ");
		}
		for(j = N; j >= i; j --) {
			printf("*");
		}
		cout << endl;
	}
	
	return 0;
}
