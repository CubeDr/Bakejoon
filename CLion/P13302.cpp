#include <cstdio>

using namespace std;

int cost[] = {10000, 25000, 37000, 0};
int duration[] = {1, 3, 5, 1};
int couponsGiven[] = {0, 1, 2, -3};

int N;
bool day[100];

int mem[100][41];
int dp(int from, int coupons) {
    if(from >= N) return 0;

    if(mem[from][coupons] != -1)
        return mem[from][coupons];

    if(from == N-1) {
        if(!day[from] || coupons>=3)
            return mem[from][coupons] = 0;
        else return mem[from][coupons] = cost[0];
    }

    if(!day[from]) return dp(from+1, coupons);

    int min = 99999999;
    for(int i=0; i<4 - (coupons<3); i++) {
        int t = cost[i] + dp(from+duration[i], coupons + couponsGiven[i]);
        if(t < min) min = t;
    }
    return mem[from][coupons] = min;
}

int main()
{
    int M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        day[i] = true;
    int d;
    for(int i=0; i<M; i++) {
        scanf("%d", &d);
        day[d-1] = false;
    }

    for(int i=0; i<100; i++)
            for(int k=0; k<41; k++)
                mem[i][k] = -1;

    printf("%d\n", dp(0, 0));

    return 0;
}
