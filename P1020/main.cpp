#include <iostream>
#include <cstring>

typedef long long ll;

using namespace std;

const int LINES[] = {
        6, 2, 5, 5, 4, 5, 6, 3, 7, 5
};

const ll WRONG = 1000000000000000;

ll POW[16] = {1, };

int N;
int number[15];

ll mem[200][15][2];

ll build(int s, int i, bool o) {
    if(s < 0) return WRONG;

    if(mem[s][i][o] != -1) return mem[s][i][o];
    if(i == N) {
        if (s == 0 && o) return mem[s][i][0] = 0;
        return mem[s][i][0] = WRONG;
    }

    for(int n=(o?0:number[i]); n<=9; n++) {
        ll v = build(s - LINES[n], i+1, o || n > number[i]);
        if(v == WRONG) continue;
        return n * POW[N-i-1] + v;
    }
    return mem[s][i][o] = WRONG;
}

int countSum(ll n, int N) {
    int sum = 0;
    while(n) {
        sum += LINES[n % 10];
        n /= 10;
        N--;
    }
    return sum + LINES[0] * N;
}

int main() {
    for(int i=1; i<16; i++) POW[i] = POW[i-1] * 10;
    memset(mem, -1, sizeof(mem));

    char num[16];
    std::cin >> num;
    N = strlen(num);
    int sum = 0;
    ll target = 0;
    for(int i=0; i<N; i++) {
        number[i] = num[i] - '0';
        sum += LINES[number[i]];
        target += number[i] * POW[N - 1 - i];
    }

    ll ans = build(sum, 0, false);
    if(ans == WRONG) {
        for(int i=0; i<N; i++) number[i] = 0;
        ans = build(sum, 0, true);
    }
//    cout << "target: "<< target << " => " << countSum(target, N) << endl;
//    cout << "answer: " << ans << " => " << countSum(ans, N) << endl;
    if(ans < target) ans += POW[N];
    cout << ans - target;
    return 0;
}