#include <bits/stdc++.h>

using namespace std;

int numlen(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    int N, answ = 0;
    scanf("%d", &N);
    int len = numlen(N);

    for (int i = 0; i < len; i++) {
        answ += (N % 10) * pow(10, len - i - 1);
        N /= 10;
    }

    printf("%d", answ);
    return 0;
}
