#include <cstdio>
#include <vector>

using namespace std;

int N, M;
char classroom[80][81];
vector<int> connected[6400];

int main() {
    int T;
    for(int t=0; t<T; t++) {
        scanf("%d %d", &N, &M);
        for(int r=0; r<N; r++)
            scanf("%s", classroom[r]);
    }
    return 0;
}
