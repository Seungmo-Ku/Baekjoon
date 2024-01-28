#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	
	int N, M;
	string *board;
	int i, j, k, l;
	int diff = 64, diff1 = 64, diff2 = 64; //blackÀÇ °³¼ö 
	string ans[8] = {
	"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", 
	"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"
	};
	string ans2[8] = {
	"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", 
	"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"
	};
	int w = 0, b = 64;
	int bcnt = 0, wcnt = 0;
	
	
	
	cin >> N >> M;
	
	board = new string[N];
	
	for(i = 0; i < N; i ++) {
		cin >> board[i];
	}
	for(i = 0; i <= N - 8; i ++) {
		for(j = 0; j <= M - 8; j ++) {
			diff1 = 0, diff2 = 0;
			for(k = i; k < i + 8; k ++) {
				for(l = j; l < j + 8; l ++){
					if(board[k][l] != ans[k-i][l-j])
						diff1 ++;
					if(board[k][l] != ans2[k-i][l-j])
						diff2 ++;
				}		
			}
			diff = min(min(diff1, diff2), diff);
			
		}
	}	
	cout << diff;
	
	delete[] board;
	return 0;
}
