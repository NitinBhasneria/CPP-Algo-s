// DFS Technique
// Depth First Search                                
// Taking the input 0 to n-1 and the edges

#include<bits/stdc++.h>
using namespace std;

void print(int** edges, int n, int sv, bool* visited) {
    // sv is for tracking the vertices
    // visited is the vertices we have already seen
    cout << sv << endl;
    visited[sv] = true;
    for(int i=0;i<n;i++) {
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

void DFS(int** edges,  int n) {
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;

    for(int i=0;i<n;i++) {
        if(!visited[i]) 
            print(edges, n, i, visited);
    }

    delete[] visited;       
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
    
    DFS(edges, n);

    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
