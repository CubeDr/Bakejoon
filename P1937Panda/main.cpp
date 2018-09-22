#include <cstdio>

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int map[500][500];

int isInRange(int x, int y) {
    return x>=0 && y>=0 && x<n && y<n;
}

int mem[500][500];
int dp(int x, int y) {
    if(mem[y][x]) return mem[y][x];

    int max = 0;
    for(int i=0; i<4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(!isInRange(X, Y)) continue;
        if(map[Y][X] <= map[y][x]) continue;

        int t = dp(X, Y);
        if(t > max) max = t;
    }
    return mem[y][x] = max + 1;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);

    int max = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int t = dp(j, i);
            if(t > max) max = t;
        }
    }
    printf("%d\n", max);
    return 0;
}
