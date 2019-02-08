#include <cstdio>
#include <utility>
#include <cmath>

typedef std::pair<int, int> Point;

double mem[512][512];
Point points[512];

double dem[512][512];
double dist(int i, int j) {
    if(i == j) return 0;
    if(dem[i][j] != 0) return dem[i][j];

    int dx = points[i].first - points[j].first;
    int dy = points[i].second - points[j].second;
    return dem[i][j] = dem[j][i] = sqrt(dx*dx + dy*dy);
}

double min(double a, double b) {
    return a < b ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                mem[i][j] = dem[i][j] = 0;

        for(int i=0; i<N; i++)
            scanf("%d %d", &points[i].first, &points[i].second);

        mem[0][1] = dist(0, 1);
        for(int d=1; d<N-1; d++) {
            for(int t=0; t<d; t++) {
                if(mem[t][d+1] == 0) mem[t][d+1] = mem[t][d] + dist(d, d+1);
                else mem[t][d+1] = min(mem[t][d+1], mem[t][d] + dist(d, d+1));

                if(mem[d][d+1] == 0) mem[d][d+1] = mem[t][d] + dist(t, d+1);
                else mem[d][d+1] = min(mem[d][d+1], mem[t][d] + dist(t, d+1));
            }
        }

        double min = 999999999;
        for(int i=0; i<N-1; i++) {
            double v = mem[i][N-1] + dist(i, N-1);
            if(v < min) min = v;
        }
        printf("%lf\n", min);
    }
    return 0;
}