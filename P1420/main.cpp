#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

class MaximumFlow {
typedef std::vector<std::map<int, int> > Graph;
typedef std::pair<int, int> Edge;
public:
    static const int MAX = 9999999;

    MaximumFlow(int n, bool isSequenced=false) {
        graph.resize(n);
        if(isSequenced) nodeCount = n;
        else nodeCount = 0;
    }
    int addNode() {
        if(graph.size() == nodeCount)
            graph.resize(++nodeCount);
        return nodeCount;
    }
    void addEdge(int u, int v, int c=1, bool undirected=false) {
        graph[u][v] += c;
        if(undirected) graph[v][u] += c;
        else graph[v][u] += 0;
    }
    int maximumFlow(int source, int sink) {
        int ans = 0;

        flow.clear();
        flow.resize(nodeCount);
        while(true) {
            int p[nodeCount];
            std::fill(p, p+nodeCount, -1);

            std::queue<int> q;
            q.push(source);
            int t;
            while(!q.empty()) {
                t = q.front();
                q.pop();
                if(t == sink) break;

                std::map<int, int>::iterator it;
                for(it = graph[t].begin(); it != graph[t].end(); it++) {
                    if(p[it->first] != -1) continue;
                    if(r(t, it->first) <= 0) continue;
                    q.push(it->first);
                    p[it->first] = t;
                }
            }

            if(p[sink] == -1) break;

            int min = MAX, res;
            t = sink;
            while(t != source) {
                res = r(p[t], t);
                if(res < min) min = res;
                t = p[t];
            }

            t = sink;
            while(t != source) {
                flow[p[t]][t] += min;
                flow[t][p[t]] -= min;
                t = p[t];
            }
            ans += min;
        }

        return ans;
    }

    void printGraph() {
        printGraph(graph);
    }
private:
    unsigned int nodeCount;
    // 각 노드에 연결된 노드들과 capacity
    Graph graph, flow;

    int r(int u, int v) {
        return graph[u][v] - flow[u][v];
    }

    void printGraph(Graph graph) {
        for(int i=0; i<graph.size(); i++) {
            std::cout << i << std::endl;
            for(std::map<int, int>::iterator it=graph[i].begin(); it!=graph[i].end(); it++) {
                std::cout << "\t" << it->first << " : " << it->second << std::endl;
            }
        }
    }
};

#define in(x) (2*(x))
#define out(x) (in(x)+1)

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int main() {
    int N, M;
    char map[100][101];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", map[i]);

    MaximumFlow mf(2*M*N, true);
    for(int i=0; i<M*N; i++)
        mf.addEdge(in(i), out(i));

    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            if(map[y][x] == '#') continue;

            int idx = y*M + x;
            for(int d=0; d<4; d++) {
                int X = x + dx[d];
                int Y = y + dy[d];
                if(X < 0 || X >= M || Y < 0 || Y >= N)
                    continue;
                if(map[Y][X] == '#') continue;
                mf.addEdge(out(idx), in(Y*M + X), 9999999);
            }
        }
    }

    int source = -1;
    int sink = -1;
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            if(map[y][x] == 'K') source = out(y*M+x);
            else if(map[y][x] == 'H') sink = in(y*M+x);
        }
    }

    int ans = mf.maximumFlow(source, sink);
    if(ans >= 9999999) ans = -1;
    printf("%d\n", ans);

    return 0;
}
