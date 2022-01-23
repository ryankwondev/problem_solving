#include <bits/stdc++.h>

using namespace std;

int N, W, maxi;
int wi[100], vi[100];

void func(int idx, int weight, int value) {
    if (weight > W)
        return;
    if (idx >= N) {
        maxi = max(maxi, value);
        return;
    }

    func(idx + 1, weight, value);
    func(idx + 1, weight + wi[idx], value + vi[idx]);
}

int main() {
    scanf("%d", &N);
    scanf("%d", &W);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &wi[i], &vi[i]);

    func(0, 0, 0);

    printf("%d", maxi);
    return 0;
}
