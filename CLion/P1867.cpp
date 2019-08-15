#include <cstdio>

using namespace std;

int N;
bool connected[500][500];
int matchedWIth[500];
bool isChecking[500];

bool tryMatch(int cIdx) {
    for(int rIdx=0; rIdx<N; rIdx++) {
        if(!connected[cIdx][rIdx]) continue;
        if(isChecking[rIdx]) continue;

        if(matchedWIth[rIdx] == -1) {
            matchedWIth[rIdx] = cIdx;
            return true;
        }

        isChecking[rIdx] = true;
        if(tryMatch(matchedWIth[rIdx])) {
            matchedWIth[rIdx] = cIdx;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    for(int i=0; i<N; i++)
        matchedWIth[i] = -1;

    int count = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) isChecking[j] = false;
        if(tryMatch(i)) count++;
    }
    return count;
}

int main() {
    int K;
    scanf("%d %d", &N, &K);
    int c, r;
    for(int k=0; k<K; k++) {
        scanf("%d %d", &c, &r);
        connected[c-1][r-1] = true;
    }
    printf("%d", bipartiteMatch());
    return 0;
}
