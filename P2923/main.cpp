#include <cstdio>

// 주어진 쌍에서 최대값의 최소를 찾는 함수
// A는 앞에서부터, B는 뒤에서부터 순회하여 최대값의 최소를 찾음
int getMax(const int arr[], const int brr[], // a, b의 값들
                int minA, int maxB, // a, b의 출발점
                int n) { // 총 쌍의 개수
    int a = minA;
    int b = maxB;

    int count = 0;
    int usedA = 0, usedB = 0;

    int max = 0;
    int sum;
    while(true) {
        // 이번 쌍의 합을 구함
        sum = a + b;
        if(sum > max) max = sum;

        // 이 숫자로 만들 수 있는 쌍의 개수
        count = arr[a]-usedA < brr[b]-usedB? arr[a]-usedA : brr[b]-usedB;
        n -= count;
        usedA += count;
        usedB += count;

        // 모든 쌍을 매칭시켰으면 루프 종료
        if(n == 0) break;

        // 해당 숫자를 모두 사용했으면 다음 숫자로 넘어감
        while(arr[a] == usedA) {
            a++;
            usedA = 0;
        }
        while(brr[b] == usedB) {
            b--;
            usedB = 0;
        }
    }
    return max;
}

int main() {
    int N;
    int arr[101], brr[101];
    for(int i=1; i<=100; i++)
        arr[i] = brr[i] = 0;

    scanf("%d", &N);
    int a, b;
    int minA=101, maxB=0;
    for(int n=1; n<=N; n++) {
        scanf("%d %d", &a, &b);
        arr[a]++;
        brr[b]++;
        if(a < minA) minA = a;
        if(b > maxB) maxB = b;
        // 매 라운드마다 최대값을 찾음
        printf("%d\n", getMax(arr, brr, minA, maxB, n));
    }
    return 0;
}