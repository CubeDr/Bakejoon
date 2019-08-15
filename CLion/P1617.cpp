#include <iostream>
#include <vector>

using namespace std;

int N;
long long sharks[50][3];

vector<int> connected[50];
int matchedWith[50];
bool isFinal[50];

bool tryMatch(int idx) {
    int o;
    for(int i=0; i<connected[idx].size(); i++) {
        o = connected[idx][i];
        if(isFinal[o]) continue;

        if(matchedWith[o] == -1) {
            matchedWith[o] = idx;
            return true;
        }

        isFinal[o] = true;
        if(tryMatch(matchedWith[o])) {
            matchedWith[o] = idx;
            return true;
        }
    }
    return false;
}

int count() {
    fill(matchedWith, matchedWith+N, -1);
    int c = 0;
    for(int i=0; i<2; i++) {
        for(int j=0; j<N; j++) {
            fill(isFinal, isFinal+N, false);
            if(tryMatch(j)) c++;
        }
    }
    return c;
}

bool edible(int i, int j) {
    int same = 0;
    for(int k=0; k<3; k++) {
        if(sharks[i][k] == sharks[j][k]) same++;
        if(sharks[i][k] < sharks[j][k]) return false;
    }

    return same < 3 || i < j;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<3; j++)
            cin >> sharks[i][j];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == j) continue;
            if(edible(i, j)) connected[i].push_back(j);
        }
    }

    cout << N-count() << endl;

    return 0;
}
