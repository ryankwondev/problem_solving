// Feedback : Var Split

#include <bits/stdc++.h>

using namespace std;

int wp[25][4], N, cnt;
// Waypoint
/* index 0: index_of_island
 * index 1: spring_power
 * index 2: with_orange, 1 - with ok; 0 - no ok
 * index 3: visited
 */

void func(int idx, int way) {
    printf("%d %d\n", idx, way);

    if (idx == 0 && way == 1) {
        cnt++;
        return;
    }

    if (idx == N - 1 || way == 1) {
        for (int i = idx - 1; i >= 0; i--) {
            if ((wp[idx][0] - wp[idx][1] <= wp[i][0]) && (wp[i][3] == 0) && (wp[i][2] == 1)) {
                func(i, 1);
            }
        }
    }

    if (way == 0) {
        for (int i = idx + 1; i < N; i++) {
            if (wp[i][0] <= wp[idx][0] + wp[idx][1]) {
                wp[i][3] = 1;
                func(i, 0);
                wp[i][3] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &wp[i][0], &wp[i][1], &wp[i][2]);

    func(0, 0);

    printf("%d", cnt % 1000);
    return 0;
}
