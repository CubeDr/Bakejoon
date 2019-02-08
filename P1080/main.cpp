#include <cstdio>

int N, M;
char A[50][51];
char B[50][51];

void flipA(int x, int y) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(A[y+i][x+j] == '0') A[y+i][x+j] = '1';
            else A[y+i][x+j] = '0';
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", A[i]);
    for(int i=0; i<N; i++)
        scanf("%s", B[i]);

    int count = 0;
    for(int i=0; i<N-2; i++) {
        for(int j=0; j<M-2; j++) {
            if(A[i][j] != B[i][j]) {
                flipA(j, i);
                count++;
            }
        }
    }
    for(int i=0; i<N && count != -1; i++)
        for(int j=0; j<M && count != -1; j++)
            if(A[i][j] != B[i][j])
                count = -1;
    printf("%d", count);
    return 0;
}