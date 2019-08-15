#include <iostream>
#include <cstring>

const int MAX = (10*11*11*11*11 + 10*11*11*11 + 10*11*11 + 10*11 + 10 + 1);
const int power11[] = { 1, 11, 121, 1331, 14641, 161051 };

using namespace std;

typedef long long ll;

int set(int state, int what, int count) {
    state = (state/power11[what+1]) * power11[what+1] + state % power11[what];
    state += count * power11[what];
    return state;
}

int get(int state, int what) {
    state %= power11[what+1];
    state -= state%power11[what];
    return state / power11[what];
}

int N;

void printState(int state) {
    for(int i=0; i<N; i++)
        cout << i << " : " << get(state, i) << endl;
}

ll mem[MAX][5][5];
// p1: 바로 전에 선택한 것, p2: p1 이전에 선택한 것
// 항상 p1 != p2
ll dp(int state, int p1, int p2) {
    // 메모이제이션
    if(mem[state][p1][p2] != -1) return mem[state][p1][p2];

    // 예외처리
    if(get(state, p1) == 0) return mem[state][p1][p2] = 0;
    if(get(state, p2) == 0) return mem[state][p1][p2] = 0;

    ll sum = 0;

    // 종료조건
    for(int i=0; i<N; i++) sum += get(state, i);
    if(sum == 2) return mem[state][p1][p2] = 1;

    // 점화식
    sum = 0;
    int prevState = set(state, p1, get(state, p1)-1);
    for(int i=0; i<N; i++) {
        if(i == p1 || i == p2) continue;
        sum += dp(prevState, p2, i);
    }

//    printState(state);
//    cout << p1 << ", " << p2 << " : " << sum << endl << endl;

    return mem[state][p1][p2] = sum;
}

ll solve(int state) {
    ll sum = 0;
    for(int p1 = 0; p1<N; p1++) {
        for(int p2 = 0; p2<N; p2++) {
            if(p1 == p2) continue;
            sum += dp(state, p1, p2);
        }
    }
    return sum;
}

void init() {
    for(int i=0; i<MAX; i++)
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                mem[i][j][k] = -1;
}

int main() {
    init();
    int state = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int v;
        cin >> v;
        state = set(state, i, v);
    }
    cout << solve(state);
    return 0;
}