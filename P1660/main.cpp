#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
int N;

int mem[300001];
void buildNums() {
    int n = 1;
    int next = 2;
    while(n <= N) {
        nums.push_back(n);
        mem[n] = 1;
        n += next*(next+1)/2;
        next++;
    }
}

int dp(int n) {
    if(mem[n] != -1) return mem[n];

    int min = 999999999, t;
    for(int i=0; i<nums.size() && n>=nums[i]; i++) {
        t = dp(n-nums[i]);
        if(t < min) min = t;
    }
    return mem[n] = min+1;
}

int main() {
    cin >> N;
    fill(mem, mem+300001, -1);
    buildNums();
    cout << dp(N);
    return 0;
}
