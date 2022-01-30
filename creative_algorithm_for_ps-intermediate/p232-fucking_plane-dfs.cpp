#include <bits/stdc++.h>

using namespace std;

int N, K, mini = 987654321, visited[15];
pair<int, int> P[15];

int calcfuel(int locA, int locB) {
    int fi = (P[locA].first - P[locB].first) * (P[locA].first - P[locB].first);
    int se = (P[locA].second - P[locB].second) * (P[locA].second - P[locB].second);
    int calc = ceil(sqrt(fi + se));

    if (calc % 10 == 0)
        return calc / 10;
    else
        return calc / 10 + 1;
}

void func(int loc, int maxfuel, int cnt) {
    if (loc == N + 1) {
        mini = min(mini, maxfuel);
        return;
    }
    if (cnt > K)
        return;

    for (int i = 1; i <= N + 1; i++) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        func(i, max(maxfuel, calcfuel(loc, i)), cnt + 1);
        visited[i] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &P[i].first, &P[i].second);
    P[0].first = 0, P[0].second = 0;
    P[N + 1].first = 10000, P[N + 1].second = 10000;

    visited[0] = 1;
    func(0, 0, 0);
    printf("%d", mini);
}
