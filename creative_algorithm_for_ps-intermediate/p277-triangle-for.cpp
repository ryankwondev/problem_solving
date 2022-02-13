#include <bits/stdc++.h>

using namespace std;

int N, cnt;

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N - 1; i++) {
        for (int j = i; i + j < N; j++) {
            int k = N - i - j;
            if (abs(i - j) < k && k < i + j && j <= k) {
                cnt++;
                // printf("%d %d %d\n", i, j, k);
            }
        }
    }
    printf("%d", cnt);
}
