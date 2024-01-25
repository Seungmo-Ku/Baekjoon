#include <iostream>
#include <string>

using namespace std;


long decreasingNumber(int cnt);
long findNext(long prev);


int main(void) {
	
	int N;
	cin >> N;

	if(N == 0)
		cout << 0 << endl;
	else {
		
		
		//cout << findNext(N);
		cout << decreasingNumber(N) << endl;
	}
	return 0;
}



long decreasingNumber(int cnt) {
	int i = 1;
	long next = 1;
	if(cnt == 0)
		return 0;
	if(cnt >= 1023)
		return -1;
	if(cnt == 1022)
		return long(9876543210);
	else {
		while (i != cnt) {
			next = findNext(next);
			//cout << "next dN : " << next << " / cnt : " << i << endl;
			i ++;
			
		} 
		return next;
	}
	
}
long findNext(long prev) {
	int len = 0, prevD, i;
	int *arr;
	int sum = 0, j, k = 1;
	if(prev == 9876543210)
		return -1;
	else if (prev == 9)
		return 10;
	else if (prev == 98)
		return 210;
	else if (prev == 987)
		return 3210;
	else if (prev == 9876)
		return 43210;
	else if (prev == 98765)
		return 543210;
	else if (prev == 987654)
		return 6543210;
	else if (prev == 9876543)
		return 76543210;
	else if (prev == 98765432)
		return 876543210;
	else if (prev == 987654321)
		return 9876543210;
	
	prevD = prev;
	while(prevD >= 10) {
		len ++;
		prevD /= 10;
	} //ÀÚ¸´¼ö ±¸ÇÔ.
	len ++;
	//cout << "len : " << len << endl;
	arr = new int[len];
	i = 1;
	prevD = prev;
	//9 8 7 6 5 4 3 2 1 0
	while(prevD >= 10) {
		arr[len - i++] = prevD % 10;
		prevD /= 10;
	}
	arr[0] = prevD;
	
	//521
	
	i = len - 1;
	if(len == 1)
		return prev+1;
	while(true) {
		if(arr[i] + 1 < arr[i-1])
			break;
		i = i-1;
		if(i == 0) break;
	} arr[i] += 1;
	//cout << "index : " << i << endl;
	//5321 -> 5410          8654 8710
	k = 0;
	for(j = len - 1; j > i; j --) {
		arr[j] = k ++;
	}
	//5321
	for(i = 0; i < len; i ++) {
		k = 1;
		for(j = 1; j < len - i; j ++)
			k *= 10;
		sum += arr[i] * k;
	}
	
	delete[] arr;

	return sum;
}
