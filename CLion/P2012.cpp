#include <cstdio>
#include <algorithm>

typedef unsigned long long ull;

int N;
int ns[500001];

int abs(int n) {
    if(n>0) return n;
    return -n;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &ns[i]);
    N++;
    std::sort(ns, ns + N);
    ull sum = 0;
    for(int i=1; i<N; i++)
        sum += abs(i - ns[i]);
    printf("%lld", sum);
    return 0;
}