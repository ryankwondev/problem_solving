#include <bits/stdc++.h>

using namespace std;

int N, M, DP[100][10000]; // N개의 앱, C 비용까지.
int Mi[100], Ci[100], CostSum; // 앱별 메모리, 앱별 비용

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", Mi + i);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", Ci + i);
        CostSum += *(Ci + i);
    }

    DP[0][0] = 0;
/* Fuck this */
//    for (int i = 1; i <= N; i++) { // AppIndex
//        for (int j = 0; j <= CostSum; j++) { // Costs
//            if (j - Ci[i] >= 0)
//                DP[i][j] = max(DP[i - 1][j],
//                               DP[i - 1][j - Ci[i]] + Mi[i]);
//            else DP[i][j] = DP[i - 1][j];
//            printf("%d ", DP[i][j]);
//        }
//        printf("\n");
//    }

    for (int j = 0; j <= CostSum; j++) {
        for (int i = 1; i <= N; i++) {
            DP[i][j] = DP[i - 1][j];
            if (j - Ci[i] >= 0) DP[i][j] = max(DP[i][j], DP[i - 1][j - Ci[i]] + Mi[i]);

        }
    }

//    for (int i = 1; i <= N; i++) { // AppIndex
//        for (int j = 0; j <= CostSum; j++) { // Costs
//            printf("%d ", DP[i][j]);
//        }
//        printf("\n");
//    }

    for (int i = 0; i <= CostSum; i++) {
        if (DP[N][i] >= M) {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}
