#include <bits/stdc++.h>

using namespace std;

int N, W, DP[100][10000];
int Wi[100], Vi[100];

int main() {
    scanf("%d %d", &N, &W);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", Wi + i, Vi + i);
    }

    DP[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            DP[i][j] = max(DP[i - 1][j],
                           DP[i - 1][j - Wi[i]] + Vi[i]);
        }
    }

    printf("%d", DP[N][W]);

    return 0;
}
