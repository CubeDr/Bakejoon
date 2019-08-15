#include <iostream>
#include <stack>

using namespace std;

char num[500001];
int previous[500000];

int main() {
    int N, K;
    cin >> N >> K >> num;
    for(int i=0; i<N; i++)
        previous[i] = i-1;

    int erased = 0;
    for(int i=0; i<N && erased < K;) {
        // 나보다 앞에있는게 더 작으면 앞에있는거 삭제
        if(previous[i] != -1 && num[i] > num[previous[i]]) {
            previous[i] = previous[previous[i]];
            erased++;
        } else i++;
    }
    // 마지막은 무조건 살아있음
    int last = N-1;
    for(int i=last; erased < K; i=previous[i]) {
        last = previous[i];
        erased++;
    }

    stack<char> s;
    for(int i=last; i>=0; i=previous[i])
        s.push(num[i]);

    while(!s.empty()) cout << s.top(), s.pop();

    return 0;
}