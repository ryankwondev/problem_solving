#include <bits/stdc++.h>

using namespace std;

int N, cnt;

void func(int stage) {
    if (stage == N) {
        cnt++;
        return;
    } else if (stage > N)
        return;

    func(stage + 1);
    func(stage + 2);
}

int main() {
    scanf("%d", &N);
    func(0);
    printf("%d", cnt);
    return 0;
}
