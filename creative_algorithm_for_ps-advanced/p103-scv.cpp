#include <bits/stdc++.h>

using namespace std;

int N, M, arr[201][201], maxi;

void func(int x, int y, int count) {
    if (x == N && y == M)
        maxi = max(maxi, count + arr[x][y]);

    if (x + 1 <= N) {
        func(x + 1, y, count + arr[x][y]);
    }

    if (y + 1 <= M) {
        func(x, y + 1, count + arr[x][y]);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    func(0, 0, 0);

    printf("%d", maxi);

    return 0;
}
