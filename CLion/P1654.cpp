#include <cstdio>

#define ull unsigned long long
#define MAX (((unsigned long long)1<<32) - 1)

using namespace std;

int K, N;
ull length[10000];

bool makable(ull l) {
    ull c = 0;
    for(int i=0; i<K; i++)
        c += length[i] / l;
    return c>=N;
}

int main() {
    scanf("%d %d", &K, &N);
    for(int k=0; k<K; k++)
        scanf("%llu", &length[k]);

    ull low=1;
    ull high=MAX;
    ull mid;
    while(low < high) {
        mid = (low + high + 1) / 2;
        if(makable(mid)) low = mid;
        else high = mid-1;
    }
    printf("%llu", high);
    return 0;
}
