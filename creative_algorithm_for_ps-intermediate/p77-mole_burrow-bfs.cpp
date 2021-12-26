#include <bits/stdc++.h>

using namespace std;
queue<pair<int, int> > Q;
int N, hole;
int arr[50][50], visited[50][50], cnt[50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] == 1 && !visited[i][j]) {
                visited[i][j]++;
                hole++;
                Q.push({i, j});
                while (!Q.empty()) {
                    int x = Q.front().first;
                    int y = Q.front().second;
                    Q.pop();
                    cnt[hole]++;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (arr[nx][ny] && !visited[nx][ny]) {
                            visited[nx][ny] = 1;
                            Q.push({nx, ny});
                        };
                    }
                }
            }

    sort(cnt + 1, cnt + 1 + hole);
    printf("%d\n", hole);
    for (int i = 1; i <= hole; i++)
        printf("%d\n", cnt[i]);
    return 0;
}
