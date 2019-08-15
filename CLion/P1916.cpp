//
// Created by HyunI on 2019-06-16.
//

#include <cstdio>
#include <vector>
#include <queue>

struct Edge {
    int v, w;

    Edge(int v, int w): v(v), w(w) {}

    bool operator<(const Edge& o) const {
        return w > o.w;
    }
};

using namespace std;

typedef vector<Edge> Adj;
typedef vector<Adj> Graph;

int shortestPath(const Graph & graph, int A, int B) {
    int distances[graph.size()];
    fill(distances, distances + graph.size(), -1);

    priority_queue<Edge> pq;
    pq.push(Edge(A, 0));

    while(!pq.empty()) {
        Edge edge = pq.top(); pq.pop();
        if(distances[edge.v] != -1 && distances[edge.v] < edge.w)
            continue;
        distances[edge.v] = edge.w;

        for(Edge adj: graph[edge.v]) {
            if(distances[adj.v] != -1 && distances[adj.v] < edge.w + adj.w)
                continue;
            pq.push(Edge(adj.v, edge.w + adj.w));
        }
    }
    return distances[B];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Graph graph(N);
    for(int i=0; i<M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        graph[u].push_back(Edge(v, w));
    }

    int A, B;
    scanf("%d %d", &A, &B);
    A--; B--;

    printf("%d", shortestPath(graph, A, B));

    return 0;
}