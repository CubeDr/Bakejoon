//
// Created by HyunI on 2019-06-30.
//

#include <iostream>

#define DIV 10007

using namespace std;

int memR[50000][4];
void buildRectangle() {
    for(int i=0; i<4; i++) memR[1][i] = 1;

    for(int i=1; i<50000-1; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                if (j == 2 && k == 3) break;
                memR[i + 1][k] = (memR[i + 1][k] + memR[i][j]) % DIV;
            }
        }
    }
}

int rectangle(int n) {
    int sum = 0;
    for(int i=0; i<4; i++)
        sum += memR[n-1][i];
    return sum % DIV;
}

int memC[50000][4][4];
void buildCircle() {
    memC[0][0][0] = memC[0][1][0] = 0;

}

int main() {
    buildRectangle();
    cout << rectangle(10);
    return 0;
}