#include <cstdio>
#include <vector>

using namespace std;

int N;
int p[200001];
vector<int> children[200001];
int r[200001];

// 이거때문에 무조건 TLE
void changeRoot(int n, int newRoot) {
    r[n] = newRoot;
    for(int i=0; i<children[n].size(); i++)
        changeRoot(children[n][i], newRoot);
}

void removeChild(int parent, int child) {
    int i;
    for(i=0; i<children[parent].size(); i++) {
        if(children[parent][i] == child) break;
    }
    if(i == children[parent].size()) return;
    children[parent].erase(children[parent].begin() + i);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    p[1] = 1;
    for(int i=2; i<=N; i++) {
        scanf("%d", &p[i]);
        children[p[i]].push_back(i);
    }
    for(int i=1; i<=N; i++)
        r[i] = 1;

    int b, c, d, e;
    bool exists;
    for(int q=0; q<Q; q++) {
        scanf("%d %d %d", &b, &c, &d);
        // 경로 존재하는지 검사
        exists = r[b] == r[c];
        printf(exists? "YES\n": "NO\n");

        if(!d) continue;

        e = exists? b : c;
        if(r[e] == e) continue;
        removeChild(p[e], e);
        p[e] = e;
        changeRoot(e, e);
    }
    return 0;
}
