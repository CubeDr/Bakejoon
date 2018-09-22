#include <iostream>

using namespace std;

int N;
int tp[16][2];
int mem[16];

// day 일의 상담을 해서 얻을 수 있는 최대 수익
int dp(int day = 0) {
    if(mem[day] != -1) return mem[day];
    if(tp[day][0]-1 > N-day) return mem[day] = 0;
    int money = tp[day][1];
    int max = 0;
    int t;
    for(int i=day+tp[day][0]; i<=N; i++) {
        t = dp(i);
        if(t > max) max = t;
    }
    return mem[day] = money + max;
}

int main() {
    cin >> N;
    fill(mem, mem+N+1, -1);
    tp[0][0] = 1;
    for(int i=1; i<=N; i++)
        for(int j=0; j<2; j++)
            cin >> tp[i][j];

    cout << dp();

    return 0;
}
