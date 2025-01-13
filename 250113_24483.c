/*
DFS
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int N, M, R;
    int* d;
    int* t;
    int **connection;
    int i, j;
    int current = -1;
    int sum;

    scanf("%d %d %d", &N, &M, &R);

    d = (int*)malloc(N * sizeof(int));
    connection = (int**)malloc(N * sizeof(int*));
    t = (int*)malloc(N * sizeof(int));

    for(i = 0; i < N; i ++) {
        connection[i] = (int*)malloc(N * sizeof(int));
    }
    
    for(i = 0; i < N; i ++) {
        for(j = 0; j < N; j ++) {
            connection[i][j] = 0;
        }
    }

    for(i = 0; i < M; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        connection[a - 1][b - 1] = 1;
    }

    for(i = 0; i < N; i ++) {
        d[i] = -1; //깊이
        t[i] = 0; //방문 순서
    }
    d[R - 1] = 0;
    t[R - 1] = 1;
    current = R - 1;
    while(current != -1) {
        for(i = 0; i < N; i ++) {
            if(connection[current][i] == 1) {
                if(d[i] == -1) {
                    d[i] = d[current] + 1;
                    t[i] = t[current] + 1;
                    current = i;
                    break;
                }
            }
        }
        if(i == N) {
            current = -1;
        }
    }
    sum = 0;
    for(i = 0; i < N; i ++) {
        sum += d[i] * t[i];
    }
    printf("%d\n", sum);

    for(i = 0; i < N; i ++) {
        free(connection[i]);
    }
    free(connection);
    free(d);
    free(t);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 간선을 추가할 때 오름차순으로 정렬되도록 삽입
void addEdge(Node** adjList, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;

    if (adjList[u] == NULL || adjList[u]->vertex > v) {
        // 리스트가 비었거나 첫 번째 노드보다 작은 경우
        newNode->next = adjList[u];
        adjList[u] = newNode;
    } else {
        // 적절한 위치를 찾아 삽입
        Node* temp = adjList[u];
        while (temp->next != NULL && temp->next->vertex < v) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main(void) {
    int N, M, R;
    int* d;
    int* t;
    Node** adjList;
    int i, sum;

    scanf("%d %d %d", &N, &M, &R);

    d = (int*)malloc(N * sizeof(int));
    t = (int*)malloc(N * sizeof(int));
    adjList = (Node**)malloc(N * sizeof(Node*));

    for (i = 0; i < N; i++) {
        adjList[i] = NULL;
        d[i] = -1; // 깊이 초기화
        t[i] = 0;  // 방문 순서 초기화
    }

    for (i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(adjList, a - 1, b - 1);
    }

    d[R - 1] = 0;
    t[R - 1] = 1;

    int visitOrder = 2; // 방문 순서 시작값
    int current = R - 1;
    while (current != -1) {
        Node* temp = adjList[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (d[neighbor] == -1) {
                d[neighbor] = d[current] + 1;
                t[neighbor] = visitOrder++;
                current = neighbor;
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            current = -1;
        }
    }

    sum = 0;
    for (i = 0; i < N; i++) {
        sum += d[i] * t[i];
    }
    printf("%d\n", sum);

    for (i = 0; i < N; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adjList);
    free(d);
    free(t);

    return 0;
}