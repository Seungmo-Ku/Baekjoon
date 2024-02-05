#include <iostream>

using namespace std;

int biggestIndex(int* votes, int N);

int main(void) {
	
	int N, cnt = 0;
	int *votes;
	
	int i;
	
	cin >> N;
	
	votes = new int[N];
	
	for(i = 0; i < N; i ++) {
		cin >> votes[i];
	}
	while(true) {
		int max = biggestIndex(votes, N);
		if(max == 0) { //if max is dasom
			if(N == 1)
				break;
			bool same = false;
			for(i = 1; i < N; i ++) {
				if(votes[i] == votes[0])
					same = true;
			}
			if(same) {
				cnt ++;
				break;
			}else {
				break;
			}
		}else {
			cnt ++;
			votes[0] += 1;
			votes[max] -= 1;
		}
	}	
	
	cout << cnt << endl;
	
	delete[] votes;
	
	return 0;
}

int biggestIndex(int* votes, int N) {
	int max = 0, index = -1;
	for(int i = 0; i < N; i ++) {
		if(votes[i] > max) {
			max = votes[i];
			index = i;
		}
	}
	return index;
}
