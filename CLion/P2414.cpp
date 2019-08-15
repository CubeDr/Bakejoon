#include <cstdio>
#include <utility>

typedef std::pair<int, int> tile;

using namespace std;

int N, M;
char board[50][51];
tile tiles[50][50];
int connected[3000][3000];
int matchedWith[3000];
int rCount, cCount;

void buildTiles() {
    bool continuous = false;
    for(int r=0; r<N; r++) {
        continuous = false;
        for(int c=0; c<M; c++) {
            if(board[r][c] == '.') continuous = false;
            else {
                if(!continuous) rCount++;
                tiles[r][c].first = rCount;
                continuous = true;
            }
        }
    }

    continuous = false;
    for(int c=0; c<M; c++) {
        continuous = false;
        for(int r=0; r<N; r++) {
            if(board[r][c] == '.') continuous = false;
            else {
                if(!continuous) cCount++;
                tiles[r][c].second = cCount;
                continuous = true;
            }
        }
    }
}

void printTiles() {
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++)
            printf("%d,%d ", tiles[r][c].first, tiles[r][c].second);
        printf("\n");
    }
}

void buildConnection() {
    for(int r=0; r<N; r++) {
        for(int c=0; c<M; c++) {
            if(tiles[r][c].first == 0) continue;
            int u = tiles[r][c].first;
            int v = tiles[r][c].second;
            connected[u-1][v-1] = true;
        }
    }
}

bool isChecking[3000];
bool tryMatch(int rIdx) {
    for(int cIdx=0; cIdx<cCount; cIdx++) {
        if(!connected[rIdx][cIdx]) continue;
        if(isChecking[cIdx]) continue;

        if(matchedWith[cIdx] == -1) {
            matchedWith[cIdx] = rIdx;
            return true;
        }

        isChecking[cIdx] = true;
        if(tryMatch(matchedWith[cIdx])) {
            matchedWith[cIdx] = rIdx;
            return true;
        }
    }
    return false;
}

int bipartiteMatching() {
    for(int i=0; i<cCount; i++)
        matchedWith[i] = -1;

    int count = 0;
    for(int rIdx=0; rIdx<rCount; rIdx++) {
        for(int i=0; i<cCount; i++)
            isChecking[i] = false;
        if(tryMatch(rIdx)) count++;
    }
    return count;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", board[i]);
    buildTiles();
    // printTiles();
    buildConnection();
    printf("%d", bipartiteMatching());
    return 0;
}
