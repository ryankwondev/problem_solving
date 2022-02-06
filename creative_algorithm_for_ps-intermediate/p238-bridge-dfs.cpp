#include <bits/stdc++.h>

using namespace std;

char scroll[11];
char bridge[2][21];

int N, M, cnt; // N = scroll_len, M = bridge_len

void func(int scroll_idx, int bridge_idx, int bridge_case) {
    if (scroll_idx >= N - 1) {
        cnt++;
        return;
    }

    char ch = scroll[scroll_idx + 1];

    for (int i = bridge_idx + 1; i < M; i++) {
        if (bridge[1 - bridge_case][i] == ch)
            func(scroll_idx + 1, i, 1 - bridge_case);
    }
}

int main() {
    scanf("%s", scroll);
    scanf("%s", bridge[0]);
    scanf("%s", bridge[1]);
    N = strlen(scroll), M = strlen(bridge[0]);

    func(-1, -1, 0);
    func(-1, -1, 1);

    printf("%d\n", cnt);
    return 0;
}
