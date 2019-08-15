//
// Created by HyunI on 2019-06-25.
//

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> buildGms(int number) {
    vector<int> gms;
    queue<int> q;
    q.push(0);
    while(q.front() <= number) {
        int n = q.front(); q.pop();
        gms.push_back(n);
        q.push(n * 10 + 4);
        q.push(n * 10 + 7);
    }
    gms.erase(gms.begin());
    return gms;
}

vector<int> bfs(int number, const vector<int> & gms) {
    vector<int> v(number+1, 0);

    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int value = q.front(); q.pop();
        if(value == number) break;

        for(int g : gms) {
            int next = value + g;
            if(next > number || v[next]) continue;
            v[next] = g;
            q.push(next);
        }
    }

    return v;
}

vector<int> reconstruct(int number, const vector<int> & track) {
    vector<int> reconstruct;
    if(!track[number]) {
        reconstruct.push_back(-1);
        return reconstruct;
    }

    int current = number;
    while(current) {
        int g = track[current];
        reconstruct.push_back(g);
        current -= g;
    }

    sort(reconstruct.begin(), reconstruct.end());

    return reconstruct;
}

vector<int> solve(int number) {
    // 1. 금민수 나열
    vector<int> gms = buildGms(number);
    // 2. bfs로 최소개수 구하기
    vector<int> track = bfs(number, gms);
    // 3. 재구성
    return reconstruct(number, track);
}

void printVector(const vector<int> & v) {
    for(int n : v) cout << n << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    printVector(solve(n));
    return 0;
}