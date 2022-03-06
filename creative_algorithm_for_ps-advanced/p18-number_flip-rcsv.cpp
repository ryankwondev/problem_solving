#include <bits/stdc++.h>

using namespace std;

void func(int num) {
    if (num == 0)
        return;

    if (num % 10 == 0 && num >= 10)
        func(num / 10);
    else {
        printf("%d", num % 10);
        func(num / 10);
    }
    
    return;
}

int main() {
    int num;
    scanf("%d", &num);
    func(num);
    return 0;
}
