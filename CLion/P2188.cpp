#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> want[2000];
int matchedCow[2000];
bool isChecking[2000];

bool matchCow(int cowIdx) {
    for(int i=0; i<want[cowIdx].size(); i++) {
        // cowIdx 가 원하는 축사
        int h = want[cowIdx][i];

        if(isChecking[h]) continue;
        isChecking[h] = true;

        if(matchedCow[h] != -1) {
            if(matchCow(matchedCow[h])) {
                matchedCow[h] = cowIdx;
                isChecking[h] = false;
                return true;
            }
        } else {
            matchedCow[h] = cowIdx;
            isChecking[h] = false;
            return true;
        }
    }
    return false;
}

int solve() {
    int count = 0;
    for(int i=0; i<N; i++)
        if(matchCow(i)) count++;
    return count;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        int c, t;
        scanf("%d", &c);
        for(int j=0; j<c; j++) {
            scanf("%d", &t);
            want[i*2].push_back(t-1);
            want[i*2+1].push_back(t-1);
        }
    }
    for(int i=0; i<M; i++)
        matchedCow[i] = -1;
    N *= 2;
    printf("%d\n", solve());
    return 0;
}
