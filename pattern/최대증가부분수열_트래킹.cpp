#include <bits/stdc++.h>

using namespace std;

long long N, idx, LIS[1000001], arr[1000001], a[10000001];


int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] > LIS[idx]) {
            LIS[++idx] = arr[i];
            a[arr[i]] = idx;
        } else {
            int cursor = lower_bound(LIS + 1, LIS + idx + 1, arr[i]) - LIS;
            LIS[cursor] = arr[i];
            a[arr[i]] = cursor;
        }
    }
    stack<int> S;
    int t = idx;
    N = 1000;
    while (1) {
        if (t == a[N]) {
            t--;
            S.push(N);
            if (t == 0) break;
        }
        N--;
    }
    printf("%lld\n", idx);
    while (S.size()) {
        printf("%d ", S.top());
        S.pop();
    }
    return 0;
}
