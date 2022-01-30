#include <bits/stdc++.h>

using namespace std;

int N, arr[80];

bool isGood(int n) {
    for (int i = 1; i <= n / 2; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[n+1-i-j] == arr[n+1-j])
                cnt++;
        }
        if (cnt == i)
            return false;
    }
    return true;
}

void func(int length, int number) {
    if (!isGood(length))
        return;
    if (length == N) {
        for (int i=1; i<=length; i++)
            printf("%d", arr[i]);
        exit(0);
    }
    arr[length + 1] = 1;
    func(length + 1, 1);
    arr[length + 1] = 2;
    func(length + 1, 2);
    arr[length + 1] = 3;
    func(length + 1, 3);
}

int main() {
    scanf("%d", &N);
    arr[1] = 1;
    func(1,1);
}
