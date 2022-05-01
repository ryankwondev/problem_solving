#include <bits/stdc++.h>

using namespace std;

int N, M;
int a, b, X, Y;
int arr[501], DP[501][100];

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &a, &b, &X, &Y);
    for (int i = 1; i <= M; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            DP[i][j] = 1 << 32;
        }
    }

    for (int i = 1; i <= N; i++) {
        // 0번째 줄까지 고려했을 때
        // a -> i라인 까지의 최소해
        int dist = abs(a - i);

        if (dist == 0) {
            DP[0][i] = 0;
        } else {
            DP[0][i] = dist * Y;
        }

        printf("X%d: %d\t", i, DP[0][i]);
    }
    printf("\n");

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            // i번째 가로줄까지 고려했을 때
            // a -> j까지의 최소 cost

            if ((arr[i] == j) || (arr[i] + 1 == j)) {
                // 가로줄이 있다면
                printf("O%d: ", j);
                DP[i][j] = min(DP[i - 1][j] + X, DP[i - 1][j] + Y);
                printf("%d", DP[i][j]);
                //DP[i][j] = min(DP[i][j],
                //min(DP[i - 1][j - 1], DP[i - 1][j + 1]));
                if (arr[i] == j) { // 왼쪽에 라인
                    printf("R");
                    DP[i][j] = min(DP[i][j], DP[i - 1][j + 1]);
                } else { // 오른쪽에 라인
                    printf("L");
                    DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
                }
            } else {
                // 가로줄이 없다면
                printf("X%d: ", j);
                int dist = abs(a - j);
                printf("%d", DP[i - 1][j]);
                if (j - 1 > 0) {
                    DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - 1] + Y);
                }
                if (j + 1 <= M) {
                    DP[i][j] = min(DP[i][j], DP[i - 1][j + 1] + Y);
                }
            }
            printf("%d\t", DP[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("SOL: %d", DP[M][b]);
}
