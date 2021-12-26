#include <bits/stdc++.h>

using namespace std;

int N = 0, arr[30][30] = {0,}, visited[101][101], hole;
int cnt[30];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int func(int x, int y) {
    cnt[hole]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (arr[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            func(nx, ny);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (arr[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = 1;
                ++hole;
                func(i, j);
            }
    printf("%d\n", hole);
    sort(cnt + 1, cnt + 1 + hole);
    for (int i = 1; i <= hole; i++) printf("%d\n", cnt[i]);
    return 0;
}
