#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct Jewel {
    int m, v;

    bool operator<(const Jewel& o) const {
        return m < o.m;
    }
};

int N, K;
Jewel jewels[300000];
int bags[300000];

int main() {
    scanf("%d %d", &N, &K);

    // 보석을 입력받고 크기 기준으로 올림차순 정렬
    for(int i=0; i<N; i++)
        scanf("%d %d",&jewels[i].m, &jewels[i].v);
    sort(jewels, jewels + N);

    // 가방을 입력받고 용량 기준으로 올림차순 정렬
    for(int i=0; i<K; i++)
        scanf("%d", &bags[i]);
    sort(bags, bags + K);

    priority_queue<int> js;
    int sum = 0, j = 0;
    for(int i=0; i<K; i++) {
        int bag = bags[i];
        // 이 가방에 담을 수 있는 모든 보석 삽입
        for(; j < N && jewels[j].m <= bag; j++)
            js.push(jewels[j].v);
        // 담을 수 있는 보석이 없으면 스킵
        if(js.empty()) continue;
        // 담을 수 있는 보석 중 가장 가치가 높은 보석을 담음
        sum += js.top();
        js.pop();
    }

    printf("%d", sum);

    return 0;
}