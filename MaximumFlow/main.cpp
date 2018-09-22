#include <iostream>
#include <vector>
#include <map>
#include <queue>

class MaximumFlow {
typedef std::vector<std::map<int, int> > Graph;
typedef std::pair<int, int> Edge;
public:
    static const int MAX = 99999999;

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

using namespace std;

int N, M;

int cowIdx(int i) {
    return i+1;
}

int cageIdx(int i) {
    return i+N+1;
}

int main() {
    cin >> N >> M;
    int source = 0;
    int sink = N+M+1;
    MaximumFlow mf(N+M+2, true);
    for(int i=0; i<N; i++) {
        mf.addEdge(source, cowIdx(i));

        int n, c;
        cin >> n;
        for(int j=0; j<n; j++) {
            cin >> c;
            mf.addEdge(cowIdx(i), cageIdx(c-1));
        }
    }
    for(int i=0; i<M; i++)
        mf.addEdge(cageIdx(i), sink);

    cout << mf.maximumFlow(source, sink) << endl;

    return 0;
}
