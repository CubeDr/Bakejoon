#include <cstdio>

char str[1000001];

int count() {
    char last = 0;
    int c = 0;
    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] == last) continue;
        c++;
        last = str[i];
    }
    return c;
}

int main() {
    scanf("%s", str);
    printf("%d", count()/2);
    return 0;
}