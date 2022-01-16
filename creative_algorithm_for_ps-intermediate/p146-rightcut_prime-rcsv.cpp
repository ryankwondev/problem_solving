#include <bits/stdc++.h>

using namespace std;

int N, arr[4] = {1, 3, 7, 9}, globalCnt;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void func(int n, int cnt) {
    if (cnt >= N) {
        printf("%d\n", n);
        globalCnt++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (isPrime(n * 10 + arr[i]))
            func(n * 10 + arr[i], cnt + 1);
    }
}

int main() {
    scanf("%d", &N);
    func(2, 1);
    func(3, 1);
    func(5, 1);
    func(7, 1);
    printf("%d\n", globalCnt);
    return 0;
}
