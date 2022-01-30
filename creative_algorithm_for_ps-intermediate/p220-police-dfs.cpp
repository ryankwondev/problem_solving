#include <bits/stdc++.h>

using namespace std;

int N, M, D, p1x, p1y, p2x, p2y, mini = 987654321;
pair<int, int> P[15];

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void func(int level, int p1x_, int p1y_, int p2x_, int p2y_, int dist) {
    if (level > N) {
        mini = min(mini, dist);
        return;
    }
    int p1_dist = dist(p1x_, p1y_, P[level].first, P[level].second);
    int p2_dist = dist(p2x_, p2y_, P[level].first, P[level].second);
    func(level + 1, P[level].first, P[level].second, p2x_, p2y_, dist+p1_dist);
    func(level + 1, p1x_, p1y_, P[level].first, P[level].second, dist+p2_dist);
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    p1x = p1y = 1;
    p2x = p2y = N;

    for (int i = 0; i < M; i++)
        scanf("%d %d", &P[i].first, &P[i].second);

    for (int i = 0; i < M; i++) {
        int p1_dist = dist(p1x, p1y, P[i].first, P[i].second);
        int p2_dist = dist(p2x, p2y, P[i].first, P[i].second);
        if (p1_dist < p2_dist) {
            p1x = P[i].first, p1y = P[i].second;
            D += p1_dist;
        } else {
            p2x = P[i].first, p2y = P[i].second;
            D += p2_dist;
        }
        // printf("%d %d : %d %d : %d\n", p1x, p1y, p2x, p2y, D);
    }

    printf("%d", D);
}
