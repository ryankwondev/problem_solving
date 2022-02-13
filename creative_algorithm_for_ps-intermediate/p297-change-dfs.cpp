#include <bits/stdc++.h>

using namespace std;

int M, N, arr[10], sum = 987654321;

void func(int bills, int cnt) {
    if (bills == 0) {
        sum = min(sum, cnt);
        return;
    }

    if (bills < 0)
        return;

    if (cnt > sum)
        return;

    for (int i = 0; i < N; i++) {
        if (bills >= arr[i])
            func(bills - arr[i], cnt + 1);
    }
}

int main() {
    scanf("%d", &M);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    func(M, 0);

    printf("%d", sum);
    return 0;
}
