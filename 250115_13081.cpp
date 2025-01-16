#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getNextRat(string);

int main(void) {
    int t;
    cin >> t;
    string* ratsArr = new string[t];
    int* numArr = new int[t];
    for(int q = 0; q < t; q ++) {
        cin >> numArr[q] >> ratsArr[q];
    }
    for(int q = 0; q < t; q ++) {
    string RATS;
    int rats_to_int;
    int M;
    //cin >> M >> RATS;
    M = numArr[q];
    RATS = ratsArr[q];
    //RATS = to_string(rats_to_int);
    string* ratsString = new string[M];
    //cout << 1 << " :::: " << RATS << endl;
    ratsString[0] = RATS;
    int i;
    for(i = 0; i < M; i ++) {
        if(i != 0) RATS = getNextRat(RATS);
        bool exists = false;
        for (int j = 0; j < i; j++) {
            if (ratsString[j] == RATS) {
                exists = true;
                cout << "R " << i+1 << endl;
                break;
            }
        }
        if(exists) break;
        int len = RATS.length();
        if(len < 5) {
            ratsString[i] = RATS;
            continue;
        }
        bool chainExists = false;
        if (RATS[0] == '1' && RATS[1] == '2' && RATS[2] == '3' && RATS[3] == '3' && RATS[len - 5] == '3' && RATS[len - 4] == '4' && RATS[len - 3] == '4' &&
            RATS[len - 2] == '4' && RATS[len - 1] == '4') {
                chainExists = true;
                for(int j = 3; j < len - 5; j ++) {
                    if(RATS[j] != '3') {
                        chainExists = false;
                        break;
                    }
                }
        }else if (RATS[0] == '5' && RATS[1] == '5' && RATS[2] == '6' && RATS[3] == '6' && RATS[len - 5] == '6' && RATS[len - 4] == '7' && RATS[len - 3] == '7' &&
            RATS[len - 2] == '7' && RATS[len - 1] == '7') {
                chainExists = true;
                for(int j = 3; j < len - 5; j ++) {
                    if(RATS[j] != '6') {
                        chainExists = false;
                        break;
                    }
                }
            }

            if(chainExists) {
                ratsString[i] = RATS;
                cout << "C " << i+1 << endl;
                break;
            }
        ratsString[i] = RATS;
        
    }
    
    if(i == M) {
        cout << ratsString[M - 1] << endl;
    }
    
    //for(int i = 0; i < M; i ++) {
     //   cout << i+1 << " :::: " << ratsString[i] << endl;
    //}
    
    delete [] ratsString;

    }
    delete [] ratsArr;
    delete [] numArr;
    return 0;
}

string getNextRat(string rat) {
    
    string nextRat = "";
    
    int length;
    //cout << "rat : " << rat << endl;
    length = rat.length();
    //cout << "length : " << length << endl;
    
    int* ratArr = new int[length];
    for(int i = 0; i < length; i ++) {
        //cout << "rat i, " << i << " ///// " << rat[i] << " " << rat[length - i - 1] << endl;
        ratArr[i] = rat[i] - '0';
        ratArr[i] += rat[length - i - 1] - '0';
        
        if(ratArr[i] >= 10) {
            if(i != 0) {
                ratArr[i] -= 10;
                ratArr[i - 1] += 1;
            }
                
        }
    }
    for(int i = length - 1; i >= 0; i --) {
        if(ratArr[i] >= 10) {
            
            if(i != 0) {
                ratArr[i - 1] += 1;
                ratArr[i] -= 10;
            }
        }
    }
    string tempRat = "", tempRat2 = "";
    for(int i = 0; i < length; i ++) {
        tempRat2 += to_string(ratArr[i]);
    }
    //cout << "tempRat2 : " << tempRat2 << endl;
    for(int i = 0; i < tempRat2.length(); i ++) {
        if(tempRat2[i] != '0') {
            tempRat += tempRat2[i];
        }
    }
    //cout << "tempRat : " << tempRat << endl;
    //tempRat = to_string(sum);
    //cout << "sum made : " << sum << endl;
    delete [] ratArr;
    ratArr = new int[tempRat.length()];
    length = tempRat.length();
    for(int i = 0; i < tempRat.length(); i ++) {
        if(tempRat[i] != '0') {
            ratArr[i] = tempRat[i] - '0';
        }
    }
    
    sort(ratArr, ratArr + length);

    for(int i = 0; i < length; i ++) {
        nextRat += to_string(ratArr[i]);
    }

    delete[] ratArr;

    return nextRat;
}