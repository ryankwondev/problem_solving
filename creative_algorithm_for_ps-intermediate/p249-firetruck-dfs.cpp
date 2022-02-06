#include <bits/stdc++.h>

using namespace std;

int p, f, P[15], F[15], visited[15], mini = 987654321;

void func(int idx, int sum) {
    if (idx >= f) {
        mini = min(mini, sum);
        return;
    }

    for (int i = 0; i < p; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            func(idx + 1, sum + abs(P[i] - F[idx]));
            visited[1] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &p, &f);
    for (int i = 0; i < p; i++)
        scanf("%d", &P[i]);
    for (int i = 0; i < f; i++)
        scanf("%d", &F[i]);

    func(0, 0);

    printf("%d", mini);
    return 0;
}
