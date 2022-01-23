#include <bits/stdc++.h>

using namespace std;

int M, N, arr[10], sum;

int main() {
    scanf("%d", &M);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = N - 1; i >= 0 && M > 0; i--) {
        int q = M / arr[i];
        int r = M % arr[i];

        sum += q;
        M = r;
    }

    printf("%d", sum);
    return 0;
}
