#include <iostream>

using namespace std;

int main()
{
    int A, B, C, N;
    bool able = false;
    cin >> A >> B >> C >> N;
    for(int i=0; !able && i<=N/A; i++) {
        for(int j=0; !able && j<=(N-A*i)/B; j++) {
            int left = N - A*i - B*j;
            if(left % C == 0)
                able = true;
        }
    }
    cout << (able?1:0) << endl;
    return 0;
}
