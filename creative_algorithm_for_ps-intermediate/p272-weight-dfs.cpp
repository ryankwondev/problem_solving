#include <bits/stdc++.h>

using namespace std;

int weight[7] = {1, 3, 9, 27, 81, 243, 729};
int N, visited[7];

void split(int num) {
    int arr[7] = {0,};
    for (int i = 6; i >= 0; i--) {
        arr[i] = num / weight[i];
        num %= weight[i];
    }
    for (int i = 0; i < 7; i++) {
        if (arr[i] == 1)
            printf("%d ", weight[i]);
    }
}

void print(int left, int right) {
    printf("%d ", N);
    split(left);
    printf("0 ");
    split(right);
}

void func(int left, int right) {
    if (left == right) {
        print(left - N, right);
        exit(0);
    }

    for (int i = 0; i < 7; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            func(left + weight[i], right);
            func(left, right + weight[i]);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    func(N, 0);
}
