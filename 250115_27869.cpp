#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N, Q;
    int *E;
    bool *I;
    long *sum;
    string initialize = "";
    
    cin >> N >> Q;
    
    E = new int[N + 1];
    I = new bool[N + 1];
    sum = new long[N + 1];

    for(int i = 1; i < N + 1; i ++) {
        cin >> E[i];
        I[i] = false;
    }E[0] = 0;
    sum[0] = E[0]; sum[1] = E[1];
    for(int j = 1; j < N + 1; j ++) {
        sum[j] = sum[j - 1] + E[j];
    }
    for(int i = 0; i < Q; i ++) {
        int t;
        cin >> t;
        if(t == 1) {
            int d;
            cin >> d;
            initialize += to_string(d);
            sort(initialize.begin(), initialize.end());
            cout << initialize << endl;
        }else if(t == 2) {
            int s, e;
            cin >> s >> e;
            cout << sum[e] - sum[s - 1] << endl;
        }
    }
    
    delete[] E;
    delete[] I;
    delete[] sum;
    return 0;
}