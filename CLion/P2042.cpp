#include <cstdio>

#define ll long long

using namespace std;

int N, M, K;
ll tree[4000000];

ll build(int node, int start, int end, const int v[]) {
    if(start == end) return tree[node] = v[start];
    int mid = (start+end)/2;
    return tree[node] = build(node*2, start, mid, v)
                      + build(node*2+1, mid+1, end, v);
}

ll buildSegmentTree() {
    int v[N];
    for(int i=0; i<N; i++)
        scanf("%d", &v[i]);

    return build(1, 0, N-1, v);
}

ll updateValue(int index, int newValue, int node=1, int start=0, int end=N-1) {
    if(start > index || end < index) return tree[node];
    if(start == end && start == index) return tree[node] = newValue;
    int mid = (start+end)/2;
    return tree[node] = updateValue(index, newValue, node*2, start, mid)
                      + updateValue(index, newValue, node*2+1, mid+1, end);
}

ll getSum(int from, int to, int node=1, int start=0, int end=N-1) {
    if(to < start || from > end) return 0;
    if(from <= start && to >= end) return tree[node];

    int mid = (start + end)/2;
    return getSum(from, to, node*2, start, mid)
        + getSum(from, to, node*2+1, mid+1, end);
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    buildSegmentTree();
    int a, b, c;
    for(int i=0; i<M+K; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a==1) updateValue(b-1, c);
        else if(a==2) printf("%lld\n", getSum(b-1, c-1));
    }
    return 0;
}
