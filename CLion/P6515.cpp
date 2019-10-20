#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Value {
    int freq;
    int left, leftFreq;
    int right, rightFreq;

    Value() {
        freq = left = right = leftFreq = rightFreq = 0;
    }

    Value operator+(const Value& o) const {
        Value v;
        v.freq = freq>o.freq? freq: o.freq;
        if(right == o.left) {
            int mid = rightFreq + o.leftFreq;
            if(mid > v.freq) v.freq = mid;
        }
        v.left = left;
        v.leftFreq = leftFreq;
        if(left == o.left) v.leftFreq += o.leftFreq;
        v.right = o.right;
        v.rightFreq = o.rightFreq;
        if(right == o.right) v.rightFreq += rightFreq;
        return v;
    }
};

const Value ZERO = Value();

Value tree[400000];
int arr[100000];
int n;

const Value& build(int node=1, int start=0, int end=n) {
    if(end == start+1) {
        tree[node].freq = 1;
        tree[node].left = tree[node].right = arr[start];
        tree[node].leftFreq = tree[node].rightFreq = 1;
        return tree[node];
    }

    int m = (start+end)/2;
    const Value& l = build(node*2, start, m);
    const Value& r = build(node*2 + 1, m, end);

    return tree[node] = l + r;
}

Value query(int i, int j, int node=1, int start=0, int end=n) {
    if(end <= i || start >= j) return ZERO;
    if(start >= i && end <= j) return tree[node];
    int m = (start + end) / 2;
    return query(i, j, node*2, start, m) + query(i, j, node*2+1, m, end);
}

int main() {
    int q, s, e;
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;

        scanf("%d", &q);
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        build();

        for(int i=0; i<q; i++) {
            scanf("%d %d", &s, &e);
            Value v = query(s-1, e);
            printf("%d\n", v.freq);
        }

    }
    return 0;
}