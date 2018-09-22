#include <cstdio>
#include <vector>

using namespace std;

int N, M, K;

vector<int> able[1000];
int by[1000];
bool isFinal[1000];

void input() {
    scanf("%d %d %d", &N, &M, &K);
    int n, w;
    for(int i=0; i<N; i++) {
        scanf("%d", &n);
        for(int j=0; j<n; j++) {
            scanf("%d", &w);
            able[i].push_back(w-1);
        }
    }
    for(int i=0; i<M; i++)
        by[i] = -1;
}

bool tryDo(int p) {
    for(int i=0; i<able[p].size(); i++) {
        int j = able[p][i];
        if(isFinal[j]) continue;

        if(by[j] == -1) {
            by[j] = p;
            return true;
        }

        isFinal[j] = true;
        if(tryDo(by[j])) {
            isFinal[j] = false;
            by[j] = p;
            return true;
        }
    }
    return false;
}

int count() {
    int ans = 0;
    for(int i=0; i<N; i++)
        if(tryDo(i)) ans++;

    int extra = 0;
    for(int i=0; i<N && extra<K; i++)
        if(tryDo(i)) extra++;

    return ans + extra;
}

int main() {
    input();
    printf("%d\n", count());
    return 0;
}
