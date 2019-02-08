#include <iostream>
#include <queue>

using namespace std;

typedef unsigned long long ull;

struct Want {
    int want; // 원하는 사탕의 개수
    int count; // 원하는 친구의 수

    bool operator<(const Want& o) const {
        return want < o.want;
    }
};

int M, N;

int main() {
    priority_queue<Want> wants;
    cin >> M >> N;
    for(int i=0; i<N; i++) {
        int w;
        cin >> w;
        wants.push(Want{w, 1});
    }
    while(M>0) {
        Want w = wants.top();
        wants.pop();
        while(!wants.empty() && wants.top().want == w.want) {
            w.count += wants.top().count;
            wants.pop();
        }
        int target = 0;
        if(!wants.empty()) target = wants.top().want;

        int required = (w.want - target) * w.count;
        if(M >= required) {
            M -= required;
            wants.push(Want{target, w.count});
        } else {
            int equal = M / w.count;
            int left = M % w.count;
            wants.push(Want{w.want - equal - 1, left});
            wants.push(Want{w.want - equal, w.count - left});
            M = 0;
        }
    }
    ull rageSum = 0;
    while(!wants.empty()) {
        ull want = (ull) wants.top().want;
        ull count = (ull) wants.top().count;
        wants.pop();

        rageSum += want * want * count;
    }
    cout << rageSum;
    return 0;
}