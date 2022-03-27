#include <bits/stdc++.h>

using namespace std;

int N, arr[100], cnt;

int func(int n, int k) {
    if (n == 0) {
        for (int i = 0; i < cnt; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    for (int i = min(n, k); i >= 1; i--) {
        arr[cnt++] = i;
        func(n - i, i);
        cnt--;
    }
}

int main() {
    scanf("%d", &N);
    func(N, N);
}
