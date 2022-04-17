#include <bits/stdc++.h>

using namespace std;

int DP[1000];
int N, M, skills[3];

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &skills[0], &skills[1], &skills[2]);

    for (int i = 0; i < 1000; i++)
        DP[i] = 987654321;
    DP[N] = 0;

    for (int i = N; i <= M; i++)
        for (int k = 0; k < 3; k++)
            DP[i + skills[k]] = min(DP[i + skills[k]], DP[i] + 1);

    printf("%d", DP[M]);
    return 0;
}
