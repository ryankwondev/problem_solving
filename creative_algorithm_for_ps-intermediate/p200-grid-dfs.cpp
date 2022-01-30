#include <bits/stdc++.h>

using namespace std;

int H, W, cnt = 0;

void func(int x, int y) {
    if (x > W || y > H)
        return;

    if (H * x > W * y)
        return;

    if (x == W && y == H) {
        cnt++;
        return;
    }

    func(x + 1, y);
    func(x, y + 1);
}

int main() {
    scanf("%d %d", &H, &W);
    func(0, 0);
    printf("%d", cnt);
}
