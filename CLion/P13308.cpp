#include <cstdio>
#include <queue>

struct Node {
    int u;
    int dist;

    bool operator<(const Node& o) {
        return dist > o.dist;
    }
};

using namespace std;

int N, M;
int cost[2501];
int graph[2501][2501];
int minDist[2501];

// u ~ N 의 최소거리
int dijkstra(int u) {

    priority_queue<Node> q;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &cost[i]);

    int u, v, c;
    for(int i=0; i<M; i++) {
        scanf("%d %d %d", &u, &v, &c);
        graph[u][v] = graph[v][u] = c;
    }

    return 0;
}
