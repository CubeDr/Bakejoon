//
// Created by HyunI on 2019-06-16.
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int v, w;
    Edge(int v, int w): v(v), w(w) { }

    bool operator<(const Edge & o) const {
        return w > o.w;
    }
};
typedef vector<Edge> Adj;
typedef vector<Adj> Graph;

vector<int> findDistance(const Graph & graph, int V, int K) {
    vector<int> distances(V);
    fill(distances.begin(), distances.end(), -1);

    priority_queue<Edge> pq;
    pq.push(Edge(K, 0));
    while(!pq.empty()) {
        Edge edge = pq.top(); pq.pop();
        if(distances[edge.v] != -1 && distances[edge.v] < edge.w)
            continue;
        distances[edge.v] = edge.w;

        for(Edge next: graph[edge.v]) {
            // If it is better than now, push to pq
            if(distances[next.v] != -1 && distances[next.v] < edge.w + next.w)
                continue;
            pq.push(Edge(next.v, edge.w + next.w));
        }
    }

    return distances;
}

int main() {
    int V, E, K;
    scanf("%d %d %d", &V, &E, &K);
    K--;

    Graph adj(V);
    for(int i=0; i<E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        adj[u].push_back(Edge(v, w));
    }

    vector<int> distances = findDistance(adj, V, K);
    for(int d: distances) {
        if(d != -1) printf("%d\n", d);
        else printf("INF\n");
    }
    return 0;
}