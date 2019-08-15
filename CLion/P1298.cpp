#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> candidates[100];
int owner[100];
bool visited[100];

bool beOwner(int ownerIndex) {
    for(int i=0; i<candidates[ownerIndex].size(); i++) {
        int l = candidates[ownerIndex][i];
        if(visited[l]) continue;
        visited[l] = true;

        if(owner[l] == -1 || beOwner(owner[l])) {
            owner[l] = ownerIndex;
            visited[l] = false;
            return true;
        }
    }
    return false;
}

int solve() {
    int c = 0;
    for(int i=0; i<N; i++)
        if(beOwner(i)) c++;
    return c;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int p, l;
        scanf("%d %d", &p, &l);
        candidates[p-1].push_back(l-1);
    }
    for(int i=0; i<N; i++)
        owner[i] = -1;
    printf("%d\n", solve());
    return 0;
}
