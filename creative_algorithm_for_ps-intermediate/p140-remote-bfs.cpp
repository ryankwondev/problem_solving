#include <bits/stdc++.h>

using namespace std;

int current, target, mini = 987654321;
int visited[41];

void func(int temp, int s) {
    if (temp == target) {
        mini = min(mini, s);
        return;
    }
    
    if (s > target - current || s > mini)
        return;
    
    if (temp < target) {
        if (visited[temp + 1] != 1) {
            visited[temp + 1] = 1;
            func(temp + 1, s + 1);
            visited[temp + 1] = 0;
        }

        if (visited[temp + 4] != 1) {
            visited[temp + 5] = 1;
            func(temp + 5, s + 1);
            visited[temp + 5] = 0;
        }

        if (visited[temp + 10] != 1) {
            visited[temp + 10] = 1;
            func(temp + 10, s + 1);
            visited[temp + 10] = 0;
        }
    } else {
        if (visited[temp - 1] != 1) {
            visited[temp - 1] = 1;
            func(temp - 1, s + 1);
            visited[temp - 1] = 0;
        }

        if (visited[temp - 5] != 1) {
            visited[temp - 5] = 1;
            func(temp - 5, s + 1);
            visited[temp - 5] = 0;
        }

        if (visited[temp - 10] != 1) {
            visited[temp - 10] = 1;
            func(temp - 10, s + 1);
            visited[temp - 10] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &current, &target);
    visited[current] = 1;
    func(current, 0);
    visited[current] = 0;
    printf("%d", mini);
    return 0;
}
