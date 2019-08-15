#include <cstdio>

typedef long long ll;

int POW2[21] = {1,};

int have[21];
ll needed[21];
int max = 0;

void calculateNeeded(ll l, ll w, ll h) {
    if(l * w * h == 0) return;
    int maxPow = 0;
    while(POW2[maxPow] <= l &&
          POW2[maxPow] <= w &&
          POW2[maxPow] <= h) maxPow++;
    maxPow--;
    if(maxPow > max) max = maxPow;
    int length = POW2[maxPow];
    ll lc = l / length;
    ll wc = w / length;
    ll hc = h / length;
    needed[maxPow] += lc * wc * hc;
    calculateNeeded(l, w, h % length);
    calculateNeeded(l, w % length, hc * length);
    calculateNeeded(l % length, wc * length, hc * length);
}

int main() {
    for(int i=1; i<21; i++)
        POW2[i] = POW2[i-1] * 2;

    int l, w, h;
    scanf("%d %d %d", &l, &w, &h);
    calculateNeeded(l, w, h);

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int base, count;
        scanf("%d %d", &base, &count);
        have[base] = count;
    }

    long long sum = 0;
    for(int i=max; i>0; i--) {
        if(needed[i] > have[i]) {
            needed[i - 1] += 8 * (needed[i] - have[i]);
            needed[i] = have[i];
        }
        sum += needed[i];
    }
    if(needed[0] > have[0]) sum = -1;
    else sum += needed[0];
    printf("%lld", sum);

    return 0;
}