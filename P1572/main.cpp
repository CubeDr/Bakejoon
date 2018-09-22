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

    int kthNumber(int k) {
        int start = 1, end = n;
        int front;
        while(start < end) {
            int mid = (start + end)/2;
            front = sum(start, mid);
            if(front >= k) end = mid;
            else {
                start = mid+1;
                k -= front;
            }
        }
        return start;
    }
};


using namespace std;

int arr[250000];
int main() {
    int N, K, n;
    scanf("%d %d", &N, &K);
    FenwickTree tree(65537);

    long long ans = 0;
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<N; i++) {
        if(i>=K) tree.update(arr[i-K]+1, -1);
        tree.update(arr[i]+1, 1);
        if(i>=K-1) ans += (tree.kthNumber((K+1)/2)-1);
    }

    printf("%lld", ans);
    return 0;
}
