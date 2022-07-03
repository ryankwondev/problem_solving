#include <bits/stdc++.h>

using namespace std;

int N, arr[10000], DP[1000], maxi;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        DP[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                DP[i] = max(DP[i], DP[j] + arr[i]);
            }
        }
        maxi = max(maxi, DP[i]);
//        printf("DP[%d]: %d\n", i, DP[i]);
    }

    printf("%d", maxi);
}
