#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, cnt=0;
    scanf("%d", &N);
    for(int i=1; i<=N-2; i++)
        for(int j=i; j<=N-1; j++) {
            int k = N-i-j;
            if(k>=j&&k<i+j) cnt++;
        }
    printf("%d", cnt);
}
