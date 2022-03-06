#include <bits/stdc++.h>

using namespace std;

int N, arr[128][128], bl, wh;

bool checkSquare(int x, int y, int size, int color) {
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (arr[i][j] != color)
                return false;
    return true;
}

void func(int x, int y, int size) {
    if (checkSquare(x, y, size, 0)) {
        wh++;
        return;
    } else if (checkSquare(x, y, size, 1)) {
        bl++;
        return;
    } else {
        func(x, y, size / 2);
        func(x + size / 2, y, size / 2);
        func(x, y + size / 2, size / 2);
        func(x + size / 2, y + size / 2, size / 2);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    func(0, 0, N);
    printf("%d\n%d\n", wh, bl);
    return 0;
}
