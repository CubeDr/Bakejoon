#include <cstdio>
#include <vector>

struct FenwickTree {
    std::vector<int> tree;

    FenwickTree(int size) {
        tree.resize(size+1);
        std::fill(tree.begin(), tree.end(), 0);
    }

    void update(int index, int diff) {
        while(index < tree.size()) {
            tree[index] += diff;
            index += (index & -index);
        }
    }

    int sum(int to) {
        int ans = 0;
        while(to) {
            ans += tree[to];
            to -= (to & -to);
        }
        return ans;
    }
};

using namespace std;

int main() {
    int N, L, R, l, r;
    scanf("%d", &N);
    FenwickTree tree(100001);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &L, &R);
        l = tree.sum(L);
        r = tree.sum(R);
        printf("%d\n", l+r);
        tree.update(L, -l);
        tree.update(L+1, l);
        tree.update(R, -r);
        tree.update(R+1, r);
        tree.update(L+1, 1);
        tree.update(R, -1);
    }

    return 0;
}
