#include <bits/stdc++.h>

using namespace std;

int N, M, tmpA, tmpB, flag;
int arr[200][200], visited[200];

void clearVisited() {
    for(int i=0; i<N; i++)
        visited[i] = 0;
    return;
}

void func(int node) {
    if (visited[node] == 0)
        visited[node] = 1;

    for (int i = 0; i < N; i++) {
        if (i == node || arr[node][i] == 0)
            continue;

        // Toggle Tip : 3 - visited[i]
        if (visited[node] == 1) {
            if (visited[i] == 1) {
                flag = 1;
                return;
            } else if (visited[i] == 0) {
                visited[i] = 2;
                func(i);
            }
        } else if (visited[node] == 2) {
            if (visited[i] == 2) {
                flag = 1;
                return;
            } else if (visited[i] == 0) {
                visited[i] = 1;
                func(i);
            }
        }
    }
}

int main() {
    scanf("%d", &N); // Node
    scanf("%d", &M); // Edge

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tmpA, &tmpB);
        arr[tmpA][tmpB] = arr[tmpB][tmpB] = 1;
    }

    for (int i = 0; i < N && flag == 0; i++) {
        clearVisited();
        func(i);
    }

    if (flag == 0)
        printf("OK\n");
    else
        printf("IMPOSSIBLE\n");

    return 0;
}
