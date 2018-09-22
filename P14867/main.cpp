#include <iostream>
#include <utility>
#include <queue>

#define NAN 999999

using namespace std;

int A, B, P, Q;
int mem[100001][4];

struct Z{
    int a, b;
};
queue <Z> que;

int& D(int a, int b)
{
    if (a == 0) return mem[b][0]; // a 가 빈 경우
    if (a == A) return mem[b][1]; // a 가 찬 경우
    if (b == 0) return mem[a][2]; // b 가 빈 경우
    if (b == B) return mem[a][3]; // b 가 찬 경우
    return mem[0][2];
}

void push(int a, int b, int d)
{
    if (D(a, b) < NAN) return;
    D(a, b) = d; que.push({a, b});
}

int main()
{
    cin >> A >> B >> P >> Q;
    for (int i=0;i<=B;i++)
        for (int j=0;j<4;j++)
            mem[i][j] = NAN;
    push(0, 0, 0);
    while (!que.empty()){
        Z q = que.front(); que.pop();
        int a = q.a, b = q.b, d = D(a, b);

        push(0, b, d+1);
        push(a, 0, d+1);
        push(A, b, d+1);
        push(a, B, d+1);

        int v = min(A-a, b);
        push(a+v, b-v, d+1);

        v = min(a, B-b);
        push(a-v, b+v, d+1);
    }
    cout << (D(P, Q) < NAN ? D(P, Q) : -1) << endl;
}
