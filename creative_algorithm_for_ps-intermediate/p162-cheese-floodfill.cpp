#include <bits/stdc++.h>

using namespace std;

int N, M, arr[100][100], timer, visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void resetVisited() {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            visited[i][j] = 0;
}

bool isClear() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (arr[i][j] == 1)
                return false;
    return true;
}

bool isInside(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M)
        return true;
    else
        return false;
}

void floodFill(int x, int y) { // Fill Air
    visited[x][y] = 1;
    arr[x][y] = 2; // Air
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isInside(nx, ny) && (arr[nx][ny] == 0 || arr[nx][ny] == 2) && !visited[nx][ny]) {
            floodFill(nx, ny);
        }
    }
}

int countAir(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        if (arr[x + dx[i]][y + dy[i]] == 2)
            cnt++;
    return cnt;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]); // MY FUCKING %d %d

    while (!isClear()) { // Fuck!
        resetVisited();
        floodFill(0, 0);
        timer++;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (arr[i][j] == 1)
                    if (countAir(i, j) >= 2)
                        arr[i][j] = 0;

        /* DEBUG
        printf("%d\n", timer);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
        printf("================================\n");
        system("PAUSE"); */
    }

    printf("%d", timer);
    return 0;
}
