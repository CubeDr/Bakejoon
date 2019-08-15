#include <cstdio>
#include <vector>
#include <algorithm>

#define ll long long

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

int N;
ll original[500000];
ll position[500000];

struct Player {
    ll ability;
    int original;

    bool operator< (const Player& o) {
        return ability > o.ability;
    }
};
void buildPositionArray() {
    Player players[N];
    for(int i=0; i<N; i++) {
        players[i].ability = original[i];
        players[i].original = i;
    }
    sort(players, players+N);
    for(int i=0; i<N; i++)
        position[players[i].original] = i+1;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%lld", &original[i]);
    buildPositionArray();

    FenwickTree fenwickTree(N);
    for(int i=0; i<N; i++) {
        fenwickTree.update(position[i], 1);
        printf("%lld\n", fenwickTree.sum(position[i]));
    }

    return 0;
}
