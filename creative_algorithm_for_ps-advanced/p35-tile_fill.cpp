#include <bits/stdc++.h>

int func(int n) {
    printf("%d\n", n);

    if (n == 1)
        return 1;
    else if (n == 2)
        return 3;
    else if (n == 3)
        return 5;

    if (n % 2 == 0) {
        return func(n / 2) * func(n / 2)
               + 2 * func(n / 2 - 1) * func(n / 2 - 1);
    } else {
        return func(n / 2) * func(n / 2 + 1)
               + 2 * func(n / 2) * func(n / 2 - 1);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", func(n) % m);
    return 0;
}
