#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define NONE (-2e9)

using namespace std;

int N;
bool contains[1000000] = {false,};
bool contained[1000000] = {false,};
bool checked[1000000] = {false,};
vector<pair<int, int> > xs;

bool isDown(int curY) { return curY < 0; }

int main()
{
    scanf("%d", &N);
    int lastY, x, y=NONE;
    int size=1;
    bool downwards=false;

    int firstX, firstY=NONE;
    for(int i=0; i<N; i++) {
        lastY = y;
        scanf("%d %d", &x, &y);
        if(lastY != NONE && (long long)lastY * y < 0) {
            xs.push_back(make_pair(x, size));
            if(isDown(y)) size++;
            if(xs.size() == 1) downwards = isDown(y);
        }
        if(firstY == NONE) {
            firstX = x;
            firstY = y;
        }
    }
    lastY = y;
    if(lastY != NONE && (long long)lastY * firstY < 0) {
        xs.push_back(make_pair(firstX, size));
        if(isDown(firstY)) size++;
        if(xs.size() == 1) downwards = isDown(firstY);
    }
    size--;

    if(downwards) xs[xs.size()-1].second = 1;
    sort(xs.begin(), xs.end());
    // for(int i=0; i<xs.size(); i++)
    //     printf("%2d -> %d\n", xs[i].first, xs[i].second);


    int c1=0, c2=0;
    int level = 0;
    bool check = false;
    for(int i=0; i<xs.size(); i++) {
        if(!checked[xs[i].second]) { // left
            if(level++ == 0) c1++;

            check = true;

            checked[xs[i].second] = true;
        } else { // right
            level--;

            if(check) c2++;
            check = false;
        }
    }

    printf("%d %d\n", c1, c2);

    return 0;
}
