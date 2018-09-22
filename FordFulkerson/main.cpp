#include <iostream>

using namespace std;

int N;
int graph[100][100];
int source, sink;

int main()
{
    cin >> N;
    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    cin >> source >> sink;


    return 0;
}
