#include <bits/stdc++.h>

using namespace std;

int func(int n, int m, int length) {
    if (n == m)
        return length;
    else
        if (n > m)
            return func(n/2, m, length+1);
        else
            return func(n, m/2, length+1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", func(n, m, 0));
    return 0;
}
