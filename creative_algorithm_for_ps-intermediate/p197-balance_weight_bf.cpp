#include <bits/stdc++.h>

using namespace std;

int arr[7] = {1, 3, 9, 27, 81, 243, 729};
int N, visited[7]; // visited left<0, right>0

void print() {
    printf("%d ", N);
    for (int i = 0; i < 7; i++)
        if (visited[i] < 0)
            printf("%d ", arr[i]);
    printf("0 ");
    for (int i = 0; i < 7; i++)
        if (visited[i] > 0)
            printf("%d ", arr[i]);
}

void func(int idx, int left, int right) {
    if (N + left == right) {
        print();
        return;
    }
    if (idx >= 7)
        return;

    // 1
    func(idx + 1, left, right);

    // 2
    visited[idx] = -1;
    func(idx + 1, left + arr[idx], right);
    visited[idx] = 0;

    // 3
    visited[idx] = 1;
    func(idx + 1, left, right + arr[idx]);
    visited[idx] = 0;
}

int main() {
    scanf("%d", &N);
    func(0, 0, 0);
    return 0;
}
