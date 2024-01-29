#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	
	int N;
	int cnt = 0;
	int i, j;
	bool in = false;
	string* words;
	
	
	cin >> N;
	words = new string[N];
	
	
	
	for(i = 0; i < N; i ++) {
		cin >> words[i];
	}
	
	for(i = 0; i < N; i ++) {
		vector<char> vect;
 		in = false;
		for(j = 0; j < words[i].length(); j ++) {
			
			if(find(vect.begin(), vect.end(), words[i][j]) == vect.end()) {
				vect.push_back(words[i][j]);
			}else { // 안에있으면 
				if(words[i][j] != words[i][j - 1]) { 
					in = true;
				
				}
			}
		}
		if(!in)
			cnt ++;
	}
	
	cout << cnt;
	
	delete[] words;
	
	
	
	
	return 0;
}


