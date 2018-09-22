#include <cstdio>
#include <vector>

using namespace std;

struct MaximumSegmentTree {
    std::vector<int> tree;
    int length;
    int min;

    MaximumSegmentTree(const std::vector<int> &data, int minimum) {
        min = minimum;
        length = data.size();
        tree.resize(length * 4);
        init(data, 1, 0, length-1);
    }

    int init(const std::vector<int> &data, int node, int start, int end) {
        if(start == end) return tree[node] = data[start];
        int mid = (start + end)/2;
        int left = init(data, node*2, start, mid);
        int right = init(data, node*2+1, mid+1, end);
        return tree[node] = left>right?left:right;
    }

    int max(int from, int to, int node, int start, int end) {
        if(from<=start && to>=end) return tree[node];
        if(from > end || to < start) return min;
        int mid = (start + end)/2;
        int left = max(from, to, node*2, start, mid);
        int right = max(from , to, node*2+1, mid+1, end);
        return left>right?left:right;
    }

    int max(int from, int to) {
        return max(from, to, 1, 0, length-1);
    }

    int update(int index, int newValue, int node, int start, int end) {
        if(end < index || start > index) return tree[node];
        if(start == end) return tree[node] = newValue;
        int mid = (start + end)/2;
        int left = update(index, newValue, node*2, start, mid);
        int right = update(index, newValue, node*2+1, mid+1, end);
        return tree[node] = left>right? left : right;
    }

    int update(int index, int newValue) {
        update(index, newValue, 1, 0, length-1);
    }
};

struct MinimumSegmentTree {
    std::vector<int> tree;
    int length;
    int max;

    MinimumSegmentTree(const std::vector<int> &data, int maximum) {
        max = maximum;
        length = data.size();
        tree.resize(length * 4);
        init(data, 1, 0, length-1);
    }

    int init(const std::vector<int> &data, int node, int start, int end) {
        if(start == end) return tree[node] = data[start];
        int mid = (start + end)/2;
        int left = init(data, node*2, start, mid);
        int right = init(data, node*2+1, mid+1, end);
        return tree[node] = left<right?left:right;
    }

    int min(int from, int to, int node, int start, int end) {
        if(from<=start && to>=end) return tree[node];
        if(from > end || to < start) return max;
        int mid = (start + end)/2;
        int left = min(from, to, node*2, start, mid);
        int right = min(from , to, node*2+1, mid+1, end);
        return left<right?left:right;
    }

    int min(int from, int to) {
        return min(from, to, 1, 0, length-1);
    }

    int update(int index, int newValue, int node, int start, int end) {
        if(end < index || start > index) return tree[node];
        if(start == end) return tree[node] = newValue;
        int mid = (start + end)/2;
        int left = update(index, newValue, node*2, start, mid);
        int right = update(index, newValue, node*2+1, mid+1, end);
        return tree[node] = left<right? left : right;
    }

    void update(int index, int newValue) {
        update(index, newValue, 1, 0, length-1);
    }
};

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        vector<int> data(N);
        for(int i=0; i<N; i++)
            data[i] = i;

        MaximumSegmentTree maxTree(data, -1);
        MinimumSegmentTree minTree(data, 100000);

        int Q, A, B;
        int min, max;
        for(int i=0; i<K; i++) {
            scanf("%d %d %d", &Q, &A, &B);
            if(Q) {
                min = minTree.min(A, B);
                max = maxTree.max(A, B);
                if(min == A && max == B) printf("YES\n");
                else printf("NO\n");
            } else {
                int t = data[A];
                data[A] = data[B];
                data[B] = t;
                maxTree.update(A, data[A]);
                maxTree.update(B, data[B]);
                minTree.update(A, data[A]);
                minTree.update(B, data[B]);
            }
        }
    }
    return 0;
}
