#include <cstdio>
#include <queue>

#define M (2*('Z'-'A'+1))

using namespace std;

int c[M][M];
int f[M][M];

int r(int i, int j) {
    return c[i][j] - f[i][j];
}

int c2i(char c) {
    if(c >= 'a') return c-'a' + 'Z'-'A'+1;
    return c-'A';
}

void input() {
    int N, f;
    char as[2], bs[2];
    int a, b;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s %s %d", as, bs, &f);
        a = c2i(as[0]);
        b = c2i(bs[0]);
        c[a][b] += f;
        c[b][a] += f;
    }
}

int edmond_karp() {
    int p[M];

    int source = c2i('A');
    int sink = c2i('Z');
    while(true) {
        for(int i=0; i<M; i++) p[i] = -1;
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(t == sink) break;
            for(int i=0; i<M; i++) {
                if(i==t || p[i]!=-1) continue;
                if(r(t, i) > 0) {
                    p[i] = t;
                    q.push(i);
                }
            }
        }

        if(p[sink] == -1) {
            break;
        }

        int rv, min = 9999;
        int t = sink;
        while(t != source) {
            rv = r(p[t], t);
            if(rv < min) min = rv;
            t = p[t];
        }

        t = sink;
        while(t != source) {
            f[p[t]][t] += min;
            f[t][p[t]] -= min;
            t = p[t];
        }
    }

    int sum = 0;
    for(int i=0; i<M; i++) {
        if(i == source) continue;
        sum += f[source][i];
    }
    return sum;
}

int main() {
    input();
    printf("%d\n", edmond_karp());
    return 0;
}
