#include <cstdio>
#include <vector>

using namespace std;

int N, M;

vector<int> able[1000];
int by[1000];
bool isFinal[1000];

void input() {
    scanf("%d %d", &N, &M);
    int p, n, w;
    for(int i=0; i<N; i++) {
        scanf("%d", &n);
        for(int j=0; j<n; j++) {
            scanf("%d", &w);
            able[i].push_back(w-1);
        }
    }
    for(int i=0; i<M; i++) by[i] = -1;
}

bool dfs(int i) {
    for(int js=0; js<able[i].size(); js++) {
        int j = able[i][js];
        if(isFinal[j]) continue;
        if(by[j]==-1) {
            by[j] = i;
            return true;
        } else {
            isFinal[j] = true;
            if(dfs(by[j])) {
                isFinal[j] = false;
                by[j] = i;
                return true;
            }
        }
    }
    return false;
}

int count() {
    int c = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<2; j++) {
            if(dfs(i)) c++;
        }
    }
    return c;
}

int main() {
    input();
    printf("%d\n", count());
    return 0;
}
