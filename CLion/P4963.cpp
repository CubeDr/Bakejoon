//
// Created by HyunI on 2019-06-28.
//

#include <queue>

using namespace std;

struct Point {
    int x, y;
};

bool isNewIsland(int map[50][50], int w, int h, int x, int y) {
    if(!map[y][x]) return false;
    queue<Point> q;
    q.push({x, y});
    while(!q.empty()) {

    }
}

int countIslands(int map[50][50], int w, int h) {
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {

        }
    }
}

int main() {

}