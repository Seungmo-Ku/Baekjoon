#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(void) {
	
	int T; //test case
	int x1, y1, x2, y2, r1, r2;
	int i;
	int *arr;
	double d;
	
	cin >> T;
	arr = new int[T];
	
	for(i = 0; i < T; i ++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	
		d = hypot(x2 - x1, y2 - y1);
		arr[i] = -2;
		//cout << d;
		
		if(x1 == x2 && y1 == y2 && r1 == r2) {
			arr[i] = -1;
		} //return -1
		else if(d < r1 || d < r2) { //내부에 있을 때 
			if(d < abs(r2 - r1)) {
				arr[i] = 0;
			} //return 0;
			else if((int)d == abs(r2 - r1)) {
				arr[i] = 1;
			} //return 1
		}
		
		else if(d == r1 + r2) {
			arr[i] = 1;
		} //return 1
		else if (d > r1 + r2) {
			arr[i] = 0;
		} //return 0;
		if (d < r1 + r2 && arr[i] == -2) {
			arr[i] = 2;
		} //return 2
	}
	for(i = 0; i < T; i ++) {
		cout << arr[i] << endl;	
	}
	
	delete[] arr;
	return 0;
}
