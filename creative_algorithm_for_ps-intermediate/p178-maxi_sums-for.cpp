// FUCKING PDF ENCODING
/*
6
6 -7 3 -1 5 2
*/

#include <bits/stdc++.h>

using namespace std;

int N, arr[100] = {0,}, maxi = -987654321, sum;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];
            maxi = max(maxi, sum);
        }
    }

    printf("%d\n", maxi);
    return 0;
}
