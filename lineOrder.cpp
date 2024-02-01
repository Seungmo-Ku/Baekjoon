#include <iostream>

using namespace std;

int main(void) {
	
	int N;
	int* height;
	int* order;
	int i, j, cnt, index;
	
	cin >> N;
	
	height = new int[N];
	order = new int[N];
	
	//4
	//2 1 1 0
	
	for(i = 0; i < N; i ++) {
		cin >> height[i];
		order[i] = 0; 
	}
	for(i = 0; i < N; i ++) {
 		for(j = 0, cnt = 0; cnt != height[i];) {
 			if(order[j] == 0)
			 	cnt ++;	
			j ++;
			 	//cout << "cnt ;;" << cnt << " j : " << j << endl;
		}
		while(order[j] != 0)
			j ++;
		order[j] = i + 1;
		//cout << "cnt : " << j << ", i + 1 : " << i+1 << endl;
		
	}
	for(i = 0; i < N; i ++) {
		cout << order[i] << " ";
	}
	cout << endl;

	delete[] height;
	delete[] order;
	
	return 0;
}
