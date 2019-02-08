#include <cstdio>
#include <queue>
#include <algorithm>

#define ABS(x) ((x)>0?(x):(-(x)))

using namespace std;

int desc(int v1, int v2) {
    return v1 > v2;
}

int main() {
    int N, M;
    priority_queue<int> ps, ns;

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        int t;
        scanf("%d", &t);
        if(t>0) ps.push(t);
        else ns.push(-t);
    }

    int count = 0;
    if(ns.empty()) {
        count = ps.top();
        for(int i=0; i<M && !ps.empty(); i++)
            ps.pop();
    } else if(ps.empty()) {
        count = ns.top();
        for(int i=0; i<M && !ns.empty(); i++)
            ns.pop();
    } else if(ns.top() > ps.top()) {
        count = ns.top();
        for(int i=0; i<M && !ns.empty(); i++)
            ns.pop();
    } else {
        count = ps.top();
        for(int i=0; i<M && !ps.empty(); i++)
            ps.pop();
    }

    while(!ns.empty()) {
        count += ns.top() * 2;
        for(int i=0; i<M && !ns.empty(); i++)
            ns.pop();
    }
    while(!ps.empty()) {
        count += ps.top() * 2;
        for(int i=0; i<M && !ps.empty(); i++)
            ps.pop();
    }

    printf("%d", count);

    return 0;
}