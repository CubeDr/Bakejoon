//
// Created by HyunI on 2019-07-04.
//

#include <cstdio>

typedef unsigned long long ull;

int upper_bound(int N, int base, ull target) { // O(logN)
    int start = 0;
    int end = N;

    // upper_bound
    while(end > start) {
        ull mid = (start + end) / 2;
        ull n = base * (mid + 1);
        if(n == target) return mid + 1;
        else if(n > target) end = mid ;
        else start = mid + 1;
    }
    return start;
}

ull k(int N, ull target) { // O(NlogN)
    ull sum = 0;
    for(int i=1; i<=N; i++) // O(N)
        sum += upper_bound(N, i, target); // O(logN)
    return sum;
}

ull solve(int N, int K) { // O(N (logN)^2)
    ull start = 1;
    ull end = (ull)N * N;

    while(end > start) { // O(logN)
        ull mid = (start + end) / 2;
        ull mk = k(N, mid); // O(NlogN)
        if(mk == K) end = mid;
        else if(mk < K) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%llu", solve(N, K));
    return 0;
}