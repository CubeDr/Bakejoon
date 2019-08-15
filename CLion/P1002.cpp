#include <cstdio>

using namespace std;

int sqrDist(int x1, int y1, int x2, int y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main() {
    int T;
    int x1, y1, r1, x2, y2, r2;
    scanf("%d", &T);
    for(int t=0; t<T; t++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int d = sqrDist(x1, y1, x2, y2);
        int s = r1 + r2;
        s *= s;
        if(x1 == x2 && y1 == y2) {
            if(r1 == r2) printf("-1\n");
            else printf("0\n");
        } else {
            if(d == s) printf("1\n");
            else if(d > s) printf("0\n");
            else printf("2\n");
        }
    }
    return 0;
}
