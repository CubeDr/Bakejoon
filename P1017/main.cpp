#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime[2000];

void buildPrime() {
    isPrime[2] = isPrime[3] = true;
    for(int i=5; i<2000; i+=2) {
        isPrime[i] = true;
        for(int j=3; j*j<=i; j+=2) {
            if(isPrime[j] && i%j == 0) {
                isPrime[i] = false;
                break;
            }
        }
    }
}

vector<int> odd;
vector<int> even;
vector<int> *set1 = &odd;
vector<int> *set2 = &even;
int matchWith[50];
bool isFinal[50];

int matchTarget;

void input() {
    int N, n;
    cin >> N;
    matchTarget = N/2-1;
    for(int i=0; i<N; i++) {
        cin >> n;
        if(n%2) odd.push_back(n);
        else even.push_back(n);

        if(i==0) {
            if(n%2 == 0) {
                set1 = &even;
                set2 = &odd;
            }
        }
        matchWith[i] = -1;
    }
}

bool tryMatch(int idx) {
    for(int i=0; i<set2->size(); i++) {
        if(isFinal[i]) continue;
        if(!isPrime[set1->at(idx) + set2->at(i)]) continue;

        if(matchWith[i] == -1) {
            matchWith[i] = idx;
            return true;
        }

        isFinal[i] = true;
        if(tryMatch(matchWith[i])) {
            matchWith[i] = idx;
            return true;
        }
    }
    return false;
}

int count(int except) {
    fill(matchWith, matchWith+set2->size(), -1);

    int sum = 0;
    for(int i=1; i<set1->size(); i++) {
        for(int i=0; i<set2->size(); i++)
            isFinal[i] = i == except;
        if(tryMatch(i)) sum++;
    }
    return sum;
}

vector<int> solve() {
    vector<int> ans;
    for(int i=0; i<set2->size(); i++) {
        if(!isPrime[set1->at(0) + set2->at(i)]) continue;
        if(count(i) == matchTarget) ans.push_back(set2->at(i));
    }
    return ans;
}

int main() {
    buildPrime();

    input();

    vector<int> ans = solve();
    if(ans.size() == 0) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
