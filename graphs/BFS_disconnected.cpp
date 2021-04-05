// BFS Adjancency Matrix
// Breadth First Search 
// Disconnected Graph
// Will use queue// DFS Technique

#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int n, int sv) {

    queue<int> pendingVertices;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
        visited[sv] = 1;
    pendingVertices.push(sv);
    while(!pendingVertices.empty()) {
        int current = pendingVertices.front();
        pendingVertices.pop();
        cout<<current<<" ";
        for(int i=0;i<n;i++){
            if(i == current) continue;
            if(edges[current][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

int main() {
    int n; // number of vertices
    int e; // number of edges;
    cin>>n>>e;
    if(n==0)
        return 0;
    if(e==0){
        for(int i=0;i<n;i++)
        	cout<<i<<" ";
        return 0;
    }
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
    

    printBFS(edges, n, 0);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
