#include <cstdio>

bool isValid(int N, int M, int K, int t) {
    return N >= t*2 && M >= t && N+M >= t*3 + K;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int team = N/2 < M? N/2 : M;
    K -= (N + M - team*3);
    while(!isValid(N, M, K, team)) team--;
    printf("%d", team);
    return 0;
}