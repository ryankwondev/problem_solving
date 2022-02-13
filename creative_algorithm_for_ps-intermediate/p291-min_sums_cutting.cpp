#include <bits/stdc++.h>

using namespace std;

int N, arr[10][10], visited[10], mini = 987654321;

void reset_visited() {
    for (int i = 0; i < 10; i++)
        visited[i] = 0;
}

void greedy() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int mini_var = 987654321, mini_idx = 0;
        for (int j = 0; j < N; j++) {
            if (mini_var < arr[i][j]) {
                mini_var = arr[i][j];
                mini_idx = j;
            }
        }
        visited[mini_idx] = 1;
        sum += arr[i][mini_idx];
    }
    mini = sum;
    reset_visited();
}

void func(int sum, int line) {
//    printf("%d %d\n", sum, line);

    if (line >= N - 1) {
        mini = min(mini, sum);
        return;
    }

    if (sum > mini)
        return;

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

    greedy();

    for (int i = 0; i < N; i++) {
        visited[i] = 1;
        func(arr[0][i], 0);
        visited[i] = 0;
    }

    printf("%d", mini);
    return 0;
}
