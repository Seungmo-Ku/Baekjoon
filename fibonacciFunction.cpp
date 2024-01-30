#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> p[41];


pair<int, int> fibonacci(int n) {
    if(p[n].first != -1) {
        return p[n];
	}else {
		return p[n] = make_pair(fibonacci(n - 1).first + fibonacci(n - 2).first, 
			fibonacci(n - 1).second + fibonacci(n - 2).second);
	}
    
}

int main(void) {
	
	int T;
	int N;
	int i;
	pair<int, int>* ans;
	
	p[0].first = 1;
	p[0].second = 0;
	p[1].first = 0;
	p[1].second = 1;
	for(i = 2; i < 41; i ++) {
		p[i].first  = -1;
		p[i].second = -1;
	}
	
	cin >> T;
	ans = new pair<int, int>[T];
	for(i = 0; i < T; i ++) {
		cin >> N;
		
		ans[i].first = fibonacci(N).first;
		ans[i].second = fibonacci(N).second;

	}
	for(i = 0; i < T; i ++) {
		cout << ans[i].first << " " << ans[i].second << endl;	
	}

	delete[] ans;

	return 0;
}
