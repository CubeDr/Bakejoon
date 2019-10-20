#include <cstdio>

int K;
bool ables[1001][1001];

bool canWin(int x, int y, int left) {
    return x + left >= y;
}

void buildAbles(int m = 0, int n = 0) {
    ables[m][n] = true;
    int k = (m>n?m:n)+1;
    int left = K-k;
    if(!canWin(m,n,left) || !canWin(n,m,left)) return;
    // 1. m °áÁ¤
    // 1-1. m Á¡¼ö ¶¡


}

int main()
{
    scanf("%d", &K);
    buildAbles();

    int C;
    scanf("%d", &C);

    int m, n;
    for(int i=0; i<C; i++) {
        scanf("%d %d", &m, &n);
        printf("%d\n", able[m][n]? 1 : 0);
    }
    return 0;
}
