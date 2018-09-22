#include <cstdio>

#define WIN 2
#define LOSE 1

int mem[1000001][2];

int dp(int n, bool turn = true) {
    if(mem[n][turn]) return mem[n][turn];

    if(turn) {
        for(int take=1; take<=3 && take<=n; take++)
            if(dp(n-take, !turn) == WIN) return mem[n][turn] = WIN;
        return mem[n][turn] = LOSE;
    } else {
        for(int take=1; take<=3 && take<=n; take++)
            if(dp(n-take, !turn) == LOSE) return mem[n][turn] = LOSE;
        return mem[n][turn] = WIN;
    }
}


int main() {
    mem[0][true] = LOSE;
    mem[0][false] = WIN;

    int n;
    scanf("%d", &n);

    printf("%d\n", dp(n));

    printf(dp(n)==WIN?"YES":"NO");
    return 0;
}
