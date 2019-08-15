#include <cstdio>
#include <algorithm>

using namespace std;

struct Conf {
    int start;
    int end;

    bool operator<(const Conf& o) const {
        if(end != o.end) return end < o.end;
        return start < o.start;
    }
};

int N;
Conf confs[100000];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d %d", &confs[i].start, &confs[i].end);
    sort(confs, confs+N);
    int count = 0;
    int lastTime = 0;
    for(int i=0; i<N; i++) {
        const Conf& c = confs[i];
        if(c.start < lastTime) continue;
        count++;
        lastTime = c.end;
    }
    printf("%d", count);
    return 0;
}