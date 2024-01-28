#include <iostream>

using namespace std;

void print(int x, int y);

int main(void) {
	
	
	/*
	1/1 1/2 2/1 3/1 2/2 1/3 1/4 2/3 3/2 
	1/1 ½ÃÀÛ 1/2 2/1  
	*/
	int X;
	int x = 1, y = 1, i = 1;
	int status = 0; //0 : right, 1 : leftdown -> down, 2 : rightup -> right
	cin >> X;
	
	if(X == 1) {
		print(x, y);
		return 0;
	} 
	else {
		
		while(i != X) {
			if(status == 0) {
				y ++;
				status ++;
			}else if (status == 1) {
				if(y - 1 > 0) {
					x ++;
					y --;
				}else {
					x++;
					status ++;
				}
			}else if (status == 2) {
				if(x - 1 > 0) {
					x --;
					y ++;
				}else {
					y ++;
					status = 1;
				}
			}
			i ++;	
		}
		print(x, y);
		
	}
	return 0;
}

void print(int x, int y) {
	cout << x << "/" << y << endl;
}

