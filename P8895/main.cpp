#include <cstdio>

long long mem[21][21][21];
long long dp(int n, int l, int r) {
    if(mem[n][l][r] != -1) return mem[n][l][r];

    if(n < l + r - 1) return mem[n][l][r] = 0;

    mem[n][l][r] = dp(n-1, l, r) * (n-2);
    if(l>1) mem[n][l][r] += dp(n-1, l-1, r);
    if(r>1) mem[n][l][r] += dp(n-1, l, r-1);

    return mem[n][l][r];
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);
        for(int i=0; i<=20; i++)
            for(int j=0; j<=20; j++)
                for(int k=0; k<=20; k++)
                    mem[i][j][k] = -1;
        mem[1][1][1] = 1;
        printf("%lld\n", dp(n, l, r));
    }
    return 0;
}
