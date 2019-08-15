#include <vector>
#include <string>
#include <queue>

#include <iostream>

using namespace std;

typedef vector<string> Map;

struct Point {
    int x, y;

    bool operator==(const Point & o) const {
        return x == o.x && y == o.y;
    }
};

struct State {
    // 좌표
    union {
        Point p;
        struct {
            int x, y;
        };
    };
    // 방향, 방문 상태, 시간
    /* 방문 상태는
     * 0: C[0] 방문
     * 1: C[1] 방문
     * 2: 방문 X
     */
    int d, v, t;

    void print() {
        cout << "(" << x << ", " << y << ") " << d << ", " << v << " : " << t  << endl;
    }
};

void findSpecialPoints(const Map & map, Point & S, Point C[]) {
    bool s = false;
    // 구하고 있는 C의 인덱스
    int cIdx = 0;
    for(int y=0; y<map.size(); y++) {
        for(int x=0; x<map[y].size(); x++) {
            if(map[y][x] == 'S') {
                s = true;
                S = {x, y};
            }
            else if(map[y][x] == 'C') C[cIdx++] = {x, y};
            if(s && cIdx == 2) return;
        }
    }
}

bool isMovable(const Map & map, int x, int y) {
    // 맵의 범위 안에 있고 막혀있지 않은지 검사
    return x >= 0 &&
        y >= 0 &&
        x < map[0].size() &&
        y < map.size() &&
        map[y][x] != '#';
}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int bfs(const Map & map, const Point & S, const Point C[]) {
    // 중복 방지용 방문 상태 저장
    bool visited[50][50][4][3] = {false,};

    queue<State> q;
    // 초기 상태
    for(int d=0; d<4; d++) {
        visited[S.x][S.y][d][2] = true;
        q.push({S.x, S.y, d, 2, 0});
    }

    while(!q.empty()) {
        State s = q.front(); q.pop();

        // C에 도달했는지 검사
        for(int c=0; c<2; c++) {
            // 목표 중 한 군데 도착했는데
            if(s.p == C[c]) {
                // 다른 곳에 방문한 상태면 여기까지 걸린 시간이 답
                if(s.v == 1-c) return s.t;
                // 다른 곳에 방문 안했으면 이곳을 먼저 방문했다고 체크
                s.v = c;
            }
        }

        // 갈 수 있는 방향 검사
        for(int d=0; d<4; d++) {
            // 이전에 움직인 방향과 같은 방향으로는 못감
            if(d == s.d) continue;

            // 갈 수 있는 좌표 계산
            int x = s.x + dx[d];
            int y = s.y + dy[d];
            // 갈 수 없거나 이미 방문했으면 스킵
            if(!isMovable(map, x, y) || visited[x][y][d][s.v]) continue;

            // 방문 체크
            visited[x][y][d][s.v] = true;
            q.push({x, y, d, s.v, s.t+1});
        }
    }
    return -1;
}

int minimumTime(const Map & map) {
    // 1. S, C 찾기
    Point S, C[2];
    findSpecialPoints(map, S, C);
    // 2. BFS
    return bfs(map, S, C);
}

Map inputMap() {
    int N, M;
    cin >> N >> M;

    Map map;
    for(int n=0; n<N; n++) {
        string str;
        cin >> str;
        map.push_back(str);
    }

    return map;
}

int main() {
    cout << minimumTime(inputMap());
    return 0;
}