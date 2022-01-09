// Index Check needed

#include <bits/stdc++.h>

using namespace std;
int arr[20][20];

int main() {
    for (int i = 1; i <= 19; i++)
        for (int j = 1; j <= 19; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 1; i <= 19; i++)
        for (int j = 1; j <= 19; j++) {
            if (arr[i][j] == 0)
                continue;

            if (arr[i][j] != arr[i][j - 1]) {
                int cnt = 0;
                for (int k = 1; k <= 4; k++)
                    if (arr[i][j] == arr[i][j + k]) cnt++;
                if (cnt == 4 && arr[i][j] != arr[i][j + 5]) {
                    printf("%d\n%d %d", arr[i][j], i, j);
                    return 0;
                }

                cnt = 0;
                for (int k = 1; k <= 4; k++)
                    if (arr[i][j] == arr[i + k][j + k]) cnt++;
                if (cnt == 4 && arr[i][j] != arr[i + 5][j + 5]) {
                    printf("%d\n%d %d", arr[i][j], i, j);
                    return 0;
                }

                cnt = 0;
                for (int k = 1; k <= 4; k++)
                    if (arr[i][j] == arr[i + k][j]) cnt++;
                if (cnt == 4 && arr[i][j] != arr[i + 5][j]) {
                    printf("%d\n%d %d", arr[i][j], i, j);
                    return 0;
                }

                cnt = 0;
                for (int k = 1; k <= 4; k++)
                    if (arr[i][j] == arr[i - k][j + k]) cnt++;
                if (cnt == 4 && arr[i][j] != arr[i - 5][j + 5]) {
                    printf("%d\n%d %d", arr[i][j], i, j);
                    return 0;
                }
            }
        }
    printf("0\n");
    return 0;
}
