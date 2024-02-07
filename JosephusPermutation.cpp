#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	
	int N, N2, K, cnt;
	vector<int> number;
	vector<int> ans;
	
	int i;
	
	cin >> N >> K;
	N2 = N;
	for(i = 1; i <= N; i ++) 
		number.push_back(i);
	cnt = K;
	while(N > 0) {
		
		ans.push_back(number[cnt - 1]);
		//cout << "cnt : " << cnt << "num : " << number[cnt - 1] << endl;
		number.erase(number.begin() + cnt - 1);
		cnt += K - 1;
		N --;
		if(N == 0)
			break;
		while(cnt > N) {
			cnt = cnt - N;
		}
	}
	printf("<");
	for(i = 0; i < N2 - 1; i ++) {
		printf("%d, ", ans[i]);
	}
	printf("%d>\n", ans[N2 - 1]);
	
	return 0;
}
