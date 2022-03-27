#include <bits/stdc++.h>

#define cu (1<<n)
#define rt (1<<(n-1))
#define dn (1)
#define M (1<<(n+1))

int p[4][4] = {{100, 70, 40, 0},
               {70,  50, 30, 0},
               {40,  30, 20, 0},
               {0,   0,  0,  0}};
int n, tb[12][12], m[12][12][1 << 13];

int max(int a, int b) { return a > b ? a : b; }

int func(int x, int y, int stat) {
    printf("$ %d %d %d\n", x, y, stat);
    if (x == n) return 0;
    if (y == n) return func(x + 1, 0, stat);

    if (!m[x][y][stat]) {
        if (!(stat & cu)) {
            if (y + 1 < n && !(stat & rt))
                m[x][y][stat] = max(m[x][y][stat], func(x, y + 2, (stat << 2) % M) + p[tb[x][y]][tb[x][y + 1]]);
            if (x + 1 < n && !(stat & dn))
                m[x][y][stat] = max(m[x][y][stat], func(x, y + 1, ((stat | dn) << 1) % M) + p[tb[x][y]][tb[x + 1][y]]);
            m[x][y][stat] = max(m[x][y][stat], func(x, y + 1, (stat << 1) % M));
        } else m[x][y][stat] = max(m[x][y][stat], func(x, y + 1, (stat << 1) % M));
    }
    return m[x][y][stat];
}

int main() {
    char t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %1c", &t);
            tb[i][j] = {t == 'F' ? 3 : t - 'A'};
        }
    }
    printf("%d\n", func(0, 0, 0));
    return 0;
}
