#include <cstdio>
#include <cmath>
#include <algorithm>

int n, t;
int sqrtN;
struct Query {
    int s, e;
    int i;

    bool operator<(const Query &o) const {
        if(s/sqrtN != o.s/sqrtN) return s < o.s;
        return e < o.e;
    }
};

typedef long long ll;

int arr[100000];
Query query[100000];

ll count[1000001];
ll sum = 0;

ll ans[1000000];

void add(int num) {
    ll n = ++count[num];
    sum += (2*n - 1) * num;
}

void sub(int num) {
    ll n = --count[num];
    sum -= (2*n + 1) * num;
}

int main() {
    scanf("%d %d", &n, &t);
    sqrtN = (int) sqrt(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<t; i++) {
        scanf("%d %d", &query[i].s, &query[i].e);
        query[i].s--;
        query[i].e--;
        query[i].i = i;
    }
    std::sort(query, query + t);

    const Query *now = &query[0];
    for(int i=now->s; i<=now->e; i++)
        add(arr[i]);
    ans[now->i] = sum;

    const Query *last = &query[0];
    for(int i=1; i<t; i++) {
        now = &query[i];

        // O(sqrt N)
        if(now->s > last->s) for(int j=last->s; j<now->s; j++) sub(arr[j]);
        else for(int j=now->s; j<last->s; j++) add(arr[j]);

        // O(sqrt N)
        if(now->e > last->e) for(int j=last->e+1; j<=now->e; j++) add(arr[j]);
        else for(int j=now->e+1; j<=last->e; j++) sub(arr[j]);

        ans[now->i] = sum;

        last = now;
    }

    for(int i=0; i<t; i++)
        printf("%lld\n", ans[i]);
    return 0;
}