#include <bits/stdc++.h>

using namespace std;

int main() {
    char arr[50000];
    scanf("%s", arr);
    int len = strlen(arr);
    bool flag = true;

    for(int i=len-1; i>=0; i--) {
        if(arr[i] == '0' && flag) {
            continue;
        } else if(arr[i] != '0' || !flag) {
            printf("%c", arr[i]);
            flag = false;
        }
    }

    return 0;
}
