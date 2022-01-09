#include <bits/stdc++.h>

using namespace std;

int N, M, W, H, arr[100][100], maxi = -1;

int sum(int x1, int y1, int x2, int y2) {
    int S = 0;

    for (int i = x1; i < x2; i++)
        for (int j = y1; j < y2; j++)
            S += arr[i][j];

    return S;
}


int main() {

    scanf("%d %d", &N, &M); // N = 2, M = 6
    scanf("%d %d", &W, &H); // W = 1, H = 3

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i <= M - H; i++)
        for (int j = 0; j <= N - W; j++)
            maxi = max(maxi, sum(i, j, i + W, j + H));

    printf("%d", maxi);
    return 0;
}
