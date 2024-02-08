#include <iostream>

using namespace std;

void add(int N, int S, int* arr, int *cnt, int depth, int sum);

int main(void) {
	
	int N, S;
	int *arr;
	int cnt = 0;
	
	int i;
	
	cin >> N >> S;
	
	arr = new int[N];
	
	for(i = 0; i < N; i ++)
		cin >> arr[i];
	
	add(N, S, arr, &cnt, 0, 0);
	
	if(S == 0) //공집합 제거 
		cnt --;
	
	cout << cnt;
	
	delete[] arr;
	
	return 0;
}

void add(int N, int S, int* arr, int *cnt, int depth, int sum) {
	if(depth == N) { //마지막 요소까지 왔다면 
		if(sum == S) { //satisfied
			*cnt += 1;
			//cout << "cnt : " << *cnt << endl;
		}
		return;
	}
	else { //마지막 요소가 아니라면 
		add(N, S, arr, cnt, depth + 1, sum + arr[depth]);
		//cout << "added " << sum + arr[depth] << endl;
		add(N, S, arr, cnt, depth + 1, sum);
	}
	
}
