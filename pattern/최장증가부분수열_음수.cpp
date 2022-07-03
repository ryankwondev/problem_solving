#include <bits/stdc++.h>

using namespace std;

long long N, idx, LIS[1000001], arr[1000001];


int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += 1000000000 + 1; // ㅎㅎ;;
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] > LIS[idx]) {
            LIS[++idx] = arr[i];
        } else {
            int cursor = lower_bound(LIS + 1, LIS + idx + 1, arr[i]) - LIS;
            LIS[cursor] = arr[i];
        }
//        printf("%d: %d\n", idx - 1, LIS[idx - 1]);

    }

    printf("%lld", idx);
    return 0;
}
