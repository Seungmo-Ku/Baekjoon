/*
DFS
*/

#include <iostream>
#include <list>

using namespace std;

int main(void) {

    int N, M, R;
    int i, j;

    cin >> N >> M >> R;

    int* d = new int[N];
    int* t = new int[N];
    int* parent = new int[N];
    int current = -1;

    for(i = 0; i < N; i ++) {
        d[i] = -1;
        t[i] = 0;
        parent[i] = -1;
    }

    d[R - 1] = 0;
    t[R - 1] = 1;
    //parent[R - 1] = R - 1;

    list<int>* connection = new list<int>[N];
    for(i = 0; i < M; i ++) {
        int a, b, index = 0;

        cin >> a >> b;

        connection[a - 1].push_back(b - 1);
        connection[b - 1].push_back(a - 1);
    }
    for(i = 0; i < N; i ++) {
        connection[i].sort();
    }

    current = R - 1;
    list<int>::iterator it;
    long long int count = 1;
    while(current != -1) {
        for(it = connection[current].begin(); it != connection[current].end(); ++it) {
            if(d[*it] == -1) {
                d[*it] = d[current] + 1;
                t[*it] = ++count;
                parent[*it] = current;
                current = *it;
                //cout << "visiting " << *it + 1 << endl;
                break;
            }
        }
        
        if(it == connection[current].end()) {
            if(parent[current] != -1) {
                current = parent[current];
                //++count;
            }else break;
        }
        
    }


    long long int sum = 0;
    for(i = 0; i < N; i ++) {
        sum += (long long int)d[i] * (long long int)t[i];
    }
    
    cout << sum << endl;

    delete [] d;
    delete [] t;
    delete [] parent;
    delete [] connection;
    return 0;
}

