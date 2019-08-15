#include <cstdio>
#include <algorithm>

struct Position {
    int x, y;
};

int N, W;
Position pos[1001];

int dist(Position p1, Position p2) {
    int dx = p2.x - p1.x;
    if(dx<0) dx = -dx;
    int dy = p2.y - p1.y;
    if(dy<0) dy = -dy;
    return dx + dy;
}

int mem[1001][1001];
int result[1001][1001];

int dp(int i=0, int j=0) {
    if(mem[i][j] != -1) return mem[i][j];

    int next = (i>j?i:j) + 1;
    if(next == W+1) return 0;

    int cost;
    // 1¹ø °æÂûÂ÷
    if(i) cost = dist(pos[next], pos[i]);
    else cost = dist(pos[next], {1, 1});
    cost += dp(next, j);
    mem[i][j] = cost;
    result[i][j] = 0;

    // 2¹ø °æÂûÂ÷
    if(j) cost = dist(pos[next], pos[j]);
    else cost = dist(pos[next], {N, N});
    cost += dp(i, next);
    if(cost < mem[i][j]) {
        mem[i][j] = cost;
        result[i][j] = 1;
    }

    return mem[i][j];
}

int main() {
    scanf("%d %d", &N, &W);
    for(int i=1; i<=W; i++)
        scanf("%d %d", &pos[i].x, &pos[i].y);
    for(int i=0; i<1001; i++)
        std::fill(mem[i], mem[i]+1001, -1);
    printf("%d\n", dp());
    int o=0, t=0;
    for(int i=0; i<W; i++) {
        printf("%d\n", result[o][t]+1);
        if(result[o][t]) t++;
        else o++;
    }
    return 0;
}
