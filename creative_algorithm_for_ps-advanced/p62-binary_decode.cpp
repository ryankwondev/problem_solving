#include <bits/stdc++.h>

using namespace std;

int N, cnt, cursor;
char arr[1000001];

int main() {
    scanf("%d", &N);
    scanf("%s", arr);

    for(int i=0; arr[i]; i++) {
        char str = arr[i];

        if(str == '\0')
            break;

        if(str == '-') {
            N/=2;
        }
        else if(str == '1') {
            for(int i=0; i<N; i++)
                printf("1");
        } else {
            for(int i=0; i<N; i++)
                printf("0");
        }
    }

    return 0;
}
