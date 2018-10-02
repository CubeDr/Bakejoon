#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> V;

V tree[400000];
int arr[100000];
int n;

void printVector(const V &v) {
    printf("[");
    for(int i=0; i<v.size(); i++)
        printf("%d ", v[i]);
    printf("]\n");
}

void mergeSort(V &v, const V &v1, const V &v2) {
    v.resize(v1.size() + v2.size());
    int i=0;
    for(int l=0, r=0; l<v1.size() || r<v2.size();) {
        if(l == v1.size())
            v[i++] = v2[r++];
        else if(r == v2.size())
            v[i++] = v1[l++];
        else if(v1[l] < v2[r])
            v[i++] = v1[l++];
        else v[i++] = v2[r++];
    }
}

const V& build(int node=1, int start=0, int end=n) {
    if(start == end-1) {
        tree[node].push_back(arr[start]);
        return tree[node];
    }

    int mid = (start+end)/2;
    mergeSort(tree[node], build(node*2, start, mid), build(node*2+1, mid, end));
    return tree[node];
}

int get(int i, int j, int k, int node=1, int start=0, int end = n) {
    if(j <= start || i >= end) return 0;
    if(i <= start && j >= end)
        return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    int m = (start+end)/2;
    return get(i, j, k, node*2, start, m) + get(i, j, k, node*2+1, m, end);
}

int query(int i, int j, int k) {
    int low = -1000000001, high = 1000000001;
    int m, v;
    while(low < high) {
        m = (low + high - 1) / 2;
        v = get(i, j, m);
        if(v < k) low = m+1;
        else high = m;
    }
    return low;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    build();
    int i, j, k;
    for(int q=0; q<m; q++) {
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", query(i-1, j, k));
    }
    return 0;
}
