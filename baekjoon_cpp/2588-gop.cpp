#include <bits/stdc++.h>

using namespace std;

int intlen(int var) { // -> int 변수의 길이
    int cnt = 1;

    while (var >= 10) {
        var /= 10;
        cnt++;
    }

    return cnt;
}

int sliceint(int var, int idx) {
    var /= (int) pow(10, idx);
    var %= 10;

    return var;
}

int main() {
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < intlen(M); i++) {
        printf("%d\n", N * sliceint(M, i));
    }

    printf("%d", N * M);

    return 0;
}
