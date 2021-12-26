#include <bits/stdc++.h>

using namespace std;

int N, visited[101], cnt;
int inc[101], _dec[101];

void func(int line) {
    // printf("%d %d\n",line,cnt);
    if (line > N) {
        cnt++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && !_dec[line + i] && !inc[line - i + N]) {
            visited[i] = inc[line - i + N] = _dec[line + i] = 1;
            func(line + 1);
            visited[i] = inc[line - i + N] = _dec[line + i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    func(1);
    printf("%d", cnt);
}
