#include<bits/stdc++.h>
using namespace std;

bool hasPath_BFS(int** edges, int n, int v1, int v2) {

    queue<int> pendingVertices;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
        visited[v1] = 1;
    pendingVertices.push(v1);
    while(!pendingVertices.empty()) {
        int current = pendingVertices.front();
        pendingVertices.pop();
        if(current == v2){
            delete[] visited;
            return true;
        }
        for(int i=0;i<n;i++){
            if(i == current) continue;
            if(edges[current][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
    return false;
}

int main() {
    int n; // number of vertices
    int e; // number of edges;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }

    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin>>v1>>v2;

    if(hasPath_BFS(edges, n, v1, v2)){
        cout<<"true";
    }
    else cout<<"false";

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
