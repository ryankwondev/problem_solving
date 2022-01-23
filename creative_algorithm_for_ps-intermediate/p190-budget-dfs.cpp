#include <bits/stdc++.h>

using namespace std;

int B, N, arr[21], maxi;

void func(int idx, int sum) {
    if (sum > B)
        return;
    if (idx >= N) {
        maxi = max(maxi, sum);
        return;
    }

    func(idx + 1, sum);
    func(idx + 1, sum + arr[idx]);
}

int main() {
    scanf("%d", &B);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    func(0, 0);

    printf("%d", maxi);
    return 0;
}
