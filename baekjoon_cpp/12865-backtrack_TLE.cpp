#include <bits/stdc++.h>
using namespace std;

int N, K; int maxival;
struct goods{
    int W;
    int V;
    bool used;
};

goods G[100];

void func(int weight, int value) {
    maxival = std::max(value, maxival);

    for(int i=0; i<N; i++) {
        if(!G[i].used && weight+G[i].W <= K){
            G[i].used = true;
            func(weight+G[i].W, value+G[i].V);
            G[i].used = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d %d", &G[i].W, &G[i].V);
    maxival = G[0].V;
    func(0, 0);
    printf("%d", maxival);
    return 0;
}
