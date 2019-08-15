#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int L, K, C;
int ks[10001];
unordered_map<int, int> mem;
// 4
bool makable(int maxLength) {
    if(mem.find(maxLength) != mem.end()) return mem[maxLength] != -1;

    // 1
    int chance = C;
    int lastK = L;
    for(int kIdx = K-1; kIdx >= 0; kIdx--) {
        int k = ks[kIdx];
//        printf("%d\n", k);
        // maxLength가 넘어갔을 때
        if(lastK - k > maxLength) {
            // 이전 지점이 이미 잘린 지점이라면 불가능한 경우
            if(kIdx == K-1 || lastK == ks[kIdx+1]) {
                mem[maxLength] = -1;
                return false;
            }
            // 이전 지점에서 자르기
            lastK = ks[++kIdx];
            if(--chance == 0) break;
        }
    }

    if(chance) lastK = ks[1];
    else if(lastK > maxLength) lastK = -1;
    mem[maxLength] = lastK;
    return mem[maxLength] != -1;
}

int lower_bound() {
    int s = 1; // in
    int e = L; // in
    while(s < e) {
        int m = (s + e) / 2;
        if(makable(m)) e = m;
        else s = m+1;
    }
    return s;
}

int main() {
    scanf("%d %d %d", &L, &K, &C);
    for(int i=0; i<K; i++)
        scanf("%d", &ks[i]);
    ks[K++] = 0;
    sort(ks, ks+K);

//    makable(4);
    int min = lower_bound();
    printf("%d %d", min, mem[min]);

    return 0;
}