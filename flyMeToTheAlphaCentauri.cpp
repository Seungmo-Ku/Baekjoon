#include <iostream>

using namespace std;

int main(void) {
	
	int T;
	int x, y;
	int distance, k;
	int* cnt;
	
	cin >> T;
	cnt = new int[T];
	
	for(int i = 0; i < T; i ++) {
	
		cin >> x >> y;
		
		distance = y - x;
		
		k = 1;
		cnt[i] = 0;
		while(distance >= 2 * k) {
			
			distance -= 2 * k;
			//cout << "distance : " << distance << endl;
			k ++;
		} 
		if(distance == 0) {
			
		}
		else if(distance > k) {
			cnt[i] += 2;
		}else if(distance <= k) {
			cnt[i] += 1;
		}
		cnt[i] += 2 * (k - 1);
	
	}
	for(int i = 0; i < T; i ++) {
		cout << cnt[i] << endl;	
	}
	delete[] cnt;
	return 0;
}
