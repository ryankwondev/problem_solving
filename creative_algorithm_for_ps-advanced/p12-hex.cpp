#include <bits/stdc++.h>

using namespace std;

char ch[20] = {'0', '1', '2', '3',
               '4', '5', '6', '7',
               '8', '9', 'A', 'B',
               'C', 'D', 'E', 'F',
               'G', 'H', 'I', 'J'};

void func(int num, int notation) {
    if (num < notation)
        printf("%c", ch[num]);
    else {
        func(num / notation, notation);
        printf("%c", ch[num % notation]);
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    func(N, M);
    return 0;
}
