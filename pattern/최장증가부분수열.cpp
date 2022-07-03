#include <bits/stdc++.h>

using namespace std;

int N, idx, LIS[1000000], arr[1000000];


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] > LIS[idx]) {
            LIS[++idx] = arr[i];
        } else {
            int t = lower_bound(LIS + 1, LIS + 1 + idx, arr[i]) - LIS;
            LIS[t] = arr[i];
        }
//        printf("%d: %d\n", i, LIS[i]);
    }

    printf("%d", idx);
    return 0;
}
