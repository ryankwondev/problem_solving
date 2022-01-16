#include <bits/stdc++.h>

using namespace std;

int N, arr[10][10], visited[10], mini = 987654321;

void func(int sum, int line) {
    if (line >= N - 1) {
        mini = min(mini, sum);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            func(sum + arr[line + 1][i], line + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < N; i++) {
        visited[i] = 1;
        func(arr[0][i], 0);
        visited[i] = 0;
    }

    printf("%d", mini);
    return 0;
}
