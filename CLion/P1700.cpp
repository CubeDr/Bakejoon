#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

// 각 전기용품들이 사용되는 시간
queue<int> nexts[101];
// 입력받은 전기용품 사용 순서
int ks[100];
// 현재 전기용품들이 꽂혀있는 멀티탭 상태
vector<int> mult;

// 현재 꽂혀있는 것 중에 가장 나중에 나오는 것 반환
int findLastKIdx() {
    int lastNext = -1;
    int lastIdx = -1;
    for(int i=0; i<mult.size(); i++) {
        int k = mult[i];
        // 더이상 등장하지 않으면 이걸 바로 뽑음
        if(nexts[k].empty()) return i;

        if(nexts[k].front() > lastNext) {
            lastNext = nexts[k].front();
            lastIdx = i;
        }
    }
    return lastIdx;
}

// 해당 전기용품이 멀티탭에 꽂혀 있는지 여부 반환
bool contains(int k) {
    return find(mult.begin(), mult.end(), k) != mult.end();
}

// 전기용품을 멀티탭에 꽂음
// 이미 꽂혀있거나 멀티탭이 다 차있지 않아 원래 있던 전기용품을 뽑지 않아도 되면 false 반환
// 멀티탭이 다 차있어서 원래 꽂혀있는것을 뽑아야 하면 true 반환
bool plug(int k) {
    // 이 등장 처리
    nexts[k].pop();

    // 이미 꽂혀있으면 아무것도 안해도 됨
    if(contains(k)) return false;
    // 멀티탭에 공간이 남아있으면 꽂기만 하면 됨
    if(mult.size() < N) {
        mult.push_back(k);
        return false;
    }

    // 뽑아야 하는 전기용품이 있는 위치
    int unplugIdx = findLastKIdx();
    // 멀티탭의 unplugIdx 번째에 꽂혀있는 전기용품을 k로 대체
    mult[unplugIdx] = k;
    return true;
}

int main() {
    cin >> N >> K;
    // 멀티탭들을 입력받으면서 마지막 등장 위치 저장
    for(int i=0; i<K; i++) {
        cin >> ks[i];
        nexts[ks[i]].push(i);
    }
    // 순서대로 하나씩 꽂아보면서 플러그를 뽑아야 하는 횟수 카운트
    int count = 0;
    for(int i=0; i<K; i++)
        count += plug(ks[i]);
    cout << count;
    return 0;
}