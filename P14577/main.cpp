#include <cstdio>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef set<ll> S;
typedef map<ll, int> M;

struct Query {
    int what;
    ll L, R;
};

int tree[1000000];
int n, m;
ll original[100000];
ll changed[300001];
Query queries[100000];
int treeEnd;

void update(int index, int diff, int node=1, int start=1, int end=treeEnd) {
    if(start > index || end <= index) return;
    tree[node] += diff;
    if(start == end-1) return;
    int m = (start + end) / 2;
    update(index, diff, node*2, start, m);
    update(index, diff, node*2+1, m, end);
}

int rangeSum(int from, int to, int node=1, int start=1, int end=treeEnd) {
    if(start >= to || end <= from) return 0;
    if(start >= from && end <= to) return tree[node];
    int m = (start + end) / 2;
    return rangeSum(from, to, node*2, start, m) + rangeSum(from, to, node*2+1, m, end);
}

int kth(int k, int node=1, int start=1, int end=treeEnd) {
    if(start == end-1) return start;
    int m = (start+end)/2;
    if(tree[node*2] >= k) return kth(k, node*2, start, m);
    return kth(k-tree[node*2], node*2+1, m, end);
}

int main() {
    S candidates;
    M position;
    scanf("%d %d",&n, &m);
    for(int i=0; i<n; i++) {  // n  < 100000
        scanf("%lld", &original[i]);
        changed[i] = original[i];
        candidates.insert(original[i]);
    }

    for(int i=0; i<m; i++) { // m logn < 2000000
        scanf("%d", &queries[i].what);
        scanf("%lld", &queries[i].L);
        if(queries[i].what != 4) {
            scanf("%lld", &queries[i].R);
            switch(queries[i].what) { // log n
                case 1:
                    queries[i].L--;
                    changed[queries[i].L] += queries[i].R;
                    candidates.insert(changed[queries[i].L]);
                    break;
                case 2:
                    queries[i].L--;
                    changed[queries[i].L] -= queries[i].R;
                    candidates.insert(changed[queries[i].L]);
                    break;
                case 3:
                    candidates.insert(queries[i].L);
                    candidates.insert(queries[i].R);
                    break;
            }
        }
    }

    treeEnd = candidates.size(); // n < 100000
    for(auto it = candidates.begin(); it != candidates.end(); ++it, --treeEnd) {
        position[*it] = treeEnd;
        changed[treeEnd] = *it;
    }
    treeEnd = candidates.size()+1;

    for(int i=0; i<n; i++) // n logn < 2000000
        update(position[original[i]], 1);

    for(int i=0; i<m; i++) { // m logn < 2000000
        const Query &q = queries[i];
        switch(q.what) {
            case 1: // logn
                update(position[original[q.L]], -1);
                original[q.L] += q.R;
                update(position[original[q.L]], 1);
                break;
            case 2: // logn
                update(position[original[q.L]], -1);
                original[q.L] -= q.R;
                update(position[original[q.L]], 1);
                break;
            case 3: // logn
                printf("%d\n", rangeSum(position[q.R], position[q.L]+1));
                break;
            case 4: // logn
                printf("%lld\n", changed[kth((int)q.L)]);
                break;
        }
    }

    return 0;
}