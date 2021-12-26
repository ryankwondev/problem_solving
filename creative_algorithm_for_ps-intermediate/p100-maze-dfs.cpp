#include <bits/stdc++.h>

using namespace std;

int h, w, visited[101][101];
int maze[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sx, sy, gx, gy;
char a[10000];

void func(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (maze[nx][ny] && !visited[nx][ny]) {
            visited[nx][ny] = visited[x][y] + 1;
            func(nx, ny);
        }

    }
}

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%s", a);
        for (int j = 0; a[j]; j++) {
            if (a[j] == 'S') {
                sx = i, sy = j + 1;
            } else if (a[j] == 'G') {
                gx = i, gy = j + 1;
                maze[i][j + 1] = 1;
            } else if (a[j] == '.') maze[i][j + 1] = 1;
        }

    }

    func(sx, sy);

    printf("%d", visited[gx][gy]);
  
    return 0;
}
