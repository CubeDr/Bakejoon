#include <cstdio>
#include <algorithm>

struct Box {
    int from;
    int to;
    int count;

    bool operator<(const Box& o) {
        return to < o.to;
    }
} boxes[10000];

int loads[2000]; // loads[i] : i ~ i+1 로 갈 때 싣고 있는 택배 수

int maxLoad(int from, int to) {
    int max = 0;
    for(int i=from; i < to; i++)
        if(loads[i] > max) max = loads[i];
    return max;
}

void addLoad(int from, int to, int load) {
    for(int i=from; i < to; i++)
        loads[i] += load;
}

void inputBox(Box& b) {
    scanf("%d %d %d", &b.from, &b.to, &b.count);
}

int main() {
    int N, C, M;
    scanf("%d %d %d", &N, &C, &M);

    for(int i=0; i<M; i++) inputBox(boxes[i]);
    std::sort(boxes, boxes+M);

    int ans = 0;
    for(int i=0; i<M; i++) {
        const Box& b = boxes[i];
        // 더 실을 수 있는 택배 수
        int more = C - maxLoad(b.from, b.to);
        int load = more < b.count? more : b.count;
        addLoad(b.from, b.to, load);
        ans += load;
    }

    printf("%d", ans);
    return 0;
}