#include <cstdio>
#include <queue>

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

struct Pos {
    int x, y, t;
};

using namespace std;

int R, C;
char parkingLot[50][51];
int cCount = 0;
int pCount = 0;
int dist[100][100];

bool isP(int x, int y) {
    return parkingLot[y][x]>='0' && parkingLot[y][x]<'0'+pCount;
}

int idxP(int x, int y) {
    return parkingLot[y][x] - '0';
}

void findDists(int cIdx, int x, int y) {
    queue<Pos> q;
    q.push({x, y, 0});
    Pos p;
    while(!q.empty()) {
        p = q.front();
        q.pop();

        if(isP(p.x, p.y)) dist[cIdx][idxP(p.x, p.y)] = p.t;
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for(int r=0; r<R; r++)
        scanf("%s", parkingLot[r]);
    for(int r=0; r<R; r++)
        for(int c=0; c<C; c++)
            if(parkingLot[r][c] == 'P')
                parkingLot[r][c] = '0' + pCount++;
    return 0;
}
