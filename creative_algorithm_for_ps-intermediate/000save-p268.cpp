#include <bits/stdc++.h>

using namespace std;

int N, len, visited[10];

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
    if (n <= 2)
        return true;

    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

void func(int idx, int sum) {
    if (idx == len) {
        if (isPrime(sum))
            printf("%d ", sum);
        return;
    }

    for (int i = 0; i < len; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            sum = sum * 10 + extnum(N, i);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    len = numlen(N);
    func(0, 0);
}
