#include <cstdio>
#include <cstring>

char str[5001];
int mem[5000][5000];
int N;

int count(int index=0, int level=0) {
    if(mem[index][level]) return mem[index][level];
    if(index == N-1) return 1;

    if(str[index] == 'f')
        return mem[index][level] = count(index+1, level+1);
    else {
        mem[index][level] = count(index+1, level);
        for(int l = level-1; l>=0; l--) {
            mem[index][level] += count(index+1,level-1);
            mem[index][level] %= 1000000007;
        }
        return mem[index][level];
    }
}

int main() {
    scanf("%s", str);
    N = strlen(str);
    printf("%d\n", count());
    return 0;
}
