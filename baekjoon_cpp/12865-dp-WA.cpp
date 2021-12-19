#include <bits/stdc++.h>
using namespace std;

int N, K;
int DP[100000][100] = {{0,},};
int W[100]; int V[100];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d %d", &W[i], &V[i]);
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            DP[i][j] = V[i] + DP[i-1][j-W[i]];
        }
    }

    printf("%d", DP[N][K];)
}
