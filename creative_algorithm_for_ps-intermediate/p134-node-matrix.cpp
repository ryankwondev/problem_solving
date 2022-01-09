#include <bits/stdc++.h>

using namespace std;

int N, M, arr[11][11], visited[11], mini = 987654321;

void func(int node, int s) {
    if(node == N) {
        mini = min(mini, s);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (arr[node][i] && !visited[i]) {
            visited[i] = 1;
            func(i, s + arr[node][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int tmpA, tmpB, tmpC;
        scanf("%d %d %d", &tmpA, &tmpB, &tmpC);
        if (tmpA == tmpB) continue;
        arr[tmpA][tmpB] = arr[tmpB][tmpA] = tmpC;
    }
    visited[1] = 1;
    func(1, 0);
    visited[1] = 0;
    printf("%d", mini);
    return 0;
}
