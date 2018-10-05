#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef set<ll> S;
int n, m, d;
ll l;
ll x[500000];
S s;

ll ans = 0;

void update(S::const_iterator it, S::const_iterator begin, S::const_iterator end, bool add=true) {
    ll from = *it - l; // inclusive
    ll to = *it + l; // inclusive
    if(it != begin) {
        --it;
        if(*it + l >= from)
            from = *it + l + 1;
        ++it;
    }
    if(++it != end) {
        if(*it - l <= to)
            to = *it - l - 1;
    }

    if(from > to) return;

    ll diff = upper_bound(x, x+n, to) - lower_bound(x, x+n, from); // log l
    if(add) ans += diff;
    else ans -= diff;
}

int main() {
    scanf("%d %d %d %lld", &n, &m, &d, &l);
    for(int i=1; i<n; i++)
        scanf("%lld", &x[i]);
    ll z;
    pair<S::iterator, bool> p;
    for(int i=0; i<m; i++) {
        scanf("%lld", &z);
        p = s.insert(z);
        update(p.first, s.begin(), s.end());
    }

    ll from, to;
    for(int i=0; i<d; i++) {
        printf("%lld\n", ans);
        scanf("%lld %lld", &from, &to);
        auto it = s.find(from); // log l
        update(it, s.begin(), s.end(), false); // log l
        s.erase(it); // log l
        it = s.insert(to).first; // log l
        update(it, s.begin(), s.end()); // log l
    }
    printf("%lld\n", ans);

    return 0;
}