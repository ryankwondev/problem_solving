#include <bits/stdc++.h>

using namespace std;

int N, M, arrM[100], arrC[100], mini = 987654321, visited[100];

void func(int mSum, int cSum) {
    if (mSum >= M) {
        mini = min(mini, cSum);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            func(mSum + arrM[i], cSum + arrC[i]);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arrM[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &arrC[i]);

    for (int i = 0; i < N; i++) {
        visited[i] = 1;
        func(arrM[i], arrC[i]);
        visited[i] = 0;
    }

    printf("%d", mini);
    return 0;
}
