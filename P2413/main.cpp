#include <cstdio>

int n;
int ns[50000]; // 현재 상태
int pos[50001]; // 원본의 위치

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &ns[i]);
        pos[ns[i]] = i;
    }

    for(int i=0; i<n; i++) {
        // 한번 바뀐 숫자면 더 바꾸지 않음
        if(pos[ns[i]] != i) continue;
        if(ns[i] == 1) continue;
        int j = pos[ns[i]-1];
        // 바꿀 필요가 없음
        if(j < i) continue;

        int t = ns[i];
        ns[i] = ns[j];
        ns[j] = t;
    }

    for(int i=0; i<n; i++)
        printf("%d ", ns[i]);
    return 0;
}