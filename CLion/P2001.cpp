#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

class Jewels {
private:
    unsigned long long d1 = 0; // 0~49
    unsigned long long d2 = 0; // 50~99

    static int count(int d) {
        int c = 0;
        while(d) {
            if(d%2) c++;
            d /= 2;
        }
        return c;
    }

public:
    bool get(unsigned int index) {
        unsigned long long *p = &d1;
        if(index >= 50) {
            p = &d2;
            index -= 50;
        }
        return ((*p) & (1ull << index)) > 0;
    }

    void set(unsigned int index, bool value) {
        unsigned long long *p = &d1;
        if(index >= 50) {
            p = &d2;
            index -= 50;
        }
        (*p) &= ~(1ull << index);
        (*p) |= (1ull << index);
    }

    int count() {
        return count(d1) + count(d2);
    }

    bool operator==(const Jewels & o) const {
        return d1 == o.d1 && d2 == o.d2;
    }

    unsigned long long hash() const {
        return d1 * d2;
    }
};

namespace std {
    template <>
    struct hash<Jewels> {
        size_t operator()(const Jewels & j) const {
            return j.hash();
        }
    };
}

struct State {
    int u;
    Jewels jewels;
};

struct Edge {
    int v, w;
    Edge(int v, int w): v(v), w(w) {}
};

bool contains(const vector<Jewels> & list, const Jewels & jewel) {
    for(const Jewels & j : list)
        if(j == jewel) return true;
    return false;
}

int solve(const vector<Edge> graph[], const bool hasJewels[]) {
    queue<State> q;
    unordered_map<Jewels, bool> visited[100];

    q.push({0});
    visited[0][Jewels()] = true;

    int max = 0;

    while(!q.empty()) {
        State s = q.front(); q.pop();
        Jewels j = s.jewels;
        int c = j.count();
//        cout << s.u << ", " << c << endl;
        if(s.u == 0) {
            if(c >= max) {
                if(hasJewels[0] && !j.get(0)) max = c + 1;
                else max = c;
            }
        }

        for(const Edge & e : graph[s.u]) {
            if(e.w < c) continue;
            if(visited[e.v][j]) continue;
            visited[e.v][j] = true;
            q.push({e.v, j});
        }

        if(hasJewels[s.u] && !j.get(s.u)) {
            j.set(s.u, true);
            c++;

            for(const Edge & e : graph[s.u]) {
                if(e.w < c) continue;
                if(visited[e.v][j]) continue;
                visited[e.v][j] = true;
                q.push({e.v, j});
            }
        }
    }

    return max;
}

void input(vector<Edge> graph[], bool hasJewel[]) {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        int island;
        cin >> island;
        hasJewel[island-1] = true;
    }

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].emplace_back(v-1, w);
        graph[v-1].emplace_back(u-1, w);
    }
}

int main() {
    vector<Edge> graph[100];
    bool hasJewel[100] = {false,};
    input(graph, hasJewel);
    cout << solve(graph, hasJewel);
    return 0;
}