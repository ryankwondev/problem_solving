#include <bits/stdc++.h>

using namespace std;

int N, len, visited[10];

set<int> S;

int extnum(int n, int idx) {
    for (int i = 0; i < idx; i++)
        n /= 10;
    return n % 10;
}

int numlen(long long n) {
    if (n < 10)
        return 1;
    return numlen(n / 10) + 1;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

void func(int idx, int sum) {
    if (idx >= len) {
        if (isPrime(sum))
            S.insert(sum);
        return;
    }

    for (int i = 0; i < len; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            func(idx + 1, sum * 10 + extnum(N, i));
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    len = numlen(N);
    func(0, 0);

    if (S.size() == 0)
        printf("0");
    else
        while (!S.empty()) {
            printf("%d ", *S.begin());
            S.erase(S.begin());
        }

    return 0;
}
