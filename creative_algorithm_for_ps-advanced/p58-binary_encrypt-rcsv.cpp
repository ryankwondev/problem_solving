#include <bits/stdc++.h>
// 인텔리센스없이하는 그는...
// 메모자에 하다가 괄호완성 필요했음
using namespace std;

int N, arr[15];

bool arrchk(int st, int end) {
    int cks = arr[st];
    for(int i=st; i<=end; i++) {
        if(arr[i] != cks)
            return false;
    }
    return true;
}

// 네이밍센스 진짜 - ㅈ까
// 아맞다 깔려있음 뭐 
// 니가 인텔리센스 켰냐? ㄴ
// ㅇㅋ

void func(int st, int end, int len) {
    // if(len == 1) {
    //     printf("%d", arr[st]);
    // }

    if(!arrchk(st, end)) {
        printf("-");
        func(st, end-len/2, len/2);
        func(st+len/2, end, len/2);
    } else {
        printf("%d", arr[st]);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%1d", &arr[i]);
    }

    func(0, N-1, N);

    return 0;
}
