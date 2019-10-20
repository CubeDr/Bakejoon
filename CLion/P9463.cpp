#include <cstdio>
#include <vector>

struct FenwickTree {
    std::vector<long long> tree;
    int n;

    FenwickTree(int size) {
        n = size;
        tree.resize(size+1, 0);
    }

    /**
     * index 는 1 부터 시작
    */
    void update(int index, int diff) {
        while(index <= n) {
            tree[index] += diff;
            index += (index & -index);
        }
    }

    /**
     * index 는 1 부터 시작
    */
    long long sum(int index) {
        long long ans = 0;
        while(index) {
            ans += tree[index];
            index -= (index & -index);
        }
        return ans;
    }

    /**
     * from, to 는 1 부터 시작
    */
    long long sum(int from, int to) {
        return sum(to) - sum(from-1);
    }
};

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    int up[100001];
    int down[100001];
    int pos[100001];
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &up[i]);
        for(int i=0; i<n; i++) scanf("%d", &down[i]);
        for(int i=0; i<n; i++) pos[down[i]] = i+1;

        FenwickTree tree(n);
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += tree.sum(pos[up[i]], n);
            tree.update(pos[up[i]], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
