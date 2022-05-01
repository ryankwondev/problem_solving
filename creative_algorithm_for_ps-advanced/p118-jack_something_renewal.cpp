#include <bits/stdc++.h>

using namespace std;

int N, M;
int a, b, X, Y;
int arr[501], DP[501][100];

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &a, &b, &X, &Y);
    for (int i = 1; i <= M; i++)
        scanf("%d", arr + i);

    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= N; j++)
            DP[i][j] = 1 << 32;

    for (int i = 1; i <= N; i++) {
        int dist = abs(a - i);
        if (dist == 0)
            DP[0][i] = 0;
        else
            DP[0][i] = dist * Y;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if ((arr[i] == j) || (arr[i] + 1 == j)) {
                DP[i][j] = min(DP[i - 1][j] + X, DP[i - 1][j] + Y);
                if (arr[i] == j)
                    DP[i][j] = min(DP[i][j], DP[i - 1][j + 1]);
                else
                    DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
            } else {
//                if (j - 1 > 0)
//                    DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - 1] + Y);
//                if (j + 1 <= M)
//                    DP[i][j] = min(DP[i][j], DP[i - 1][j + 1] + Y);
                for (int k = 1; k <= N; k++) {
                    // k -> j 까지의 최단거리
                    // k -> j 다리를 놓아 옮겨오는 방법
                    // k -> j 다리를 제거하여 옮겨오는 방법
                }
            }
        }
    }

    printf("%d", DP[M][b]);
}
