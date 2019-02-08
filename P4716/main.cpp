#include <cstdio>
#include <algorithm>

struct Team {
    int needed;
    int dA, dB;

    bool operator<(const Team& o) const {
        int mDiff = dA>dB? dA-dB : dB-dA;
        int oDiff = o.dA>o.dB? o.dA-o.dB : o.dB-o.dA;
        return mDiff > oDiff;
    }
};

int give(int &needed, int &src, int d) {
    int ans = 0;
    if(needed > src) {
        ans = d * src;
        needed -= src;
        src = 0;
    } else {
        ans = d * needed;
        src -= needed;
        needed = 0;
    }
    return ans;
}

int giveBalloon(Team t, int &A, int &B) {
    if(t.dA < t.dB)
        return give(t.needed, A, t.dA) + give(t.needed, B, t.dB);
    else
        return give(t.needed, B, t.dB) + give(t.needed, A, t.dA);
}

int solve(int N, int A, int B) {
    Team teams[N];
    for(int i=0; i<N; i++)
        scanf("%d %d %d", &teams[i].needed, &teams[i].dA, &teams[i].dB);
    std::sort(teams, teams+N);

    int sum = 0;
    for(int i=0; i<N; i++)
        sum += giveBalloon(teams[i], A, B);
    return sum;
}

int main() {
    int N, A, B;
    while(true) {
        scanf("%d %d %d", &N, &A, &B);
        if(N==0) break;
        printf("%d\n", solve(N, A, B));
    }
    return 0;
}