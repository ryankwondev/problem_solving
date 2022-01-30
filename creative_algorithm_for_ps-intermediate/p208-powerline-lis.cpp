#include <bits/stdc++.h>

using namespace std;

int N, lis[500], maxi = 0;
pair<int, int> P[500];

bool cmp(pair<int, int> A, pair<int, int> B) {
    if (A.first == B.first)
        return A.second < B.second;
    else
        return A.first < B.first;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &P[i].first, &P[i].second);

    sort(P, P + N, cmp);

    for (int i = 0; i < N; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (P[j].second < P[i].second) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        maxi = max(maxi, lis[i]);
    }

    printf("%d\n", N - maxi);
}
