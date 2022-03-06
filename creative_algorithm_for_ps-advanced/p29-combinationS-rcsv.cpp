#include <bits/stdc++.h>

using namespace std;

int combination(int n, int r) {
    if (r == 0)
        return 1;
    return (n - r + 1) * combination(n, r - 1) / r;
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d", combination(n, r));
    return 0;
}
