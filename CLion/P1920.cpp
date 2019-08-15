//
// Created by HyunI on 2019-07-04.
//

#include <algorithm>
#include <vector>

#include <cstdio>

using namespace std;

vector<int> inputVector() {
    int n;
    vector<int> v;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int c;
        scanf("%d", &c);
        v.push_back(c);
    }

    return v;
}

int main() {
    vector<int> n = inputVector();
    vector<int> m = inputVector();

    sort(n.begin(), n.end());
    for(int t: m) {
        bool match = binary_search(n.begin(), n.end(), t);
        printf("%d\n", match);
    }

    return 0;
}