#include <bits/stdc++.h>

using namespace std;

int N, arr[15], diff = 987654321, A, B, C;

void func(int level, int a, int b, int c) {
    if (level >= N)
        if (a < b || b < c) {
            return;
        } else {
            if (a - c < diff) {
                diff = a - c;
                A = a, B = b, C = c;
            } else if (a - c == diff && A > a) {
                A = a, B = b, C = c;
            }
            return;
        }

    func(level + 1, a + arr[level], b, c);
    func(level + 1, a, b + arr[level], c);
    func(level + 1, a, b, c + arr[level]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    func(0, 0, 0, 0);
    printf("%d %d %d", A, B, C);
}
