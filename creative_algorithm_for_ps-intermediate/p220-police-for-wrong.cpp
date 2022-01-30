#include <bits/stdc++.h>

using namespace std;

int N, M, D, p1x, p1y, p2x, p2y;
pair<int, int> P[15];

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
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
        if(p1_dist < p2_dist) {
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
