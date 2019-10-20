#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int tree[200001];
int position[100000];
int top;

void build() {
    fill(tree, tree+n+m, 0);
    int v;
    for(int i=1; i<=n+m; i++) {
        v = i & -i;
        if(i > n) v -= (i-n);
        if(v < 0) v = 0;
        tree[i] = v;
    }
    for(int i=0; i<n; i++)
        position[i] = n-i;
    top = n+1;
}

int sum(int i) {
    int ans = 0;
    while(i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int sum(int i, int j) {
    return sum(j) - sum(i-1);
}

// 추가할 경우 1, 뺄 경우 -1
void update(int i, int v) {
    while(i <= n+m) {
        tree[i] += v;
        i += (i & -i);
    }
}

int count(int dvd) {
    return sum(position[dvd], n+m)-1;
}

int watch(int dvd) {
    int ans = count(dvd);
    update(position[dvd], -1);
    position[dvd] = top++;
    update(position[dvd], 1);
    return ans;
}

int main() {
    int T, dvd;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        build();
        for(int i=0; i<m; i++) {
            scanf("%d", &dvd);
            printf("%d ", watch(dvd-1));
        }
        printf("\n");
    }
    return 0;
}
